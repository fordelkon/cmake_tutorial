# 查找StrUtils目录下的所有源文件，然后将结果存进DIR_SRCS。
aux_source_directory(. DIR_SRCS)

# 指定生成Palindrome链接库
add_library(Palindrome ${DIR_SRCS})

# 链接AroundCenter到Palindrome,被引用是自动引用
target_link_libraries(Palindrome PUBLIC AroundCenter)

# 指定此链接库的包含目录
target_include_directories(Palindrome INTERFACE
    ${CMAKE_SOURCE_DIR}          # 添加这行，使得可以从项目根目录包含文件Palindrome
)