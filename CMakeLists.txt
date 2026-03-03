# Main CMakeLists file
cmake_minimum_required(VERSION 3.16)

project(AWC_GUI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

add_subdirectory(core)

qt_add_executable(appAWC_GUI
    main.cpp
)

qt_add_qml_module(appAWC_GUI
    URI AWC_GUI
    QML_FILES
        Main.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appAWC_GUI PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appAWC_GUI
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appAWC_GUI PRIVATE Qt6::Quick core)

include(GNUInstallDirs)
install(TARGETS appAWC_GUI
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
