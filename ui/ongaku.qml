import QtQuick 2.15
import QtQuick.Controls 2.15
import Models.SongList 1.0

ApplicationWindow {
    width: 800
    height: 600
    visible: true
    title: qsTr("ONGAKU")

    ScrollView {
        anchors.fill: parent
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

        ListView {
            id: listView
            width: parent.width
            model: SongListModel
            delegate: ItemDelegate {
                width: listView.width

                Label  {
                text: model.text
                color: model.color
                }
            }
        }
    }
}
