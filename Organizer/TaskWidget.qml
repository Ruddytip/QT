import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.3
import FileInfoSave 1.0

GridLayout{
    columns: 4
    rows: 2
    FileInfoSave{
        id: file
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
        id: count_tsk
        text: qsTr("(" + file.getCountTasks() + " Задач)")
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
            if(file.addTask(taskName.text, taskDate.text, combo.currentText)){
                taskName.text = ""
                taskDate.text = ""
                combo.currentIndex = 0
                count_tsk.text = qsTr("(" + file.getCountTasks() + " Задач)")
            }
        }
    }
}
