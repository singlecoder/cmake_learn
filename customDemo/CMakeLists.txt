# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (customDemo)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 是否使用自己的 test 库
option (USE_MYTEST 
		"Use provided test implementation" ON)

# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file (
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_BINARY_DIR}/config.h"
)

# 是否加入 test 库
if (USE_MYTEST)
	include_directories ("${PROJECT_SOURCE_DIR}/test")
	add_subdirectory (test)
	set (EXTRA_LIBS ${EXTRA_LIBS} test)
endif (USE_MYTEST)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory (. DIR_SOURCE)

# 指定生成目标
add_executable (customDemo ${DIR_SOURCE})

# 添加链接库
target_link_libraries (customDemo ${EXTRA_LIBS})

