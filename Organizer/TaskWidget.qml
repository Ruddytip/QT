import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.3

GridLayout{
    columns: 4
    rows: 2
    property string fileName: "file:///D:/Develop/Source/QT/Tasks.txt"
    property string textData: ""

    function openFile(fileUrl) {
        var request = new XMLHttpRequest();
        request.open("GET", fileUrl, false);
        request.send(null);
        return request.responseText;
    }

    function saveFile(fileUrl, text) {
        var request = new XMLHttpRequest();
        request.open("PUT", fileUrl, false);
        request.send(text);
        return request.status;
    }

    Text{
        text: qsTr("Название задачи")
        Layout.column: 0
        Layout.row: 0
    }
    Text{
        text: qsTr("Дата выполнения")
        Layout.column: 1
        Layout.row: 0
    }
    Text{
        text: qsTr("Прогресс выполнения")
        Layout.column: 2
        Layout.row: 0
    }
    Text{
        text: qsTr("")
        Layout.column: 3
        Layout.row: 0
    }
    TextField{
        id: taskName
        Layout.column: 0
        Layout.row: 1
        placeholderText: qsTr("Укажите название")
    }
    TextField {
        id: taskDate
        Layout.column: 1
        Layout.row: 1
        placeholderText: qsTr("dd.mm.yyyy")
    }
    ComboBox {
        id: combo
        Layout.column: 2
        Layout.row: 1
        model: ListModel {
            id: model
            ListElement { text: "0" }
            ListElement { text: "1" }
            ListElement { text: "2" }
            ListElement { text: "3" }
            ListElement { text: "4" }
            ListElement { text: "5" }
            ListElement { text: "6" }
            ListElement { text: "7" }
            ListElement { text: "8" }
            ListElement { text: "9" }
            ListElement { text: "10" }
        }
    }
    Button {
        Layout.column: 3
        Layout.row: 1
        text: "Создать"
        onClicked: {
            textData = openFile(fileName)
            textData += taskName.text + ": "
            textData += taskDate.text + " -> "
            textData += combo.currentText + "/10\n"
            saveFile(fileName, textData)
        }
    }
}
