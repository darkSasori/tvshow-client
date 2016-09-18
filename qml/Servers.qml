import QtQuick 2.0

Item {
    property alias listServers: listServers.model
    ListView {
        id: listServers
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
                spacing: 10

                Text {
                    text: model.modelData.name
                    font.bold: true
                    anchors.verticalCenter: parent.verticalCenter

                }
            }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            udpsocket.current = model.modelData
                        }
                    }
        }
        onMovementEnded: {
            if (listServers.contentY <= 0) {
                udpsocket.refresh();
            }
        }
    }

}
