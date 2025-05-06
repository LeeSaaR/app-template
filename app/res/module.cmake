cmake_minimum_required(VERSION 3.5)

include_directories(${CMAKE_CURRENT_LIST_DIR})
set(CORE_SOURCES ${CORE_SOURCES}
    ${CMAKE_CURRENT_LIST_DIR}/app.qrc
    ${CMAKE_CURRENT_LIST_DIR}/app.rc
)
