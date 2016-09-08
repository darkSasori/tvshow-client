import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4

Item {
    id: info
    property var item: null

    ColumnLayout {
        anchors.fill: parent
        RowLayout {
            id: rowHeader
            width: parent.width
            height: iconBack.implicitHeight
            visible: item

            ToolButton {
                id: iconBack
                Layout.topMargin: 10
                Layout.leftMargin: 10
                Layout.rightMargin: 30
                Layout.alignment: Qt.AlignTop
                iconSource: "../icon/back.png"
                MouseArea {
                    anchors.fill: parent
                    onClicked: root.currentIndex = 1
                }
            }

            ColumnLayout {
                Layout.alignment: Qt.AlignVCenter
                Layout.fillWidth: true
                RowLayout {
                    Layout.fillWidth: true
                    Text {
                        text: item.channel
                        font.bold: true
                    }
                    Text {
                        text: qsTr("NET: " + item.net)
                    }
                }

                RowLayout {
                    Text {
                        text: item.title
                        Layout.alignment: Qt.AlignTop
                    }
                }
            }

            ToolButton {
                iconSource: "../icon/play-button.png"
                onClicked: {
                    udpsocket.play(item.net)
                }
            }

        }

        RowLayout {
            width: parent.width

            Text {
                text: item.period()
                font.italic: true
                Layout.alignment: Qt.AlignTop
                Layout.leftMargin: 10
            }

            Item {
                Layout.fillWidth: true
            }
        }

        RowLayout {
            Text {
                text: item.desc
                Layout.alignment: Qt.AlignTop
                Layout.leftMargin: 10
                wrapMode: Text.WordWrap
            Layout.fillHeight: true
            Layout.fillWidth: true
            }
        }
    }
}
