cmake_minimum_required(VERSION 3.16)
project(QtApp5 VERSION 0.1 LANGUAGES CXX)

# Thiết lập vcpkg
set(CMAKE_TOOLCHAIN_FILE "C:/Users/minke/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")

# Set OpenCV directories explicitly
set(OpenCV_DIR "C:/Users/minke/vcpkg/installed/x64-windows/share/opencv4")
list(APPEND CMAKE_PREFIX_PATH
    "C:/Users/minke/vcpkg/installed/x64-windows"
    "C:/Users/minke/vcpkg/installed/x64-windows/share/opencv4"
)


# Các thiết lập Qt hiện có
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DQT_QML_DEBUG")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QT_QML_GENERATE_QMLLS_INI ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Core Network Multimedia MultimediaWidgets)
find_package(OpenCV REQUIRED)

# Set Qt policies
qt_policy(SET QTP0004 NEW)
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
    SOURCES Services/CameraService.h Services/CameraService.cpp
    RESOURCES Images/video-slash-solid.svg
    SOURCES Services/QRCodeService.h Services/QRCodeService.cpp
)

set_target_properties(appQtApp5 PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Cập nhật target_link_libraries để thêm OpenCV
target_link_libraries(appQtApp5
    PRIVATE
        Qt6::Quick
        Qt6::Core
        Qt6::Network
        Qt6::Multimedia
        Qt6::MultimediaWidgets
        ${OpenCV_LIBS}  # Thêm OpenCV libraries
)

# Thêm OpenCV include directories
target_include_directories(appQtApp5
    PRIVATE
    ${OpenCV_INCLUDE_DIRS}
)

include(GNUInstallDirs)
install(TARGETS appQtApp5
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
