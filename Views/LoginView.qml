import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Basic
import "../Themes/ThemeManager.js" as Theme

Item {
    id: loginView
    signal loginSuccess
    width: 1360
    height: 768
    visible: true

    property bool showPassword: false

    FontLoader {
        id: fontAW
        source: "../Fonts/fa-solid-900.ttf"
    }

    Rectangle {
        anchors.fill: parent
        color: Theme.current.panelBackgroundColor_Normal

        Rectangle {
            id: mainContent
            width: 500
            height: parent.height * 0.8
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            radius: 8
            color: Theme.current.panelBackgroundColor_Actived
            border.color: Theme.current.panelBorderColor_Actived
            border.width: 1

            ColumnLayout {
                id: columnLayoutMain
                anchors.fill: parent
                anchors.margins: 20
                spacing: 15

                Item {
                    Layout.fillHeight: true
                    Layout.preferredHeight: 20
                }

                Text {
                    id: textSignIn
                    text: "Sign in"
                    font {
                        family: "Montserrat"
                        pixelSize: 32
                        bold: true
                    }
                    color: Theme.current.textColor_Normal
                    Layout.alignment: Qt.AlignHCenter
                }

                Text {
                    id: textWelcome
                    text: "Welcome to QRScanner!"
                    font {
                        family: "Montserrat"
                        pixelSize: 16
                    }
                    color: Theme.current.textColor_Normal
                    Layout.alignment: Qt.AlignHCenter
                }

                // Email Field
                Rectangle {
                    Layout.preferredHeight: 45
                    Layout.preferredWidth: parent.width * 0.8
                    Layout.alignment: Qt.AlignHCenter
                    Layout.topMargin: 30
                    radius: 8
                    color: Theme.current.textFieldBackgroundColor_Actived
                    border.color: Theme.current.textFieldBorderColor_Actived
                    border.width: 1

                    RowLayout {
                        anchors.fill: parent
                        anchors.margins: 10
                        spacing: 10

                        Text {
                            text: "\u0040"
                            font {
                                family: fontAW.name
                                pixelSize: 18
                            }
                            color: Theme.current.iconColor_Actived
                        }

                        TextField {
                            id: textFieldEmail
                            placeholderText: "Email"
                            activeFocusOnTab: true
                            selectByMouse: true
                            focus: true
                            KeyNavigation.tab: textFieldPassword
                            font {
                                family: "Montserrat"
                                pixelSize: 14
                            }
                            color: Theme.current.textColor_Actived
                            Layout.fillWidth: true
                            background: Rectangle {
                                color: "transparent"
                            }
                            text: loginViewModel.email
                            onTextChanged: loginViewModel.email = text

                            onActiveFocusChanged: {
                                if (activeFocus) {

                                }
                            }
                            Component.onDestruction: {
                                clear()
                            }
                        }
                    }
                }

                // Password Field
                Rectangle {
                    Layout.preferredHeight: 45
                    Layout.preferredWidth: parent.width * 0.8
                    Layout.alignment: Qt.AlignHCenter
                    Layout.topMargin: 10
                    radius: 8
                    color: Theme.current.textFieldBackgroundColor_Actived
                    border.color: Theme.current.textFieldBorderColor_Actived
                    border.width: 1

                    RowLayout {
                        anchors.fill: parent
                        anchors.margins: 10
                        spacing: 10

                        Text {
                            text: "\uf084"
                            font {
                                family: fontAW.name
                                pixelSize: 18
                            }
                            color: Theme.current.iconColor_Actived
                        }

                        TextField {
                            id: textFieldPassword
                            activeFocusOnTab: true
                            selectByMouse: true
                            KeyNavigation.tab: textFieldEmail
                            placeholderText: "Password"
                            echoMode: loginView.showPassword ? TextInput.Normal : TextInput.Password
                            font {
                                family: "Montserrat"
                                pixelSize: 14
                            }
                            color: Theme.current.textColor_Actived
                            Layout.fillWidth: true
                            background: Rectangle {
                                color: "transparent"
                            }
                            text: loginViewModel.password
                            onTextChanged: loginViewModel.password = text
                            Keys.onReturnPressed: {
                                busyIndicator.visible = true
                                errorText.visible = false
                                loginViewModel.loginByViewModel()
                            }

                            onActiveFocusChanged: {
                                if (activeFocus) {

                                    // Clear cache khi focus thay đổi
                                    // clear()
                                }
                            }

                            Component.onDestruction: {
                                clear()
                            }
                        }

                        Text {
                            text: loginView.showPassword ? "\uf070" : "\uf06e"
                            font {
                                family: fontAW.name
                                pixelSize: 18
                            }
                            color: Theme.current.iconColor_Actived

                            MouseArea {
                                anchors.fill: parent
                                cursorShape: Qt.PointingHandCursor
                                onClicked: loginView.showPassword = !loginView.showPassword
                                hoverEnabled: true
                                onEntered: parent.color = Theme.current.iconColor_Actived
                                onExited: parent.color = Theme.current.iconColor_Normal
                            }
                        }
                    }
                }

                // Error and Loading Section
                Rectangle {
                    Layout.preferredHeight: 40
                    Layout.fillWidth: true
                    color: "transparent"

                    Item {
                        anchors.fill: parent
                        BusyIndicator {
                            id: busyIndicator
                            anchors.centerIn: parent
                            visible: false
                            running: visible
                        }

                        Text {
                            id: errorText
                            visible: false
                            anchors.fill: parent
                            text: loginViewModel.errorMessage
                            font {
                                family: "Montserrat"
                                pixelSize: 14
                            }
                            color: "red"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                }

                // Sign In Button
                Rectangle {
                    id: rectButtonSignIn
                    Layout.preferredHeight: 45
                    Layout.preferredWidth: parent.width * 0.8
                    Layout.alignment: Qt.AlignHCenter
                    radius: 8
                    color: Theme.current.buttonColor_Normal

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.PointingHandCursor
                        onEntered: parent.color = Theme.current.buttonColor_Actived
                        onExited: parent.color = Theme.current.buttonColor_Normal
                        onClicked: {
                            busyIndicator.visible = true
                            errorText.visible = false
                            loginViewModel.loginByViewModel()
                        }
                    }

                    Text {
                        anchors.centerIn: parent
                        text: "Sign in"
                        font {
                            family: "Montserrat"
                            pixelSize: 16
                            bold: true
                        }
                        color: Theme.current.textColor_Normal
                    }
                }

                // Reset Password Section
                Rectangle {
                    Layout.preferredHeight: 40
                    Layout.fillWidth: true
                    color: "transparent"

                    RowLayout {
                        anchors.centerIn: parent
                        spacing: 5

                        Text {
                            text: "Forgot your password?"
                            font {
                                family: "Montserrat"
                                pixelSize: 14
                            }
                            color: Theme.current.textColor_Normal
                        }

                        Text {
                            text: "Reset"
                            font {
                                family: "Montserrat"
                                pixelSize: 14
                                bold: true
                            }
                            color: Theme.current.textColor_Normal

                            MouseArea {
                                anchors.fill: parent
                                cursorShape: Qt.PointingHandCursor
                                hoverEnabled: true
                                onEntered: parent.color = Theme.current.textColor_Actived
                                onExited: parent.color = Theme.current.textColor_Normal
                            }
                        }
                    }
                }

                Item {
                    Layout.fillHeight: true
                }
            }
        }
    }

    Connections {
        target: loginViewModel
        function onLoginSuccess() {
            busyIndicator.visible = false
            loginViewModel.loginSuccess()
        }

        function onErrorMessageChanged() {
            if (loginViewModel.errorMessage !== "") {
                errorText.visible = true
                errorText.text = loginViewModel.errorMessage
                busyIndicator.visible = false
            }
        }
    }
    Component.onCompleted: {
        gc()
    }
}
