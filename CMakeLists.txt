cmake_minimum_required(VERSION 3.20)

project(MYMUDUO)
#动态库的路径,根目录的lib文件夹下
set(LIBRARY_OUTPUT_DIRECTORY ￥{PROJECT_SOURCE_DIR}/lib)
#设置调试信息
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")

aux_source_directory(. SRC_LIST)

add_library(mymuduo SHARED ${SRC_LIST})