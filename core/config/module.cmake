cmake_minimum_required(VERSION 3.5)

include_directories(${CMAKE_CURRENT_LIST_DIR})
set(CORE_SOURCES ${CORE_SOURCES}
    ${CMAKE_CURRENT_LIST_DIR}/appconfiguration.h       ${CMAKE_CURRENT_LIST_DIR}/appconfiguration.cpp
    ${CMAKE_CURRENT_LIST_DIR}/configdata.h             ${CMAKE_CURRENT_LIST_DIR}/configdata.cpp
    ${CMAKE_CURRENT_LIST_DIR}/configsectionsub.h       ${CMAKE_CURRENT_LIST_DIR}/configsectionsub.cpp
    ${CMAKE_CURRENT_LIST_DIR}/configsectiontop.h       ${CMAKE_CURRENT_LIST_DIR}/configsectiontop.cpp
    ${CMAKE_CURRENT_LIST_DIR}/configdatalist.h         ${CMAKE_CURRENT_LIST_DIR}/configdatalist.cpp
    ${CMAKE_CURRENT_LIST_DIR}/propitemscontroller.h    ${CMAKE_CURRENT_LIST_DIR}/propitemscontroller.cpp
    ${CMAKE_CURRENT_LIST_DIR}/widgetpropdir.h          ${CMAKE_CURRENT_LIST_DIR}/widgetpropdir.cpp          ${CMAKE_CURRENT_LIST_DIR}/widgetpropdir.ui
    ${CMAKE_CURRENT_LIST_DIR}/widgetpropdropdown.h     ${CMAKE_CURRENT_LIST_DIR}/widgetpropdropdown.cpp     ${CMAKE_CURRENT_LIST_DIR}/widgetpropdropdown.ui
    ${CMAKE_CURRENT_LIST_DIR}/widgetpropdropdownfile.h ${CMAKE_CURRENT_LIST_DIR}/widgetpropdropdownfile.cpp ${CMAKE_CURRENT_LIST_DIR}/widgetpropdropdownfile.ui
    ${CMAKE_CURRENT_LIST_DIR}/widgetpropfile.h         ${CMAKE_CURRENT_LIST_DIR}/widgetpropfile.cpp         ${CMAKE_CURRENT_LIST_DIR}/widgetpropfile.ui
    ${CMAKE_CURRENT_LIST_DIR}/widgetproptext.h         ${CMAKE_CURRENT_LIST_DIR}/widgetproptext.cpp         ${CMAKE_CURRENT_LIST_DIR}/widgetproptext.ui
    ${CMAKE_CURRENT_LIST_DIR}/widgetpropsection.h      ${CMAKE_CURRENT_LIST_DIR}/widgetpropsection.cpp      ${CMAKE_CURRENT_LIST_DIR}/widgetpropsection.ui
    ${CMAKE_CURRENT_LIST_DIR}/propoptions.h            ${CMAKE_CURRENT_LIST_DIR}/propoptions.cpp
)
