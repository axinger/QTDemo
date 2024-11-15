cmake_minimum_required(VERSION 3.16)

project(QTDemo VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 模块化，添加sql支持
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql Core Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql Core Network)

# 使用 Qt 自动处理的 CMake 设置
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#全局设置icon，可以是png格式
set(app_icon_resource_windows "${CMAKE_CURRENT_SOURCE_DIR}/icon.rc")
set(PROJECT_SOURCES
        ${app_icon_resource_windows}
        main.cpp
        mylogin.cpp
        mylogin.h
        myhomewindow.cpp
        myregister.cpp
        myregister.h
        myregister.ui
        mylogoutwidget.cpp
        mylogoutwidget.h
        mylogoutwidget.ui
        applogin.cpp
        applogin.h
        applogin.ui
        apphomewindow.cpp
        apphomewindow.h
        apphomewindow.ui
        main.cpp
        main.cpp
        mydbwidget.cpp
        mydbwidget.h
        mydbwidget.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QTDemo
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        teacher.h teacher.cpp
        student.h student.cpp


        res.qrc
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET QTDemo APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(QTDemo SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(QTDemo
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# 模块化，添加对sql支持
target_link_libraries(QTDemo PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Sql
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Network
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.QTDemo)
endif()
set_target_properties(QTDemo PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS QTDemo
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QTDemo)
endif()
