# 指定最小Cmake的版本要求
cmake_minimum_required(VERSION 3.9)
# 设置项目名称
project(CMAKE_VARIABLES)

# 本地变量
set(LOCAL_VAR "changes value")
set(LOCAL_LIST "value1" "value2")
message("LOCAL_VAR is ${LOCAL_VAR}, LOCAL_LIST is ${LOCAL_LIST}")

# 缓存变量
set(CACHE_VAR_BOOL OFF CACHE BOOL "this is a bool cache variable")
set(CACHE_VAR_STRING "cache value" CACHE STRING "this is a string variable")
message("CACHE_VAR_BOOL is ${CACHE_VAR_BOOL}, CACHE_VAR_STRING is ${CACHE_VAR_STRING}")

# 环境变量
message("My PC shell is $ENV{SHELL}")