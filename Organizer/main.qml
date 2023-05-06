import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    visible: true
    title: qsTr("Organizer")
    property int sizeBorder: 10

    TaskWidget{
        id: id_taskWidget
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: sizeBorder
        anchors.leftMargin: sizeBorder
    }

    minimumHeight: id_taskWidget.height + sizeBorder * 2
    minimumWidth: id_taskWidget.width + sizeBorder * 2
    maximumHeight: id_taskWidget.height + sizeBorder * 2
    maximumWidth: id_taskWidget.width + sizeBorder * 2
}
