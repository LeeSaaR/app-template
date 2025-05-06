cmake_minimum_required(VERSION 3.5)

include_directories(${CMAKE_CURRENT_LIST_DIR})
set(APP_SOURCES ${APP_SOURCES}
    ${CMAKE_CURRENT_LIST_DIR}/wgttextline.h ${CMAKE_CURRENT_LIST_DIR}/wgttextline.cpp
)
