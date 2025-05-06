cmake_minimum_required(VERSION 3.5)

include_directories(${CMAKE_CURRENT_LIST_DIR})
set(APP_SOURCES ${APP_SOURCES}
    ${CMAKE_CURRENT_LIST_DIR}/letterdata.h
    ${CMAKE_CURRENT_LIST_DIR}/contactdata.h
    ${CMAKE_CURRENT_LIST_DIR}/commonletterdata.h
    ${CMAKE_CURRENT_LIST_DIR}/letteroptions.h
    ${CMAKE_CURRENT_LIST_DIR}/receiveroptions.h
    ${CMAKE_CURRENT_LIST_DIR}/receiverdata.h
    ${CMAKE_CURRENT_LIST_DIR}/senderdata.h
    ${CMAKE_CURRENT_LIST_DIR}/pdfdata.h 
    ${CMAKE_CURRENT_LIST_DIR}/pdfdata.cpp
    ${CMAKE_CURRENT_LIST_DIR}/pdfletterdataloader.h 
    ${CMAKE_CURRENT_LIST_DIR}/pdfletterdataloader.cpp
)
