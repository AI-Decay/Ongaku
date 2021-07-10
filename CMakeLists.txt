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

find_package(QT NAMES Qt5 COMPONENTS Core Quick Multimedia REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick Multimedia REQUIRED)


set(PROJECT_SOURCES
        src/core/base/player/player.cpp
        src/core/base/player/player.h
        src/core/base/song/song.h
        src/core/base/song/metadata.h
        src/media/audio_player/audio_player.cpp
        src/media/audio_player/audio_player.h
        src/song_queue/song_queue.cpp
        src/song_queue/song_queue.h
        src/utils/type_info_name/type_info_name.h
        src/song_list_model/song_list_model.cpp
        src/song_list_model/song_list_model.h
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

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

target_compile_definitions(ONGAKU
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(ONGAKU
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Multimedia)
