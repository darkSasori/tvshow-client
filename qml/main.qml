import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQml.Models 2.2
import QtQuick.Layouts 1.1

ApplicationWindow {
    id: main
    visible: true
    width: 640
    height: 480
    title: qsTr("Desktop Controller Client (" + tvshow.count + ")")

    property int listViewActive: 1

    toolBar: ToolBar {
        height: 31
        RowLayout {
            anchors.fill: parent
            ToolButton {
                iconName: "Servers"
                iconSource: "../icon/wifi-signal.png"
                onClicked: {
                    udpsocket.refresh();
                    root.currentIndex = 0
                }
            }

            ToolButton {
                iconName: "Refresh"
                iconSource: "../icon/refresh.png"
                onClicked: {
                    tvshow.now()
                    root.currentIndex = 1
                }
            }

            TextField {
                id: search
                height: parent.height
                width: 150
                style: TextFieldStyle {
                    background: Rectangle {
                        color: "white"
                        radius: 5
                        implicitWidth: parent.parent.width
                        implicitHeight: parent.parent.height
                        border.color: "#333"
                        border.width: 1
                    }
                }
                Keys.onReturnPressed: {
                }
            }

            ToolButton {
                iconSource: "../icon/search.png"
                onClicked: {
                }
            }


            Item {
                Layout.fillWidth: true
            }

            Text {
                Layout.alignment: Qt.AlignRight
                text: qsTr("Send to:")
                font.bold: true
            }

            Text {
                Layout.alignment: Qt.AlignRight
                text: udpsocket.current.name
            }
        }
    }

    ListView {
        id: root
        anchors.fill: parent
        snapMode: ListView.SnapOneItem
        highlightRangeMode: ListView.StrictlyEnforceRange
        highlightMoveDuration: 250
        focus: false
        orientation: ListView.Horizontal
        boundsBehavior: Flickable.StopAtBounds
        currentIndex: listViewActive
        onCurrentIndexChanged: {
        }

        model: ObjectModel{
            Servers {
                width: root.width
                height: root.height
                listServers.model: udpsocket.list
            }

            TvShow {
                width: root.width
                height: root.height
                listTvShows.model: tvshow.list
            }

            Info {
                id: info
                width: root.width
                height: root.height
            }
        }
    }
}
