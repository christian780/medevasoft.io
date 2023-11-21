cmake_minimum_required(VERSION 3.5)

project(projct VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CONFIGURATION_TYPES "Release;RelWithDebInfo" CACHE STRING "" FORCE)



set(SOURCES_FILES...)


find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS  Widgets  Sql REQUIRED)




#set(RESOURCE_FILES logo.png)

set(PROJECT_SOURCES
      mainwindow.ui
      mainwindow.h
      main.cpp
    table.cpp
    table.h
    mainwindow.cpp
     secwin.ui
     table.ui
     secwin.cpp
     secwin.h
      dialog.cpp
      dialog.ui
      dialog.h
      delete.h
      delete.cpp
      delete.ui
      admin.cpp
      admin.h
      admin.ui
      admin2.cpp
      admin2.h
      admin2.ui
      load.cpp
      load.h
      load.ui
      Aboutus.h
      Aboutus.cpp
      Aboutus.ui
      admupdate.h
      admupdate.cpp
      admupdate.ui
      admdel.cpp
      admdel.ui
      admdel.h
      globals.h
      db.h
      Record.h
      Record.cpp
      Record.ui

)




qt_add_resources(PROJECT_SOURCES  image/srcc.qrc)




if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(projct
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET projct APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(projct SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(projct
            ${PROJECT_SOURCES}
            main.cpp
        )
    endif()
endif()

target_link_libraries(projct  PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(projct PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                       Qt${QT_VERSION_MAJOR}::Sql)


set_target_properties(projct PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(projct)
endif()
