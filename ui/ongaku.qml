import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    width: 800
    height: 600
    visible: true
    title: qsTr("Scroll")

    ScrollView {
        anchors.fill: parent
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

        ListView {
            id: listView
            width: parent.width
            model: 20
            delegate: ItemDelegate {
                text: "Song " + (index + 1)
                width: listView.width
            }
        }
    }
}
