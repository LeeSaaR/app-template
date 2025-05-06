cmake_minimum_required(VERSION 3.5)

include_directories(${CMAKE_CURRENT_LIST_DIR})
set(APP_SOURCES ${APP_SOURCES}
    ${CMAKE_CURRENT_LIST_DIR}/pdfviewer.h        
    ${CMAKE_CURRENT_LIST_DIR}/pdfviewer.cpp

    ${CMAKE_CURRENT_LIST_DIR}/pdfviewerwidget.h  
    ${CMAKE_CURRENT_LIST_DIR}/pdfviewerwidget.cpp  
    ${CMAKE_CURRENT_LIST_DIR}/pdfviewerwidget.ui

    ${CMAKE_CURRENT_LIST_DIR}/dialogpdfviewer.h 
    ${CMAKE_CURRENT_LIST_DIR}/dialogpdfviewer.cpp  
    ${CMAKE_CURRENT_LIST_DIR}/dialogpdfviewer.ui

    ${CMAKE_CURRENT_LIST_DIR}/dialogpdfpreview.h 
    ${CMAKE_CURRENT_LIST_DIR}/dialogpdfpreview.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/dialogpdfpreview.ui

    ${CMAKE_CURRENT_LIST_DIR}/wgtpdfpreviewletteroption.h 
    ${CMAKE_CURRENT_LIST_DIR}/wgtpdfpreviewletteroption.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/wgtpdfpreviewletteroption.ui

    ${CMAKE_CURRENT_LIST_DIR}/wgtpdfpreviewfileselect.h
    ${CMAKE_CURRENT_LIST_DIR}/wgtpdfpreviewfileselect.cpp   
    ${CMAKE_CURRENT_LIST_DIR}/wgtpdfpreviewfileselect.ui
)
