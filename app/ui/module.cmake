cmake_minimum_required(VERSION 3.5)

include_directories(${CMAKE_CURRENT_LIST_DIR})
set(APP_SOURCES ${APP_SOURCES}
    ${CMAKE_CURRENT_LIST_DIR}/propui.h   ${CMAKE_CURRENT_LIST_DIR}/propui.cpp
    ${CMAKE_CURRENT_LIST_DIR}/appimage.h ${CMAKE_CURRENT_LIST_DIR}/appimage.cpp
    ${CMAKE_CURRENT_LIST_DIR}/propwgt.h  ${CMAKE_CURRENT_LIST_DIR}/propwgt.cpp
    ${CMAKE_CURRENT_LIST_DIR}/apptext.h  ${CMAKE_CURRENT_LIST_DIR}/apptext.cpp
    ${CMAKE_CURRENT_LIST_DIR}/appconnector.h ${CMAKE_CURRENT_LIST_DIR}/appconnector.cpp
)
