cmake_minimum_required(VERSION 3.16)

project(QtApp5 VERSION 0.1 LANGUAGES CXX)

# Add this near the top of your CMakeLists.txt, before your target definitions
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Add QML debugging flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DQT_QML_DEBUG")

# qt_policy(set QTP0004 NEW)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT_QML_GENERATE_QMLLS_INI ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Core Network Multimedia)
# Set Qt policies
qt_policy(SET QTP0004 NEW)

# # Set the path to Felgo SDK
# set(FELGO_DIR "C:/Felgo/Felgo/mingw_64/lib/cmake") # Update this path to your Felgo installation directory
# list(APPEND CMAKE_PREFIX_PATH ${FELGO_DIR})

# # Include Felgo
# find_package(Felgo REQUIRED)


qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appQtApp5
    main.cpp
)
qt_policy(set QTP0004 NEW)

qt_add_qml_module(appQtApp5
    URI QtApp5
    VERSION 1.0
    QML_FILES
        Views/LoginView.qml
        Views/Main.qml
        Views/MainView.qml
        Views/QRScannerView.qml
        Views/DataView.qml
        Views/ReportView.qml
        Views/SettingView.qml
        Views/SupportView.qml

    SOURCES Repositories/FirebaseAuth.h Repositories/FirebaseAuth.cpp
    
    SOURCES Models/UserModel.h Models/UserModel.cpp
    
    SOURCES ViewModels/LoginViewModel.h ViewModels/LoginViewModel.cpp
    SOURCES ViewModels/MainViewModel.h ViewModels/MainViewModel.cpp
    
    RESOURCES MyResources.qrc
    
    RESOURCES Fonts/fa-solid-900.ttf
    SOURCES ViewModels/QRScannerViewModel.h ViewModels/QRScannerViewModel.cpp

)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appQtApp5 PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appQtApp5
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appQtApp5
    PRIVATE 
        Qt6::Quick
        Qt6::Core
        Qt6::Network
        Qt6::Multimedia
)

include(GNUInstallDirs)
install(TARGETS appQtApp5
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# # Configure Felgo Hot Reload
# felgohotreload_configure_executable(${CURRENT_PROJECT_NAME})

# # Packaging configuration
# include(CPack)
# set(CPACK_PACKAGE_NAME "QRScanner")
# set(CPACK_PACKAGE_VENDOR "IMAS")
# set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
# set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
# set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Your App Description")
