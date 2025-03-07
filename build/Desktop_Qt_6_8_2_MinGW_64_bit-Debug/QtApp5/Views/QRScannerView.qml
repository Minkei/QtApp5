pragma ComponentBehavior

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtMultimedia 6.2
import "../Themes/ThemeManager.js" as Theme

Item {
    id: qrscanner
    anchors.fill: parent
    width: 1300
    height: 768

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

            color: Theme.current.panelBackgroundColor_Normal

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
                    color: Theme.current.buttonColor_Normal
                    border.color: Theme.current.buttonBorder_Normal
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
                            color: Theme.current.iconColor_Normal
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
                            color: Theme.current.textColor_Normal
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
                    border.color: Theme.current.buttonBorder_Normal
                    color: Theme.current.buttonColor_Normal
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
                            color: Theme.current.iconColor_Normal
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
                            color: Theme.current.textColor_Normal
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
                    color: Theme.current.buttonColor_Normal
                    border.color: Theme.current.buttonBorder_Normal

                    MouseArea {
                        id: mouseAreaSelectCameraDropDown
                        anchors.fill: parent
                        z: 1
                        cursorShape: Qt.PointingHandCursor

                        onClicked: {
                            qrscanner.isPopupOpen = !qrscanner.isPopupOpen
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
                            color: Theme.current.textColor_Normal
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
                            color: Theme.current.iconColor_Normal
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

                        background: Rectangle {
                            color: Theme.current.panelBackgroundColor_Actived
                            radius: 10
                            border.color: Theme.current.panelBorderColor_Actived
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
                                    color: Theme.current.textColor_Actived
                                    verticalAlignment: Text.AlignVCenter
                                    leftPadding: 10
                                }

                                background: Rectangle {
                                    color: delegateItem.highlighted ? Theme.current.panelBackgroundColor_Hovered : "transparent"
                                }
                            }
                            ScrollIndicator.vertical: ScrollIndicator {}
                        }
                    }
                }

                Rectangle {
                    id: rectRefreshButton
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 150
                    border.color: Theme.current.buttonBorder_Normal
                    color: Theme.current.buttonColor_Normal
                    radius: 8

                    MouseArea {
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                        hoverEnabled: true
                        onClicked: {
                            refreshAnimation.start()
                            qrScannerViewModel.refreshCameraList()
                        }

                        onEntered: {
                            rectRefreshButton.color = Theme.current.buttonColor_Hovered
                            textRefreshButton.color = Theme.current.textColor_Hovered
                            textRefreshButton.font.bold = true
                            refreshIcon.color = Theme.current.iconColor_Hovered
                        }

                        onExited: {
                            rectRefreshButton.color = Theme.current.buttonColor_Normal
                            textRefreshButton.color = Theme.current.textColor_Normal
                            textRefreshButton.font.bold = false
                            refreshIcon.color = Theme.current.iconColor_Normal
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
                            color: Theme.current.iconColor_Normal

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
                            color: Theme.current.textColor_Normal
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
                    id: rectControlAudio
                    Layout.preferredHeight: 40
                    Layout.preferredWidth: 150
                    border.color: Theme.current.buttonBorder_Normal
                    border.width: 1
                    color: Theme.current.buttonColor_Normal
                    radius: 8

                    MouseArea {
                        id: mouseAreaControlAudio
                        anchors.fill: parent
                        z: 1
                        cursorShape: Qt.PointingHandCursor
                        hoverEnabled: true
                        onClicked: {
                            qrScannerViewModel.toggleAudio()
                        }
                        onEntered: {
                            rectControlAudio.color = Theme.current.buttonColor_Hovered
                            iconControlAudio.color = Theme.current.iconColor_Hovered
                            textControlAudio.color = Theme.current.textColor_Hovered
                            textControlAudio.font.bold = true
                        }
                        onExited: {
                            rectControlAudio.color = Theme.current.buttonColor_Normal
                            iconControlAudio.color = Theme.current.iconColor_Normal
                            textControlAudio.color = Theme.current.textColor_Normal
                            textControlAudio.font.bold = false
                        }
                    }
                    RowLayout {
                        id: rowLayoutControlAudio
                        spacing: 0
                        anchors.fill: parent
                        Item {
                            Layout.fillWidth: true
                        }
                        Text {
                            id: iconControlAudio
                            text: !qrScannerViewModel.isAudio ? "\uf6a9" : "\uf028"
                            Layout.preferredHeight: 40
                            Layout.preferredWidth: 40
                            Layout.alignment: Qt.AlignVCenter
                            font {
                                family: fontAW.name
                                pixelSize: 14
                            }
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: Theme.current.iconColor_Normal
                        }
                        Text {
                            id: textControlAudio
                            text: qrScannerViewModel.isAudio ? "Umuted" : "Muted"
                            Layout.fillHeight: true
                            Layout.preferredWidth: 100
                            font {
                                family: "Montserrat"
                                pixelSize: 14
                            }
                            color: Theme.current.textColor_Normal
                            horizontalAlignment: Text.AlignLeft
                            verticalAlignment: Text.AlignVCenter
                            leftPadding: 10
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
                    border.color: Theme.current.buttonBorder_Normal
                    border.width: 1
                    color: Theme.current.buttonColor_Normal
                    radius: 8

                    MouseArea {
                        z: 1
                        enabled: qrScannerViewModel.selectedCamera !== ""
                        id: mouseAreaControlCameraButton
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                        hoverEnabled: true
                        onClicked: {
                            qrScannerViewModel.toggleStreaming()
                        }

                        onEntered: {
                            rectControlCameraButton.color = Theme.current.buttonColor_Hovered
                            textControlCameraButtonn.color = Theme.current.textColor_Hovered
                            textControlCameraButtonn.font.bold = true
                            iconControlCameraButtonn.color = Theme.current.iconColor_Hovered
                        }

                        onExited: {
                            rectControlCameraButton.color = Theme.current.buttonColor_Normal
                            textControlCameraButtonn.color = Theme.current.textColor_Normal
                            textControlCameraButtonn.font.bold = false
                            iconControlCameraButtonn.color = Theme.current.iconColor_Normal
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
                            color: Theme.current.iconColor_Normal
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
                            color: Theme.current.textColor_Normal
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
                    color: Theme.current.panelBackgroundColor_Normal

                    property int noColumnWidth: rectDataTable.width * 0.1
                    property int qrCodeColumnWidth: rectDataTable.width * 0.4
                    property int dateColumnWidth: rectDataTable.width * 0.1
                    property int timeColumnWidth: rectDataTable.width * 0.1
                    property int picColumnWidth: rectDataTable.width * 0.3

                    ColumnLayout {
                        id: columnLayoutDataTable
                        anchors.fill: parent
                        spacing: 0

                        Rectangle {
                            id: rectTableHeader
                            Layout.preferredHeight: 50
                            Layout.fillWidth: true
                            color: "transparent"
                            Layout.alignment: Qt.AlignTop

                            RowLayout {
                                id: rowLayoutTableHeader
                                anchors.fill: parent
                                spacing: 0

                                Rectangle {
                                    // border.color: "white"
                                    // border.width: 1
                                    Layout.preferredWidth: rectDataTable.noColumnWidth
                                    Layout.fillHeight: parent
                                    color: "transparent"
                                    Text {
                                        anchors.fill: parent
                                        text: "No"
                                        anchors.centerIn: parent
                                        horizontalAlignment: Text.AlignHCenter
                                        verticalAlignment: Text.AlignVCenter
                                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                        font {
                                            family: "Montserrat"
                                            pixelSize: 14
                                            bold: true
                                        }
                                        color: Theme.current.textColor_Normal
                                    }
                                }

                                Rectangle {
                                    // border.color: "white"
                                    // border.width: 1
                                    Layout.preferredWidth: rectDataTable.qrCodeColumnWidth
                                    Layout.fillHeight: parent
                                    color: "transparent"
                                    Text {
                                        anchors.fill: parent
                                        text: "QR Code"
                                        anchors.centerIn: parent
                                        horizontalAlignment: Text.AlignHCenter
                                        verticalAlignment: Text.AlignVCenter
                                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                        font {
                                            family: "Montserrat"
                                            pixelSize: 14
                                            bold: true
                                        }
                                        color: Theme.current.textColor_Normal
                                    }
                                }

                                Rectangle {
                                    // border.color: "white"
                                    // border.width: 1
                                    Layout.preferredWidth: rectDataTable.dateColumnWidth
                                    Layout.fillHeight: parent
                                    color: "transparent"
                                    Text {
                                        anchors.fill: parent
                                        text: "Date"
                                        anchors.centerIn: parent
                                        horizontalAlignment: Text.AlignHCenter
                                        verticalAlignment: Text.AlignVCenter
                                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                        font {
                                            family: "Montserrat"
                                            pixelSize: 14
                                            bold: true
                                        }
                                        color: Theme.current.textColor_Normal
                                    }
                                }

                                Rectangle {
                                    // border.color: "white"
                                    // border.width: 1
                                    Layout.preferredWidth: rectDataTable.timeColumnWidth
                                    Layout.fillHeight: parent
                                    color: "transparent"
                                    Text {
                                        anchors.fill: parent
                                        text: "Time"
                                        anchors.centerIn: parent
                                        horizontalAlignment: Text.AlignHCenter
                                        verticalAlignment: Text.AlignVCenter
                                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                        font {
                                            family: "Montserrat"
                                            pixelSize: 14
                                            bold: true
                                        }
                                        color: Theme.current.textColor_Normal
                                    }
                                }

                                Rectangle {
                                    // border.color: "white"
                                    // border.width: 1
                                    Layout.preferredWidth: rectDataTable.picColumnWidth
                                    Layout.fillHeight: parent
                                    color: "transparent"
                                    Text {
                                        anchors.fill: parent
                                        text: "PIC"
                                        anchors.centerIn: parent
                                        horizontalAlignment: Text.AlignHCenter
                                        verticalAlignment: Text.AlignVCenter
                                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                        font {
                                            family: "Montserrat"
                                            pixelSize: 14
                                            bold: true
                                        }
                                        color: Theme.current.textColor_Normal
                                    }
                                }
                                Item {
                                    Layout.fillWidth: true
                                }
                            }
                        }

                        ///
                        Rectangle {
                            id: rectTableContent
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            color: "transparent"
                            clip: true
                            ListView {
                                id: listViewTableContent
                                anchors.fill: parent
                                model: qrScannerViewModel.qrCodeModel

                                delegate: Rectangle {
                                    width: parent.width
                                    height: 60
                                    color: "transparent"

                                    RowLayout {
                                        id: rowLayoutTableContent
                                        anchors.fill: parent
                                        spacing: 0

                                        Rectangle {
                                            // border.color: "white"
                                            // border.width: 1
                                            id: rectTableContentNo
                                            Layout.preferredWidth: rectDataTable.noColumnWidth
                                            Layout.fillHeight: parent
                                            color: "transparent"
                                            Text {
                                                anchors.fill: parent
                                                text: model.index + 1
                                                anchors.centerIn: parent
                                                horizontalAlignment: Text.AlignHCenter
                                                verticalAlignment: Text.AlignVCenter
                                                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                                font {
                                                    family: "Montserrat"
                                                    pixelSize: 14
                                                }
                                                color: Theme.current.textColor_Normal
                                            }
                                        }

                                        Rectangle {
                                            // border.color: "white"
                                            // border.width: 1
                                            id: rectTableContentQRCodeContent
                                            Layout.preferredWidth: rectDataTable.qrCodeColumnWidth
                                            Layout.fillHeight: parent
                                            color: "transparent"
                                            Text {
                                                text: model.content
                                                anchors.left: parent.left
                                                anchors.top: parent.top
                                                anchors.bottom: parent.bottom
                                                // anchors.centerIn: parent
                                                horizontalAlignment: Text.AlignLeft
                                                verticalAlignment: Text.AlignVCenter
                                                anchors.horizontalCenter: parent.horizontalCenter
                                                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                                font {
                                                    family: "Montserrat"
                                                    pixelSize: 14
                                                }
                                                color: Theme.current.textColor_Normal
                                            }
                                        }

                                        Rectangle {
                                            // border.color: "white"
                                            // border.width: 1
                                            id: rectTableContentScannedDate
                                            Layout.preferredWidth: rectDataTable.dateColumnWidth
                                            Layout.fillHeight: parent
                                            color: "transparent"
                                            Text {
                                                anchors.fill: parent
                                                text: model.scannedDay
                                                anchors.centerIn: parent
                                                horizontalAlignment: Text.AlignHCenter
                                                verticalAlignment: Text.AlignVCenter
                                                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                                font {
                                                    family: "Montserrat"
                                                    pixelSize: 14
                                                }
                                                color: Theme.current.textColor_Normal
                                            }
                                        }

                                        Rectangle {
                                            // border.color: "white"
                                            // border.width: 1
                                            id: rectTableContentScannedTime
                                            Layout.preferredWidth: rectDataTable.timeColumnWidth
                                            Layout.fillHeight: parent
                                            color: "transparent"
                                            Text {
                                                anchors.fill: parent
                                                text: model.scannedTime
                                                anchors.centerIn: parent
                                                horizontalAlignment: Text.AlignHCenter
                                                verticalAlignment: Text.AlignVCenter
                                                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                                font {
                                                    family: "Montserrat"
                                                    pixelSize: 14
                                                }
                                                color: Theme.current.textColor_Normal
                                            }
                                        }
                                        Rectangle {

                                            // border.color: "white"
                                            // border.width: 1
                                            id: rectTableContentPIC
                                            Layout.preferredWidth: rectDataTable.picColumnWidth
                                            Layout.fillHeight: parent
                                            color: "transparent"
                                            Text {
                                                anchors.fill: parent
                                                text: model.pic
                                                anchors.centerIn: parent
                                                horizontalAlignment: Text.AlignHCenter
                                                verticalAlignment: Text.AlignVCenter
                                                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                                                font {
                                                    family: "Montserrat"
                                                    pixelSize: 14
                                                }
                                                color: Theme.current.textColor_Normal
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
                /////
                Rectangle {
                    id: rectCameraViewPort
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.margins: 5
                    Layout.topMargin: 0
                    radius: 10
                    color: Theme.current.panelBackgroundColor_Normal

                    ColumnLayout {
                        id: columnLayoutRectCameraViewPort
                        anchors.fill: parent
                        Item {
                            Layout.fillHeight: true
                        }

                        Text {
                            id: textTitleCameraViewPort
                            text: qrScannerViewModel.selectedCamera
                                  || "No Camera selected!"
                            font {
                                family: "Montserrat"
                                pixelSize: 14
                                italic: true
                            }
                            color: Theme.current.textColor_Normal
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
                            border.color: Theme.current.buttonBorder_Actived
                            border.width: 1
                            color: "transparent"
                            clip: true

                            // Busy Indicator (centered)
                            BusyIndicator {
                                id: cameraBusyIndicator
                                anchors.centerIn: parent
                                running: qrScannerViewModel.isLoading
                                visible: qrScannerViewModel.isLoading
                            }

                            // Video Stream
                            VideoOutput {
                                id: videoOutput
                                anchors.fill: parent
                                clip: true
                                layer.smooth: true
                                fillMode: VideoOutput.PreserveAspectCrop
                                visible: qrScannerViewModel.isStreaming

                                Component.onCompleted: {
                                    qrScannerViewModel.setVideoSink(
                                        videoOutput.videoSink)
                                }
                            }

                            Rectangle {
                                anchors.centerIn: parent
                                visible: !qrScannerViewModel.isLoading
                                         && !qrScannerViewModel.isStreaming
                                color: Theme.current.panelBackgroundColor_Actived
                                Image {
                                    anchors.centerIn: parent
                                    source: "../Images/video-slash-solid.svg"
                                    fillMode: Image.PreserveAspectCrop
                                    height: 160
                                    width: 200
                                }
                            }
                        }

                        Rectangle {
                            id: rectLastedResultsQRCode
                            color: Theme.current.panelBackgroundColor_Actived
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
                                    color: Theme.current.textColor_Normal
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                                }

                                Text {
                                    id: textLastedQRCodeContent
                                    Layout.fillWidth: true
                                    Layout.fillHeight: true
                                    text: qrScannerViewModel.qrCodeDataLatest
                                          || "Unknow"
                                    font {
                                        family: "Montserrat"
                                        pixelSize: 16
                                    }
                                    leftPadding: 20
                                    color: Theme.current.textColor_Normal
                                    topPadding: 10
                                    horizontalAlignment: Text.AlignLeft
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
