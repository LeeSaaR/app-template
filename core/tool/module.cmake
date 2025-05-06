cmake_minimum_required(VERSION 3.5)

include_directories(${CMAKE_CURRENT_LIST_DIR})
set(CORE_SOURCES ${CORE_SOURCES}
    ${CMAKE_CURRENT_LIST_DIR}/convertdata.h ${CMAKE_CURRENT_LIST_DIR}/convertdata.cpp
    ${CMAKE_CURRENT_LIST_DIR}/apptool.h ${CMAKE_CURRENT_LIST_DIR}/apptool.cpp
    ${CMAKE_CURRENT_LIST_DIR}/billnumber.h ${CMAKE_CURRENT_LIST_DIR}/billnumber.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgetprop.h ${CMAKE_CURRENT_LIST_DIR}/widgetprop.cpp
    ${CMAKE_CURRENT_LIST_DIR}/prop.h ${CMAKE_CURRENT_LIST_DIR}/prop.cpp
    ${CMAKE_CURRENT_LIST_DIR}/info.h ${CMAKE_CURRENT_LIST_DIR}/info.cpp

)
