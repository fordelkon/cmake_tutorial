# 指定最小Cmake的版本要求
cmake_minimum_required(VERSION 3.9)
# 设置项目名称
project(THIRD_PACKAGE)

set(FLAG OFF)

if(FLAG)
    find_package(Python REQUIRED COMPONENTS Interpreter Development)

    if(Python_FOUND)
        message("Package include directory is ${Python_INCLUDE_DIRS}")
        message("Package library is ${Python_LIBRARIES}")
        message("Package version is ${Python_VERSION}")
        message("Package executable file path is ${Python_EXECUTABLE}")    
    endif()
else()
    set(Python_EXECUTABLE "$ENV{CONDA_PYTHON_EXE}")
    find_package(Python REQUIRED COMPONENTS Interpreter Development)

    if(Python_FOUND)
        message("Package include directory is ${Python_INCLUDE_DIRS}")
        message("Package library is ${Python_LIBRARIES}")
        message("Package version is ${Python_VERSION}")
        message("Package executable file path is ${Python_EXECUTABLE}")    
    endif()
endif()