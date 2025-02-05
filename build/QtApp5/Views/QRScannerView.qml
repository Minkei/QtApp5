// pragma ComponentBehavior: Bound

// QRScannerView.qml
import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

// import QtQuick.Controls.Calendar

// import Felgo 3.0

// import QtQuick.Layouts
Item {
    id: qrscanner
    anchors.fill: parent
    width: 1300
    height: 768

    property color primaryBlue: "#2563eb"
    property color lightBlue: "#60a5fa"
    property color hoverBlue: "#3b82f6"
    property color textColor: "#1e3a8a"
    property color backgroundColor: "#f0f9ff"

    property bool isStreaming: false

    FontLoader {
        id: fontAW
        source: "../Fonts/fa-solid-900.ttf"
    }

    ColumnLayout {
        id: columnLayoutMain
        anchors.fill: parent

        Rectangle {
            id: rectHeader
            Layout.preferredHeight: 60
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
            radius: 8
            activeFocusOnTab: true
            Layout.margins: 5

            color: "white"

            RowLayout {
                id: rowLayoutHeader
                anchors.fill: parent
                spacing: 30

                Rectangle {
                    id: rectDate
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 150
                    Layout.leftMargin: 10
                    color: "white"
                    border.color: qrscanner.lightBlue
                    radius: 8

                    RowLayout {
                        id: rowLayoutDate
                        anchors.fill: parent
                        spacing: 0
                        Item {
                            Layout.fillWidth: true
                            // Layout.preferredWidth: 10
                        }
                        Text {
                            id: iconDate
                            Layout.preferredHeight: 40
                            Layout.preferredWidth: 40
                            // Layout.leftMargin: 5
                            Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            text: "\uf133"
                            font {
                                family: fontAW.name
                                pixelSize: 14
                            }
                            color: qrscanner.primaryBlue
                        }
                        Text {
                            id: textDate
                            Layout.preferredHeight: 40
                            // Layout.fillWidth: true
                            Layout.preferredWidth: 100
                            text: "06/02/2025"
                            font {
                                family: "Montserrat"
                                pixelSize: 14
                                bold: false
                            }
                            color: qrscanner.textColor
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            leftPadding: 5
                        }
                        Item {
                            Layout.fillWidth: true
                        }
                    }
                }

                Rectangle {
                    id: rectTime
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 150
                    border.color: qrscanner.lightBlue
                    color: "white"
                    radius: 8

                    RowLayout {
                        id: rowLayoutTime
                        anchors.fill: parent
                        spacing: 0
                        Item {
                            Layout.fillWidth: true
                            // Layout.preferredWidth: 10
                        }
                        Text {
                            Layout.preferredHeight: 40
                            Layout.preferredWidth: 40
                            // Layout.leftMargin: 5
                            Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            text: "\uf017"
                            font {
                                family: fontAW.name
                                pixelSize: 14
                            }
                            color: qrscanner.primaryBlue
                        }
                        Text {
                            id: textTime
                            Layout.preferredHeight: 40
                            // Layout.fillWidth: true
                            Layout.preferredWidth: 100
                            text: "12:50:00"
                            font {
                                family: "Montserrat"
                                pixelSize: 14
                                bold: false
                            }
                            color: qrscanner.textColor
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            leftPadding: 5
                        }
                        Item {
                            Layout.fillWidth: true
                        }
                    }
                }

                Rectangle {
                    id: rectSelectCamera
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 300
                    radius: 8
                    color: "white"
                    border.color: qrscanner.lightBlue

                    MouseArea {
                        id: mouseAreaSelectCameraDropDown
                        anchors.fill: parent
                        z: 1
                        cursorShape: Qt.PointingHandCursor
                        onClicked: {
                            console.log("popSelectCamera.opened?",
                                        popupSelectCamera.opened)
                            if (!popupSelectCamera.visible) {
                                popupSelectCamera.open()
                            }
                        }
                    }

                    RowLayout {
                        id: rowLayoutSelectCamera
                        anchors.fill: parent
                        spacing: 0

                        Text {
                            id: selectedCamera
                            Layout.preferredHeight: 40
                            Layout.fillWidth: true
                            text: "Select camera"
                            font {
                                family: "Montserrat"
                                pixelSize: 14
                                bold: false
                            }
                            color: qrscanner.textColor
                            horizontalAlignment: Text.AlignLeft
                            verticalAlignment: Text.AlignVCenter
                            leftPadding: 20
                        }

                        Text {
                            id: iconAngleDown
                            Layout.preferredHeight: 40
                            Layout.preferredWidth: 40
                            Layout.alignment: Qt.AlignRight
                            text: "\uf107"
                            font {
                                family: fontAW.name
                                pixelSize: 14
                            }
                            color: qrscanner.primaryBlue
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }

                    Popup {
                        id: popupSelectCamera

                        // y: rectSelectCamera
                        y: parent.height + 8
                        width: parent.width
                        topMargin: 10
                        dim: false
                        modal: false
                        closePolicy: Popup.CloseOnPressOutside | Popup.CloseOnEscape
                        // width: rectSelectCamera.width
                        padding: 10

                        background: Rectangle {
                            color: qrscanner.backgroundColor
                            radius: 5
                            border.color: qrscanner.lightBlue
                            border.width: 1
                        }
                        contentItem: ListView {
                            id: listViewPopupSelectCamera
                            implicitHeight: contentHeight
                            // model: ["Camera 1", "Camera 2", "Camera 3"]
                            model: ListModel {
                                ListElement {
                                    name: "Camera 1"
                                }
                                ListElement {
                                    name: "Camera 2"
                                }
                                ListElement {
                                    name: "Camera 3"
                                }
                                ListElement {
                                    name: "Camera 4"
                                }
                            }

                            clip: true

                            delegate: ItemDelegate {
                                id: delegateItem
                                width: popupSelectCamera.width
                                height: 40

                                contentItem: Text {
                                    text: model.name
                                    font {
                                        family: "Montserrat"
                                        pixelSize: 14
                                    }
                                    color: qrscanner.textColor
                                    verticalAlignment: Text.AlignVCenter
                                    leftPadding: 10
                                }

                                background: Rectangle {
                                    color: delegateItem.highlighted ? qrscanner.backgroundColor : "transparent"
                                }

                                onClicked: {
                                    selectedCamera.text = model.name
                                    popupSelectCamera.close()
                                }
                            }
                            ScrollIndicator.vertical: ScrollIndicator {}
                        }
                    }
                }

                Rectangle {
                    id: rectControlCameraButton
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 150
                    border.color: qrscanner.lightBlue
                    border.width: 1
                    radius: 8

                    RowLayout {
                        id: rowLayoutControlCameraButton
                        spacing: 0
                        anchors.fill: parent
                        MouseArea {
                            id: mouseAreaControlCameraButton
                            anchors.fill: parent
                            z: 1
                            cursorShape: Qt.PointingHandCursor
                            hoverEnabled: true
                            onClicked: {
                                qrscanner.isStreaming = !qrscanner.isStreaming
                            }

                            onEntered: {
                                rectControlCameraButton.color = qrscanner.primaryBlue
                                textControlCameraButtonn.color = "white"
                                textControlCameraButtonn.font.bold = true
                                iconControlCameraButtonn.color = "white"
                            }

                            onExited: {
                                rectControlCameraButton.color = "white"
                                textControlCameraButtonn.color = qrscanner.textColor
                                textControlCameraButtonn.font.bold = false
                                iconControlCameraButtonn.color = qrscanner.primaryBlue
                            }
                        }
                        Item {
                            Layout.fillWidth: true
                        }

                        Text {
                            id: iconControlCameraButtonn
                            text: qrscanner.isStreaming ? "\uf04b" : "\uf04c"
                            Layout.preferredHeight: 40
                            Layout.preferredWidth: 40
                            Layout.alignment: Qt.AlignVCenter
                            font {
                                family: fontAW.name
                                pixelSize: 16
                            }
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: qrscanner.primaryBlue
                        }
                        Text {
                            id: textControlCameraButtonn
                            text: qrscanner.isStreaming ? "Play" : "Paused"
                            Layout.fillHeight: true
                            Layout.preferredWidth: 100
                            font {
                                family: "Montserrat"
                                pixelSize: 16
                            }
                            color: qrscanner.textColor
                            horizontalAlignment: Text.AlignLeft
                            verticalAlignment: Text.AlignVCenter
                            leftPadding: 10
                        }
                        Item {
                            Layout.fillWidth: true
                        }
                    }
                }

                Item {
                    Layout.fillWidth: true
                }
            }
        }

        Rectangle {
            id: rectContent
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
            radius: 10
            Layout.margins: 5
            Layout.topMargin: 0
            color: "white"
        }
    }
}
