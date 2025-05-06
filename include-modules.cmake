cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_LIST_DIR}/core/module.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/core/config/module.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/core/database/dbio.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/core/dialog/module.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/core/enum/module.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/core/font/module.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/core/io/module.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/core/menu/module.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/core/messagebox/module.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/core/project/module.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/core/res/module.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/core/theme/module.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/core/tool/module.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/core/widget/module.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/app/module.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/app/dialog/module.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/app/menu/module.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/app/pdf/module.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/app/project/module.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/app/res/module.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/app/ui/module.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/app/widget/module.cmake)

# ADD OTHER STUFF HERE

# add ${APPLICATION_SOURCES} to PROJECT_SOURCES in top level CMakeLists.txt
set(APPLICATION_SOURCES ${CORE_SOURCES} ${APP_SOURCES} ${DBIO})
