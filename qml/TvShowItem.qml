import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.0
import QtQuick.Window 2.0

Item {
    id: tvShowItem
    x: 5
    width: parent.width
    height: 64
    visible: model.modelData.visible
    Layout.topMargin: 10
    Layout.rightMargin: 10

    RowLayout {
        id: row1
        height: 54
        anchors.left: parent.left
        anchors.right: parent.right
        spacing: 10

        ColumnLayout {
            spacing: 2
                anchors.fill: parent

            RowLayout {
                Layout.fillWidth: true
                anchors.fill: parent
                Image {
                    id: icon
                    source: "../icon/tap_and_play.png"
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            udpsocket.play(model.modelData)
                        }
                    }
                }

                ColumnLayout {
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    RowLayout {
                        Text {
                            id: channel
                            Layout.fillWidth: false
                            text: model.modelData.channel
                            font.bold: true
                            anchors.verticalCenter: parent.verticalCenter
                        }
                        MouseArea {
                            Layout.fillWidth: true
                            anchors.fill: parent
                            onClicked:{
                                stackMain.push(info)
                            }
                        }
                    }
                    RowLayout {
                        Text {
                            id: title
                            text: model.modelData.title
                            anchors.verticalCenter: parent.verticalCenter
                            wrapMode: Text.WordWrap
                            Layout.fillWidth: true
                        }
                        MouseArea {
                            Layout.fillWidth: true
                            anchors.fill: parent
                            onClicked:{
                                stackMain.push(info)
                            }
                        }
                    }
                }
            }
        }
    }
}
