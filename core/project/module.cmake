cmake_minimum_required(VERSION 3.5)

include_directories(${CMAKE_CURRENT_LIST_DIR})
set(APP_SOURCES ${APP_SOURCES}
    ${CMAKE_CURRENT_LIST_DIR}/projectfiledata.h   ${CMAKE_CURRENT_LIST_DIR}/projectfiledata.cpp
    ${CMAKE_CURRENT_LIST_DIR}/projecthandler.h    ${CMAKE_CURRENT_LIST_DIR}/projecthandler.cpp
    ${CMAKE_CURRENT_LIST_DIR}/wgtnewproject.h     ${CMAKE_CURRENT_LIST_DIR}/wgtnewproject.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgetprojectlist.h ${CMAKE_CURRENT_LIST_DIR}/widgetprojectlist.cpp ${CMAKE_CURRENT_LIST_DIR}/widgetprojectlist.ui
    ${CMAKE_CURRENT_LIST_DIR}/widgetprojectnew.h  ${CMAKE_CURRENT_LIST_DIR}/widgetprojectnew.cpp  ${CMAKE_CURRENT_LIST_DIR}/widgetprojectnew.ui
)
