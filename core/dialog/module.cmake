cmake_minimum_required(VERSION 3.5)

include_directories(${CMAKE_CURRENT_LIST_DIR})
set(CORE_SOURCES ${CORE_SOURCES}
    ${CMAKE_CURRENT_LIST_DIR}/coredialog.h                ${CMAKE_CURRENT_LIST_DIR}/coredialog.cpp
    #${CMAKE_CURRENT_LIST_DIR}/appfiledialog.h            ${CMAKE_CURRENT_LIST_DIR}/appfiledialog.cpp
    ${CMAKE_CURRENT_LIST_DIR}/dialogabout.h              ${CMAKE_CURRENT_LIST_DIR}/dialogabout.cpp              ${CMAKE_CURRENT_LIST_DIR}/dialogabout.ui
    ${CMAKE_CURRENT_LIST_DIR}/dialogpreferences.h        ${CMAKE_CURRENT_LIST_DIR}/dialogpreferences.cpp      ${CMAKE_CURRENT_LIST_DIR}/dialogpreferences.ui
    ${CMAKE_CURRENT_LIST_DIR}/dialogprojectsettings.h    ${CMAKE_CURRENT_LIST_DIR}/dialogprojectsettings.cpp    ${CMAKE_CURRENT_LIST_DIR}/dialogprojectsettings.ui
    ${CMAKE_CURRENT_LIST_DIR}/dialogstartscreen.h        ${CMAKE_CURRENT_LIST_DIR}/dialogstartscreen.cpp        ${CMAKE_CURRENT_LIST_DIR}/dialogstartscreen.ui
    ${CMAKE_CURRENT_LIST_DIR}/dialognewproject.h         ${CMAKE_CURRENT_LIST_DIR}/dialognewproject.cpp         ${CMAKE_CURRENT_LIST_DIR}/dialognewproject.ui
    ${CMAKE_CURRENT_LIST_DIR}/dialogopenproject.h        ${CMAKE_CURRENT_LIST_DIR}/dialogopenproject.cpp        ${CMAKE_CURRENT_LIST_DIR}/dialogopenproject.ui
)
