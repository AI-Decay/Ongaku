cmake_minimum_required(VERSION 3.14)

project(ONGAKU LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(ANDROID)
    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)

set(PROJECT_SOURCES
        src/main/main.cpp
        qml.qrc
)
if(WIN32)
#set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/ONGAKU_windows.rc")
endif()

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ONGAKU
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(ONGAKU SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(ONGAKU
          ${PROJECT_SOURCES}    
          #${APP_ICON_RESOURCE_WINDOWS}
        )
    endif()
endif()

target_compile_definitions(ONGAKU
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(ONGAKU
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)
