# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (multiDirs)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory (. DIR_SOURCE)

# 添加 test 子目录
add_subdirectory (test)

# 指定生成目标
add_executable (multiDirs ${DIR_SOURCE})

# 添加链接库
target_link_libraries (multiDirs test)

