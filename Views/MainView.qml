pragma ComponentBehavior

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Controls.Basic

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

    // Định nghĩa các màu sắc chính
    property color primaryBlue: "#2563eb"
    property color lightBlue: "#60a5fa"
    property color hoverBlue: "#3b82f6"
    property color textColor: "#1e3a8a"
    property color backgroundColor: "#f0f9ff"
    property color selectedBlue: "#1d4ed8" // Màu khi button được chọn

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
        color: mainView.backgroundColor
        radius: 10
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.leftMargin: 10
        anchors.topMargin: 10
        anchors.bottomMargin: 10
        border.color: mainView.isExpandNavigation ? mainView.primaryBlue : "transparent"
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
                        color: mainView.primaryBlue
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
                        color: mainView.primaryBlue
                        visible: mainView.isExpandNavigation
                        Layout.alignment: Qt.AlignVCenter
                    }
                }
            }

            Repeater {
                model: navigationButtonsModel
                delegate: Rectangle {
                    id: rectButton
                    Layout.preferredHeight: 45
                    Layout.preferredWidth: mainView.isExpandNavigation ? 180 : 50
                    Layout.alignment: Qt.AlignHCenter
                    radius: 10
                    property bool isSelected: index === mainView.selectedIndex
                    color: {
                        if (isSelected) {
                            return mainView.selectedBlue
                        }
                        return buttonMouseArea.containsMouse ? mainView.hoverBlue : "transparent"
                    }

                    property alias buttonMouseArea: buttonMouseArea

                    Behavior on Layout.preferredWidth {
                        NumberAnimation {
                            duration: 400
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
                            mainView.selectedIndex = index // Cập nhật button được chọn
                            console.log("Click button:", index)
                            childViewLoader.source = model.viewName
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
                            text: iconText
                            font {
                                family: fontAW.name
                                pixelSize: 18
                            }
                            color: rectButton.isSelected
                                   || buttonMouseArea.containsMouse ? "white" : primaryBlue
                            Layout.alignment: Qt.AlignVCenter
                        }

                        Text {
                            text: buttonText
                            visible: mainView.isExpandNavigation
                            font {
                                family: "Montserrat"
                                pixelSize: 14
                                bold: true
                            }
                            color: rectButton.isSelected
                                   || buttonMouseArea.containsMouse ? "white" : mainView.textColor
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
                        // visible: !mainView.isExpandNavigation
                    }

                    Rectangle {
                        // width: 40
                        // height: 40
                        Layout.preferredHeight: 40
                        Layout.preferredWidth: 40
                        Layout.alignment: Qt.AlignHCenter
                        radius: Layout.preferredWidth / 2
                        color: mainView.lightBlue

                        Text {
                            anchors.centerIn: parent
                            text: "\uf007"
                            font {
                                family: fontAW.name
                                pixelSize: 20
                            }
                            color: mainView.primaryBlue
                            visible: !userModel.photoUrl
                        }

                        // Image {
                        //     id: imageCurrentUser
                        //     source: userModel.photoUrl
                        //     visible: userModel.photoUrl !== ""
                        //     fillMode: Image.PreserveAspectCrop
                        // }
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
                                color: mainView.textColor
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
                                color: mainView.textColor

                                MouseArea {
                                    anchors.fill: parent
                                    hoverEnabled: true
                                    cursorShape: Qt.PointingHandCursor
                                    onEntered: {
                                        logoutButton.font.color = mainView.primaryBlue
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
