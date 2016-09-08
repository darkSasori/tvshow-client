import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4

Item {
    property alias listTvShows: listTvShows

    Layout.bottomMargin: 10

    ListView {
        id: listTvShows
        anchors.fill: parent
        model: ListModel {
        }
        delegate: Item {
            x: 5
            width: model.modelData.visible ? parent.width : 0
            height: model.modelData.visible ? row1.implicitHeight + 10 : 0
            visible: model.modelData.visible
            Layout.topMargin: 10
            Layout.rightMargin: 10

            RowLayout {
                id: row1
                width: parent.width
                height: title.implicitHeight + channel.implicitHeight
                spacing: 10
                anchors.fill: parent

                RowLayout {
                    ToolButton {
                        id: iconPlay
                        iconSource: "../icon/play-button.png"
                        onClicked: {
                            udpsocket.play(model.modelData.net)
                        }
                    }
                }

                ColumnLayout {
                    spacing: 2

                    RowLayout {
                        Text {
                            id: channel
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            text: model.modelData.channel
                            font.bold: true
                            anchors.verticalCenter: parent.verticalCenter
                            MouseArea {
                                width: parent.width
                                height: parent.height
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
                            Layout.fillHeight: true
                            MouseArea {
                                width: parent.width
                                height: parent.height
                            }
                        }
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            info.item = model.modelData
                            root.currentIndex = 2
                        }
                    }
                }

            }
        }
    }
}
