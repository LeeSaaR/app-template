cmake_minimum_required(VERSION 3.5)

include_directories(${CMAKE_CURRENT_LIST_DIR})
# include_directories(${CMAKE_CURRENT_LIST_DIR}/pdf_letter/letter_data)
# include_directories(${CMAKE_CURRENT_LIST_DIR}/pdf_viewer)
# include_directories(${CMAKE_CURRENT_LIST_DIR}/pdf_writer)

include(${CMAKE_CURRENT_LIST_DIR}/letter_editor/module.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/pdf_letter/module.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/pdf_viewer/module.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/pdf_writer/module.cmake)

set(APP_SOURCES ${APP_SOURCES}


)
