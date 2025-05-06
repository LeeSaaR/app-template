cmake_minimum_required(VERSION 3.5)

include_directories(${CMAKE_CURRENT_LIST_DIR})
set(APP_SOURCES ${APP_SOURCES}
    ${CMAKE_CURRENT_LIST_DIR}/msgbox.h
    ${CMAKE_CURRENT_LIST_DIR}/msgboxdata.h ${CMAKE_CURRENT_LIST_DIR}/msgboxdata.cpp
)
