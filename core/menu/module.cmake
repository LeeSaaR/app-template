cmake_minimum_required(VERSION 3.5)

include_directories(${CMAKE_CURRENT_LIST_DIR})
set(CORE_SOURCES ${CORE_SOURCES}
    # ${CMAKE_CURRENT_LIST_DIR}/appmenu.h ${CMAKE_CURRENT_LIST_DIR}/appmenu.cpp
    ${CMAKE_CURRENT_LIST_DIR}/menubutton.h     ${CMAKE_CURRENT_LIST_DIR}/menubutton.cpp
    ${CMAKE_CURRENT_LIST_DIR}/menubuttonprop.h ${CMAKE_CURRENT_LIST_DIR}/menubuttonprop.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgetmenubar.h  ${CMAKE_CURRENT_LIST_DIR}/widgetmenubar.cpp  ${CMAKE_CURRENT_LIST_DIR}/widgetmenubar.ui
    ${CMAKE_CURRENT_LIST_DIR}/widgetmenupage.h ${CMAKE_CURRENT_LIST_DIR}/widgetmenupage.cpp ${CMAKE_CURRENT_LIST_DIR}/widgetmenupage.ui
)
