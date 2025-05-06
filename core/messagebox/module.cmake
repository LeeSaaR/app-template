cmake_minimum_required(VERSION 3.5)

include_directories(${CMAKE_CURRENT_LIST_DIR})
set(CORE_SOURCES ${CORE_SOURCES}
    ${CMAKE_CURRENT_LIST_DIR}/appmsgbox.h ${CMAKE_CURRENT_LIST_DIR}/appmsgbox.cpp ${CMAKE_CURRENT_LIST_DIR}/appmsgbox.ui
    ${CMAKE_CURRENT_LIST_DIR}/msgboxuibutton.h ${CMAKE_CURRENT_LIST_DIR}/msgboxuibutton.cpp
    ${CMAKE_CURRENT_LIST_DIR}/msgboxmessage.h
    ${CMAKE_CURRENT_LIST_DIR}/msgboxbutton.h
)
