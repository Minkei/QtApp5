pragma ComponentBehavior

import QtQuick
import QtQuick.Layouts
import "../Themes/ThemeManager.js" as Theme

Item {
    id: mainView
    width: 1360
    height: 768
    visible: true

    FontLoader {
        id: fontAW
        source: "../Fonts/fa-solid-900.ttf"
    }

    Timer {
        id: collapseNavigationTimer
        interval: 600
        running: false
        repeat: false
        onTriggered: {
            if (!rectNavigationMouseArea.containsMouse
                && !rectNavigationMouseArea.isMouseOverAnyButton()) {
                mainView.isExpandNavigation = false
            }
        }
    }

    property bool isExpandNavigation: false
    property int selectedIndex: 0 // Thêm property để theo dõi button được chọn

    ListModel {
        id: navigationButtonsModel
        ListElement {
            iconText: "\uf029"
            buttonText: "QR Scanner"
            viewName: "QRScannerView.qml"
        }
        ListElement {
            iconText: "\uf1c0"
            buttonText: "Data"
            viewName: "DataView.qml"
        }
        ListElement {
            iconText: "\uf200"
            buttonText: "Report"
            viewName: "ReportView.qml"
        }
        ListElement {
            iconText: "\uf0c0"
            buttonText: "Setting"
            viewName: "SettingView.qml"
        }
        ListElement {
            iconText: "\uf590"
            buttonText: "Support"
            viewName: "SupportView.qml"
        }
    }

    // RowLayout {
    //     id: mainRowLayout
    //     anchors.fill: parent
    //     spacing: 0
    // }
    Rectangle {
        id: rectNavigation
        width: mainView.isExpandNavigation ? 200 : 60
        Behavior on width {
            NumberAnimation {
                duration: 500
            }
        }
        color: Theme.current.panelBackgroundColor_Normal
        radius: 10
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.leftMargin: 10
        anchors.topMargin: 10
        anchors.bottomMargin: 10
        border.color: mainView.isExpandNavigation ? Theme.current.panelBackgroundColor_Hovered : Theme.current.panelBackgroundColor_Normal
        border.width: mainView.isExpandNavigation ? 1 : 0

        clip: true

        // Layout.preferredWidth: mainView.isExpandNavigation ? 200 : 60
        z: 1

        MouseArea {
            id: rectNavigationMouseArea
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                collapseNavigationTimer.stop()
                mainView.isExpandNavigation = true
            }
            onExited: {
                // if (!isMouseOverAnyButton()) {
                //     mainView.isExpandNavigation = false
                // }
                collapseNavigationTimer.restart()
            }

            function isMouseOverAnyButton() {
                for (var i = 0; i < columnLayoutNavigation.children.length; i++) {
                    let child = columnLayoutNavigation.children[i]
                    if (child.buttonMouseArea
                            && child.buttonMouseArea.containsMouse) {
                        return true
                    }
                }
                return false
            }
        }

        ColumnLayout {
            id: columnLayoutNavigation
            spacing: 15
            anchors {
                fill: parent
                topMargin: 20
                bottomMargin: 20
            }

            Rectangle {
                Layout.preferredHeight: 40
                Layout.preferredWidth: parent.width
                color: "transparent"

                RowLayout {
                    anchors.centerIn: parent
                    spacing: 8

                    // Hamburger menu icon when collapsed
                    Text {
                        text: "\uf0c9" // Bars/hamburger icon
                        font {
                            family: fontAW.name
                            pixelSize: 24
                        }
                        color: Theme.current.iconColor_Normal
                        visible: !mainView.isExpandNavigation
                        Layout.alignment: Qt.AlignVCenter
                    }

                    // QRScanner text when expanded
                    Text {
                        text: "QR Scanner"
                        font {
                            family: "Montserrat"
                            pixelSize: 24
                            bold: true
                        }
                        color: Theme.current.textColor_Normal
                        visible: mainView.isExpandNavigation
                        Layout.alignment: Qt.AlignVCenter
                    }
                }
            }

            Repeater {
                id: navigationRepeater
                model: navigationButtonsModel
                delegate: Rectangle {
                    id: rectButton
                    required property int index
                    Layout.preferredHeight: 45
                    Layout.preferredWidth: mainView.isExpandNavigation ? 180 : 50
                    Layout.alignment: Qt.AlignHCenter
                    radius: 10
                    property bool isSelected: index === mainView.selectedIndex
                    color: {
                        if (rectButton.isSelected) {
                            return Theme.current.buttonColor_Actived
                        }
                        return buttonMouseArea.containsMouse ? Theme.current.buttonColor_Hovered : "transparent"
                    }

                    property alias buttonMouseArea: buttonMouseArea

                    Behavior on Layout.preferredWidth {
                        NumberAnimation {
                            duration: 500
                            easing.type: Easing.InOutQuad
                        }
                    }

                    MouseArea {
                        id: buttonMouseArea
                        anchors.fill: parent
                        hoverEnabled: true
                        propagateComposedEvents: true

                        onEntered: {
                            collapseNavigationTimer.stop()
                            mainView.isExpandNavigation = true
                        }

                        onExited: {
                            if (!rectNavigationMouseArea.containsMouse) {
                                // mainView.isExpandNavigation = false
                                collapseNavigationTimer.restart()
                            }
                        }

                        onClicked: {
                            mainView.selectedIndex = rectButton.index // Cập nhật button được chọn
                            console.log("Click button:", rectButton.index)
                            childViewLoader.source = navigationRepeater.model.get(
                                rectButton.index).viewName
                        }
                    }

                    RowLayout {
                        anchors {
                            fill: parent
                            leftMargin: 15
                            rightMargin: 15
                        }
                        spacing: 0
                        Item {
                            Layout.fillWidth: true
                        }
                        Text {
                            text: navigationRepeater.model.get(rectButton.index).iconText
                            font {
                                family: fontAW.name
                                pixelSize: 18
                            }
                            color: rectButton.isSelected || buttonMouseArea.containsMouse ? Theme.current.iconColor_Actived : Theme.current.iconColor_Normal
                            Layout.alignment: Qt.AlignVCenter
                        }

                        Text {
                            text: navigationRepeater.model.get(rectButton.index).buttonText
                            visible: mainView.isExpandNavigation
                            font {
                                family: "Montserrat"
                                pixelSize: 14
                                bold: true
                            }
                            color: rectButton.isSelected
                                   || buttonMouseArea.containsMouse ? Theme.current.textColor_Actived : Theme.current.textColor_Normal
                            Layout.fillWidth: true
                            Layout.alignment: Qt.AlignVCenter
                            leftPadding: 10
                        }
                        Item {
                            Layout.fillWidth: true
                        }
                    }
                }
            }

            Item {
                Layout.fillHeight: true
            }

            ////
            Rectangle {
                id: rectCurrentUser
                Layout.fillWidth: parent.width
                Layout.preferredHeight: 60
                color: "transparent"
                Layout.alignment: Qt.AlignLeft

                RowLayout {
                    anchors {
                        fill: parent
                    }
                    spacing: 0

                    Item {
                        Layout.fillWidth: true
                    }

                    Rectangle {
                        Layout.preferredHeight: 40
                        Layout.preferredWidth: 40
                        Layout.alignment: Qt.AlignHCenter
                        radius: Layout.preferredWidth / 2
                        color: Theme.current.panelBackgroundColor_Actived

                        Text {
                            anchors.centerIn: parent
                            text: "\uf007"
                            font {
                                family: fontAW.name
                                pixelSize: 20
                            }
                            color: Theme.current.iconColor_Normal
                            visible: !userModel.photoUrl
                        }
                    }

                    Rectangle {
                        Layout.preferredHeight: 40
                        Layout.leftMargin: 10
                        Layout.fillWidth: true
                        visible: mainView.isExpandNavigation
                        color: "transparent"

                        ColumnLayout {
                            spacing: 3
                            anchors.fill: parent
                            Text {
                                id: currentUserEmail
                                text: userModel.email || "Unknown"
                                font {
                                    family: "Montserrat"
                                    pixelSize: 14
                                }
                                color: Theme.current.textColor_Normal
                            }

                            Text {
                                id: logoutButton
                                text: "Log out"
                                font {
                                    family: "Montserrat"
                                    pixelSize: 12
                                    // bold: true
                                    // italic: true
                                }
                                color: Theme.current.textColor_Normal

                                MouseArea {
                                    anchors.fill: parent
                                    hoverEnabled: true
                                    cursorShape: Qt.PointingHandCursor

                                    onEntered: {
                                        logoutButton.font.color = Theme.current.textColor_Horvered
                                    }
                                    onClicked: {
                                        console.log(
                                            "Log out button is clicked!")
                                        // Command
                                        mainViewModel.logoutByViewModel()

                                    }
                                }
                            }
                        }
                    }

                    Item {
                        Layout.fillWidth: true
                        // visible: !mainView.isExpandNavigation
                    }
                }
            }
        }
    }

    Rectangle {
        id: rectMainContent

        // Layout.fillHeight: true
        // Layout.fillWidth: true
        color: "transparent"
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.leftMargin: 70
        // clip: true
        // Layout.leftMargin: 60
        // Layout.fillHeight: true
        // Layout.fillWidth: true
        // border.width: 1
        // border.color: "black"
        // radius: 10
        Loader {
            id: childViewLoader
            anchors.fill: parent
            source: "QRScannerView.qml"
        }
    }
}
