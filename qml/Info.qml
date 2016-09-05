import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4

Item {
    id: info
    property var item: null

    RowLayout {
        id: rowHeader
        width: parent.width
        height: 500

        ToolButton {
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


        Text {
            text: item.channel
            font.bold: true
            Layout.alignment: Qt.AlignTop
            Layout.topMargin: 10
        }

        Text {
            text: item.title
            Layout.alignment: Qt.AlignTop
            Layout.topMargin: 10
        }

        ToolButton {
            iconSource: "../icon/play-button.png"
            Layout.alignment: Qt.AlignTop
            Layout.topMargin: 5
            onClicked: {
                udpsocket.play(item.net)
            }
        }

        Item {
            Layout.fillWidth: true
        }
    }

    RowLayout {
        width: parent.width

        Text {
            text: item.period()
            font.italic: true
            Layout.alignment: Qt.AlignTop
            Layout.topMargin: 45
            Layout.leftMargin: 50
        }

        Item {
            Layout.fillWidth: true
        }

        Text {
            text: qsTr("NET: " + item.net)
            Layout.alignment: Qt.AlignTop
            Layout.topMargin: 45
            Layout.rightMargin: 10
        }
    }

    RowLayout {
        width: parent.width

        Text {
            text: item.desc
            Layout.alignment: Qt.AlignTop
            Layout.topMargin: 70
            Layout.leftMargin: 10
            wrapMode: Text.WordWrap
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}
