cmake_minimum_required(VERSION 3.5)

include_directories(${CMAKE_CURRENT_LIST_DIR})
set(APP_SOURCES ${APP_SOURCES}
    ${CMAKE_CURRENT_LIST_DIR}/menupage.h
    ${CMAKE_CURRENT_LIST_DIR}/menufactory.h ${CMAKE_CURRENT_LIST_DIR}/menufactory.cpp
    ${CMAKE_CURRENT_LIST_DIR}/appmenubar.h ${CMAKE_CURRENT_LIST_DIR}/appmenubar.cpp
)
