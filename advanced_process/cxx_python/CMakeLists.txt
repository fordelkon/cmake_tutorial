cmake_minimum_required(VERSION 3.9)
project(CPy VERSION 0.1 DESCRIPTION "Little C to Python Program" LANGUAGES CXX)

# 自定义我想要的包的路径：位于Conda环境下的Python可执行文件
set(Python_EXECUTABLE "$ENV{CONDA_PYTHON_EXE}")

# 查找Python解释器以及调试工具组件
find_package(Python REQUIRED COMPONENTS Interpreter Development)

if(Python_FOUND)
    message("Python Found at ${Python_INCLUDE_DIRS}")
    
    # 从Conda环境下的Python查找pybind11路径
    execute_process(
        COMMAND "${Python_EXECUTABLE}" -m pybind11 --cmakedir 
        RESULT_VARIABLE __pybind_exit_code 
        OUTPUT_VARIABLE __pybind_path 
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    if(__pybind_exit_code EQUAL 0)
        set(pybind11_DIR ${__pybind_path})
        find_package(pybind11 REQUIRED)
        
        message("pybind11 Found at ${pybind11_INCLUDE_DIRS}")

        # 创建编译选项接口库
        add_library(compiler_flags INTERFACE)
        target_compile_features(compiler_flags INTERFACE cxx_std_11)

        # 添加优化选项
        if(NOT MSVC)
            target_compile_options(compiler_flags INTERFACE 
                -O2 
                -march=native
            )
        else()
            target_compile_options(compiler_flags INTERFACE 
                /O2
                /arch:AVX2  # 对应于 -march=native
            )
        endif()

        ##################
        #######CPU########
        ##################
        add_library(ndarray_backend_cpu MODULE src/ndarray_backend_cpu.cc)

        target_include_directories(ndarray_backend_cpu 
            PRIVATE 
                ${Python_INCLUDE_DIRS}
                ${pybind11_INCLUDE_DIRS} 
        )

        target_link_libraries(ndarray_backend_cpu 
            PUBLIC 
                ${pybind11_LIBRARIES}
                compiler_flags  # 链接编译选项接口库
        )

        pybind11_extension(ndarray_backend_cpu)
        pybind11_strip(ndarray_backend_cpu)

        # 输出编译文件
        set_target_properties(
            ndarray_backend_cpu
            PROPERTIES 
                LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/needle/backend_ndarray
                CXX_VISIBILITY_PRESET "hidden"
        )

        if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
            set_property(TARGET ndarray_backend_cpu PROPERTY LINK_OPTIONS -undefined dynamic_lookup)
        endif()
    else()
        message(FATAL_ERROR "Could not find pybind11 in the Python environment!!!")
    endif()
else()
    message(FATAL_ERROR "Could not find Python from Miniconda!!!")
endif()