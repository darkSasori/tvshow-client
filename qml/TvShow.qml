import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    property alias listTvShows: listTvShows
    ListView {
        id: listTvShows
        anchors.fill: parent
        model: ListModel {
        }
        delegate: Item {
            x: 5
            width: parent.width
            height: 40
            Row {
                anchors.topMargin: 10
                anchors.rightMargin: 10
                id: row1
                width: parent.width
                height: parent.height
                spacing: 10
                anchors.fill: parent

                ToolButton {
                    iconSource: "../icon/info.png"
                    onClicked: {
                        info.item = model.modelData
                        root.currentIndex = 2
                    }
                }

                ToolButton {
                    iconSource: "../icon/play-button.png"
                    onClicked: {
                        udpsocket.play(model.modelData.net)
                    }
                }

                Text {
                    text: model.modelData.channel
                    font.bold: true
                    anchors.verticalCenter: parent.verticalCenter

                    MouseArea {
                        width: parent.width
                        height: parent.height
                    }
                }

                Text {
                    text: model.modelData.title
                    anchors.verticalCenter: parent.verticalCenter
                    MouseArea {
                        width: parent.width
                        height: parent.height
                    }
                }

            }
        }
    }

}
