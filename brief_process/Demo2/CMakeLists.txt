# 指定最小Cmake的版本要求
cmake_minimum_required(VERSION 3.9)
# 设置项目名称
project(Demo2 C CXX)
# 启用 C++11 或更高标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 查找Demo2/目录下的所有源文件，然后将结果存进DIR_SRCS。
aux_source_directory(. DIR_SRCS)
# 使用Demo2/目录下的所有源文件构建一个名为Demo的可执行文件
add_executable(Demo ${DIR_SRCS})