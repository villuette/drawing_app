cmake_minimum_required(VERSION 3.5)

project(qt_drawing_app VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        colorpickerbutton.h
        colorpickerbutton.cpp
        myshape.h myshape.cpp
        shapeselector.h shapeselector.cpp
        mycircle.h mycircle.cpp
        myrectangle.h myrectangle.cpp
        shapesstorage.h shapesstorage.cpp
        drawingarea.h drawingarea.cpp
        sizepicker.h sizepicker.cpp
        selectionarea.h selectionarea.cpp
        myshapegroup.h myshapegroup.cpp
        shapefactory.h shapefactory.cpp
        myrectanglefactory.h myrectanglefactory.cpp
        mycirclefactory.h mycirclefactory.cpp
        shapesfilemanager.h shapesfilemanager.cpp
        iobservable.h iobservable.cpp
        iobserver.h iobserver.cpp
        shapestreecontroller.h shapestreecontroller.cpp
        mytreeitem.h mytreeitem.cpp
        mystickyshape.h mystickyshape.cpp
        mystickyfactory.h mystickyfactory.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(qt_drawing_app
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET qt_drawing_app APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(qt_drawing_app SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(qt_drawing_app
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(qt_drawing_app PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(qt_drawing_app PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS qt_drawing_app
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(qt_drawing_app)
endif()
