cmake_minimum_required(VERSION 2.8)

PROJECT(rtt_binary)
SET(SRC src/gz_file_reader.cpp
    src/mmap_file_reader.cpp
    src/riverdb_reader.cpp
    src/riverdb_writer.cpp
    src/time_riverdb.cpp
    src/data_index.cpp
    src/row_reader.cpp
    src/kv_riverdb.cpp
    src/util.cpp)

SET(CMAKE_CXX_FLAGS "-std=c++11 -g")

ADD_LIBRARY(riverdb STATIC ${SRC})
SET_TARGET_PROPERTIES(riverdb PROPERTIES OUTPUT_NAME "riverdb")

target_link_libraries(riverdb -lz)
