import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

ApplicationWindow {
    id: main
    visible: true
    width: 640
    height: 480
    title: qsTr("Desktop Controller Client (" + tvshow.count + ")")
    property bool loading: false

    header: ToolBar {
        id: header
        ToolButton {
            id: backButton
            width: opacity ? 60 : 0
            Behavior on opacity { NumberAnimation{} }
            opacity: stackMain.depth > 1 && !loading ? 1 : 0
            Image {
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                source: "../icon/arrow_back.png"
            }
            onClicked: {
                stackMain.pop()
            }
        }

        Text {
            Behavior on x { NumberAnimation{ easing.type: Easing.OutCubic} }
            x: backButton.x + backButton.width + 20
            anchors.verticalCenter: parent.verticalCenter
            color: "white"
            text: main.title
        }
    }

    StackView {
        id: stackMain
        anchors.fill: parent
        initialItem: swipe
        anchors.margins: 10

        SwipeView {
            id: swipe
            currentIndex: 1
            spacing: 10
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            Servers {
                listServers: udpsocket.list
            }

            TvShow {
                id: tvShowList
                listTvShows: tvshow.list
            }
        }

    }

    Component {
        id: componentLoading
        Item {
            BusyIndicator {
                id: busy
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }

    Component {
        id: info
        Info {
        }
    }

    Connections{
        target: tvshow
        onStartLoading: {
            loading = true
            stackMain.push(componentLoading)
        }
        onEndLoading: {
            loading = false
            stackMain.pop();
        }
    }
}
