cmake_minimum_required(VERSION 3.5)

include_directories(${CMAKE_CURRENT_LIST_DIR})
set(APP_SOURCES ${APP_SOURCES}
    ${CMAKE_CURRENT_LIST_DIR}/projectdata.h       ${CMAKE_CURRENT_LIST_DIR}/projectdata.cpp
    ${CMAKE_CURRENT_LIST_DIR}/projectsjsonio.h    ${CMAKE_CURRENT_LIST_DIR}/projectsjsonio.cpp
    ${CMAKE_CURRENT_LIST_DIR}/projectcreator.h    ${CMAKE_CURRENT_LIST_DIR}/projectcreator.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgetprojectname.h ${CMAKE_CURRENT_LIST_DIR}/widgetprojectname.cpp ${CMAKE_CURRENT_LIST_DIR}/widgetprojectname.ui
)
