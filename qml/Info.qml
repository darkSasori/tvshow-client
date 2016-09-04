import QtQuick 2.0
import QtQuick.Layouts 1.1

Item {
    id: info
    property var item: null

    RowLayout {
        id: rowHeader
        width: parent.width
        height: 500

        Image {
            Layout.topMargin: 10
            Layout.leftMargin: 10
            Layout.rightMargin: 30
            Layout.alignment: Qt.AlignTop
            source: "../icon/back.png"
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

        Item {
            Layout.fillWidth: true
        }
    }

    RowLayout {
        width: parent.width

        Text {
            text: item.start + " to " + item.end
            font.italic: true
            Layout.alignment: Qt.AlignTop
            Layout.topMargin: 45
            Layout.leftMargin: 50
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
