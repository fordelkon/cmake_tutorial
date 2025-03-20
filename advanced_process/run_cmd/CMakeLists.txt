# 指定最小Cmake的版本要求
cmake_minimum_required(VERSION 3.9)
# 设置项目名称
project(THIRD_PACKAGE)

execute_process(
    COMMAND ls
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE ls_output
)
message("Directory ${CMAKE_SOURCE_DIR} listing: ${ls_output}")