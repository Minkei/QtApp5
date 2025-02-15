import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtMultimedia 6.2

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

    property bool isPopupOpen: false

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
            Layout.margins: 10
            Layout.bottomMargin: 5

            color: qrscanner.backgroundColor

            RowLayout {
                id: rowLayoutHeader
                anchors.fill: parent
                spacing: 30

                Item {
                    Layout.fillWidth: true
                }

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
                        }
                        Text {
                            id: iconDate
                            Layout.preferredHeight: 40
                            Layout.preferredWidth: 40
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
                            Layout.preferredWidth: 100
                            text: qrScannerViewModel.currentDate
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
                        }
                        Text {
                            Layout.preferredHeight: 40
                            Layout.preferredWidth: 40
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
                            Layout.preferredWidth: 100
                            text: qrScannerViewModel.currentTime
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
                            qrscanner.isPopupOpen = !qrscanner.isPopupOpen
                            // console.log("qrscanner.isPopupOpen",
                            //             qrscanner.isPopupOpen)
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
                            text: qrScannerViewModel.selectedCamera
                                  || "Select camera"
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
                            text: qrscanner.isPopupOpen ? "\uf106" : "\uf107"
                            font {
                                family: fontAW.name
                                pixelSize: 14
                            }
                            color: qrscanner.primaryBlue
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter

                            rotation: qrscanner.isPopupOpen ? 360 : 0
                            Behavior on rotation {
                                NumberAnimation {
                                    duration: 200
                                    easing.type: Easing.InOutQuad
                                }
                            }

                            scale: mouseAreaSelectCameraDropDown.containsMouse ? 1.1 : 1.0
                            Behavior on scale {
                                NumberAnimation {
                                    duration: 100
                                    easing.type: Easing.InOutQuad
                                }
                            }
                        }
                    }

                    Popup {
                        id: popupSelectCamera
                        visible: qrscanner.isPopupOpen
                        y: parent.height + 8
                        width: parent.width
                        topMargin: 10
                        dim: false
                        modal: false
                        closePolicy: Popup.CloseOnPressOutside | Popup.CloseOnEscape
                        padding: 10

                        // onOpened: {
                        //     qrScannerViewModel.refreshCameraList()
                        // }
                        background: Rectangle {
                            color: qrscanner.backgroundColor
                            radius: 10
                            border.color: qrscanner.lightBlue
                            border.width: 1
                        }
                        contentItem: ListView {
                            id: listViewPopupSelectCamera
                            implicitHeight: contentHeight
                            model: qrScannerViewModel.availableCameras

                            clip: true

                            delegate: ItemDelegate {
                                id: delegateItem
                                width: popupSelectCamera.width
                                height: 40
                                MouseArea {
                                    anchors.fill: parent
                                    cursorShape: Qt.PointingHandCursor
                                    onClicked: {
                                        qrScannerViewModel.setSelectedCamera(
                                                    modelData)
                                        selectedCamera.text = modelData
                                        popupSelectCamera.close()
                                    }
                                }

                                contentItem: Text {
                                    text: modelData
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

                                // onClicked: {
                                //     qrScannerViewModel.setSelectedCamera(
                                //                 modelData)
                                //     selectedCamera.text = modelData
                                //     popupSelectCamera.close()
                                // }
                            }
                            ScrollIndicator.vertical: ScrollIndicator {}
                        }
                    }
                }

                Rectangle {
                    id: rectRefreshButton
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 150
                    border.color: qrscanner.lightBlue
                    color: "white"
                    radius: 8

                    MouseArea {
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                        hoverEnabled: true
                        onClicked: {
                            refreshAnimation.start()
                            qrScannerViewModel.refreshCameraList()
                        }
                    }

                    RowLayout {
                        id: rowRefreshButton
                        anchors.fill: parent
                        spacing: 0
                        Item {
                            Layout.fillWidth: true
                        }
                        Text {
                            id: refreshIcon
                            Layout.preferredHeight: 40
                            Layout.preferredWidth: 40
                            Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            text: "\uf021"
                            font {
                                family: fontAW.name
                                pixelSize: 14
                            }
                            color: qrscanner.primaryBlue

                            RotationAnimation {
                                id: refreshAnimation
                                target: refreshIcon
                                from: 0
                                to: 360
                                duration: 500
                                running: false
                            }
                        }
                        Text {
                            id: textRefreshButton
                            Layout.preferredHeight: 40
                            Layout.preferredWidth: 100
                            text: "Refresh"
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
                    id: rectControlCameraButton
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 150
                    border.color: qrscanner.lightBlue
                    border.width: 1
                    radius: 8

                    MouseArea {
                        z: 1
                        id: mouseAreaControlCameraButton
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                        hoverEnabled: true
                        onClicked: {
                            qrScannerViewModel.toggleStreaming()
                            // console.log("isStreaming: ",
                            //             qrScannerViewModel.isStreaming)
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

                    RowLayout {
                        id: rowLayoutControlCameraButton
                        spacing: 0
                        anchors.fill: parent

                        Item {
                            Layout.fillWidth: true
                        }

                        Text {
                            id: iconControlCameraButtonn
                            text: !qrScannerViewModel.isStreaming ? "\uf04b" : "\uf04c"
                            Layout.preferredHeight: 40
                            Layout.preferredWidth: 40
                            Layout.alignment: Qt.AlignVCenter
                            font {
                                family: fontAW.name
                                pixelSize: 14
                            }
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: qrscanner.primaryBlue
                        }
                        Text {
                            id: textControlCameraButtonn
                            text: qrScannerViewModel.isStreaming ? "Pause" : "Play"
                            Layout.fillHeight: true
                            Layout.preferredWidth: 100
                            font {
                                family: "Montserrat"
                                pixelSize: 14
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
            color: "transparent"

            RowLayout {
                id: rowLayoutContent
                anchors.fill: parent
                spacing: 0

                Rectangle {
                    id: rectDataTable
                    Layout.fillHeight: true
                    radius: 10
                    Layout.preferredWidth: parent.width * 0.6
                    Layout.margins: 5
                    Layout.topMargin: 0
                    color: qrscanner.backgroundColor

                    ColumnLayout {
                        id: columnLayoutDataTable
                        anchors.fill: parent
                        spacing: 0

                        Rectangle {
                            id: rectTableHeader
                            Layout.preferredHeight: 40
                            Layout.fillWidth: true
                            color: "transparent"
                            Layout.alignment: Qt.AlignTop

                            RowLayout {
                                id: rowLayoutTableHeader
                                anchors.fill: parent
                                spacing: 0

                                Repeater {
                                    id: repeaterTableHeader
                                    model: ["No.", "QR Code", "Date", "Time", "PIC"]

                                    Rectangle {
                                        Layout.preferredWidth: parent.width / 5
                                        Layout.fillHeight: true
                                        color: "transparent"

                                        Text {
                                            anchors.fill: parent
                                            text: modelData
                                            horizontalAlignment: Text.AlignHCenter
                                            verticalAlignment: Text.AlignVCenter
                                            font {
                                                family: "Montserrat"
                                                pixelSize: 14
                                                bold: true
                                            }
                                            color: qrscanner.textColor
                                        }
                                    }
                                }
                            }
                        }

                        Rectangle {
                            id: rectTableContent
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            color: "transparent"

                            ListView {
                                id: listViewTableContent
                                anchors.fill: parent

                                model: ListModel {
                                    ListElement {
                                        No: "1"
                                        QRCodeContent: "ABC"
                                        ScannedDate: "06/02/2025"
                                        ScannedTime: "20:05:00"
                                        PIC: "Tran Van A"
                                    }
                                    ListElement {
                                        No: "2"
                                        QRCodeContent: "XYZ"
                                        ScannedDate: "06/02/2025"
                                        ScannedTime: "20:05:00"
                                        PIC: "Tran Van B"
                                    }
                                    ListElement {
                                        No: "3"
                                        QRCodeContent: "KMW"
                                        ScannedDate: "06/02/2025"
                                        ScannedTime: "20:05:00"
                                        PIC: "Tran Van C"
                                    }
                                }

                                delegate: Rectangle {
                                    width: parent.width
                                    height: 40
                                    color: "transparent"

                                    RowLayout {
                                        id: rowLayoutTableContent
                                        anchors.fill: parent
                                        spacing: 0

                                        Rectangle {
                                            id: rectTableContentNo
                                            Layout.preferredWidth: parent.width / 5
                                            Layout.fillHeight: parent
                                            color: "transparent"
                                            Text {
                                                anchors.fill: parent
                                                text: No
                                                anchors.centerIn: parent
                                                horizontalAlignment: Text.AlignHCenter
                                                verticalAlignment: Text.AlignVCenter
                                                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                                font {
                                                    family: "Montserrat"
                                                    pixelSize: 14
                                                }
                                                color: qrscanner.textColor
                                            }
                                        }

                                        Rectangle {
                                            id: rectTableContentQRCodeContent
                                            Layout.preferredWidth: parent.width / 5
                                            Layout.fillHeight: parent
                                            color: "transparent"
                                            Text {
                                                anchors.fill: parent
                                                text: QRCodeContent
                                                anchors.centerIn: parent
                                                horizontalAlignment: Text.AlignHCenter
                                                verticalAlignment: Text.AlignVCenter
                                                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                                font {
                                                    family: "Montserrat"
                                                    pixelSize: 14
                                                }
                                                color: qrscanner.textColor
                                            }
                                        }

                                        Rectangle {
                                            id: rectTableContentScannedDate
                                            Layout.preferredWidth: parent.width / 5
                                            Layout.fillHeight: parent
                                            color: "transparent"
                                            Text {
                                                anchors.fill: parent
                                                text: ScannedDate
                                                anchors.centerIn: parent
                                                horizontalAlignment: Text.AlignHCenter
                                                verticalAlignment: Text.AlignVCenter
                                                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                                font {
                                                    family: "Montserrat"
                                                    pixelSize: 14
                                                }
                                                color: qrscanner.textColor
                                            }
                                        }

                                        Rectangle {
                                            id: rectTableContentScannedTime
                                            Layout.preferredWidth: parent.width / 5
                                            Layout.fillHeight: parent
                                            color: "transparent"
                                            Text {
                                                anchors.fill: parent
                                                text: ScannedTime
                                                anchors.centerIn: parent
                                                horizontalAlignment: Text.AlignHCenter
                                                verticalAlignment: Text.AlignVCenter
                                                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                                font {
                                                    family: "Montserrat"
                                                    pixelSize: 14
                                                }
                                                color: qrscanner.textColor
                                            }
                                        }
                                        Rectangle {
                                            id: rectTableContentPIC
                                            Layout.preferredWidth: parent.width / 5
                                            Layout.fillHeight: parent
                                            color: "transparent"
                                            Text {
                                                anchors.fill: parent
                                                text: PIC
                                                anchors.centerIn: parent
                                                horizontalAlignment: Text.AlignHCenter
                                                verticalAlignment: Text.AlignVCenter
                                                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                                font {
                                                    family: "Montserrat"
                                                    pixelSize: 14
                                                }
                                                color: qrscanner.textColor
                                            }
                                        }
                                        Item {
                                            Layout.fillWidth: true
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                Rectangle {
                    id: rectCameraViewPort
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.margins: 5
                    Layout.topMargin: 0
                    radius: 10
                    color: qrscanner.backgroundColor

                    ColumnLayout {
                        id: columnLayoutRectCameraViewPort
                        anchors.fill: parent
                        Item {
                            Layout.fillHeight: true
                        }

                        Text {
                            id: textTitleCameraViewPort
                            text: qrScannerViewModel.selectedCamera
                            font {
                                family: "Montserrat"
                                pixelSize: 14
                                italic: true
                            }
                            color: qrscanner.textColor
                            Layout.fillWidth: true
                            Layout.preferredHeight: 40
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }

                        Rectangle {
                            id: rectCameraViewPortImage
                            Layout.preferredHeight: parent.width * 0.6
                            Layout.preferredWidth: parent.width * 0.6
                            radius: 10
                            Layout.alignment: Qt.AlignHCenter
                            border.color: qrscanner.lightBlue
                            border.width: 1
                            color: "transparent"
                            clip: true

                            // Busy Indicator (centered)
                            BusyIndicator {
                                id: cameraBusyIndicator
                                anchors.centerIn: parent
                                running: qrScannerViewModel.isLoading
                                visible: qrScannerViewModel.isLoading
                                // onVisibleChanged: console.log("isLoading",
                                // visible)
                            }

                            // Video Stream
                            VideoOutput {
                                id: videoOutput
                                anchors.fill: parent
                                clip: true
                                layer.smooth: true
                                fillMode: VideoOutput.PreserveAspectCrop
                                visible: qrScannerViewMode.isStreaming

                                Component.onCompleted: {
                                    qrScannerViewModel.setVideoSink(
                                                videoOutput.videoSink)
                                }
                            }

                            // Fallback text (optional)
                            Text {
                                text: "Camera unavailable"
                                font {
                                    family: "Montserrat"
                                    pixelSize: 20
                                }
                                color: qrscanner.textColor
                                visible: !qrScannerViewModel.isLoading
                                         && !qrScannerViewMode.isStreaming
                                anchors.centerIn: parent
                            }
                        }

                        Rectangle {
                            id: rectLastedResultsQRCode
                            color: "#bf8b87"
                            Layout.preferredHeight: parent.width * 0.3
                            Layout.preferredWidth: parent.width * 0.6
                            Layout.alignment: Qt.AlignHCenter
                            radius: 10

                            Layout.topMargin: 30

                            ColumnLayout {
                                id: columnLayoutLastedResultsQRCode
                                anchors.fill: parent
                                Text {
                                    id: textLastedQRCodeTitle
                                    Layout.fillWidth: true
                                    Layout.preferredHeight: 30
                                    text: "Lasted QR Code"
                                    font {
                                        family: "Montserrat"
                                        pixelSize: 16
                                        bold: true
                                    }
                                    color: "white"
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                                }

                                Text {
                                    id: textLastedQRCodeContent
                                    Layout.fillWidth: true
                                    Layout.fillHeight: true
                                    text: "Askdjsdk"
                                    font {
                                        family: "Montserrat"
                                        pixelSize: 16
                                    }
                                    color: "white"
                                    topPadding: 10
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignTop
                                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                }
                            }
                        }

                        Item {
                            Layout.fillHeight: true
                        }
                    }
                }
            }
        }
    }
}
