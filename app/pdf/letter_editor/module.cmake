cmake_minimum_required(VERSION 3.5)

include_directories(${CMAKE_CURRENT_LIST_DIR})
set(APP_SOURCES ${APP_SOURCES}
    # DialogLetterEditor
    ${CMAKE_CURRENT_LIST_DIR}/dialoglettereditor.h
    ${CMAKE_CURRENT_LIST_DIR}/dialoglettereditor.cpp
    ${CMAKE_CURRENT_LIST_DIR}/dialoglettereditor.ui

    # WidgetLetterEditor
    ${CMAKE_CURRENT_LIST_DIR}/widgetlettereditor.h
    ${CMAKE_CURRENT_LIST_DIR}/widgetlettereditor.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgetlettereditor.ui
)
