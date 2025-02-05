// Main.qml
import QtQuick
import QtQuick.Controls
// import QtQuick.Layouts

ApplicationWindow {
    id: window
    width: 1360
    height: 768
    color: "black"
    visible: true
    title: qsTr("QRScanner")

    property bool isLoginView: userModel.idToken === ""

    flags: {
        if(isLoginView)
        {
            return Qt.Window | Qt.CustomizeWindowHint | Qt.WindowTitleHint | Qt.WindowMinimizeButtonHint | Qt.WindowCloseButtonHint
        }
        else 
        {
            return Qt.Window
        }
    }

    Loader {
        id: mainLoader
        anchors.fill: parent

        // Kiểm tra nếu đã có token thì load MainView, không thì load LoginView
        source: userModel.idToken !== "" ? "MainView.qml" : "LoginView.qml"

        Connections {
            target: mainLoader.item
            function onLoginSuccess() {
                window.isLoginView = false
                mainLoader.source = "MainView.qml"
                window.flags = Qt.Window
            }
        }
    }

    // Chỉ sử dụng Connections với userModel cho logout
    Connections {
        target: userModel
        function onIdTokenChanged() {
            if (userModel.idToken === "" && mainLoader.source.toString().includes("MainView.qml")) {
                mainLoader.source = "LoginView.qml"
                window.isLoginView = true
            }
        }
    }
}
