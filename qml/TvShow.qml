import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Item {
    property alias listTvShows: listTvShows.model
//    property alias stack: stack

//    StackView {
//        id: stack
//        anchors.fill: parent
//        initialItem: listTvShows

        ListView {
        anchors.fill: parent
            id: listTvShows
            model: ListModel {
            }
            delegate: TvShowItem {
//                MouseArea {
//                    anchors.fill: parent
//                    onClicked:{
//                        stackMain.push(info)
//                    }
//                }
            }
            onMovementEnded: {
                if (listTvShows.contentY <= 0) {
                    tvshow.now();
                }
            }
        }
//    }
}
