cmake_minimum_required(VERSION 3.5)

include_directories(${CMAKE_CURRENT_LIST_DIR})
include( ${CMAKE_CURRENT_LIST_DIR}/letter_data/module.cmake )
set(APP_SOURCES ${APP_SOURCES}
    ${CMAKE_CURRENT_LIST_DIR}/pdfletterinitializer.h
    ${CMAKE_CURRENT_LIST_DIR}/pdfletterinitializer.cpp

    ${CMAKE_CURRENT_LIST_DIR}/pdfletterbase.h
    ${CMAKE_CURRENT_LIST_DIR}/pdfletterbase.cpp

    ${CMAKE_CURRENT_LIST_DIR}/pdfletterpreview.h
    ${CMAKE_CURRENT_LIST_DIR}/pdfletterpreview.cpp

    ${CMAKE_CURRENT_LIST_DIR}/pdfletter.h
    ${CMAKE_CURRENT_LIST_DIR}/pdfletter.cpp

    ${CMAKE_CURRENT_LIST_DIR}/pdfbill.h
    ${CMAKE_CURRENT_LIST_DIR}/pdfbill.cpp
)
