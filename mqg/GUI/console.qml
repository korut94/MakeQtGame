import QtQuick          2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts  1.3

Item {
    signal submit(string command)

    ColumnLayout {
        id: mqg_console_layout

        anchors.fill: parent

        ScrollView {
            id: mqg_view_console_input

            Layout.fillWidth: true
            Layout.maximumHeight: 100

            TextArea {
                id: mqg_console_input

                placeholderText: qsTr("Insert command...")
                wrapMode: TextArea.Wrap

                Keys.onReturnPressed: {
                    mqg_console.submit(mqg_console_input.text)
                    clear()
                }
            }
        }

        ListView {
            id: mqg_view_console_log

            Layout.fillWidth: true
            Layout.fillHeight: true

            spacing: 5

            model: ListModel {
                ListElement {
                    message: "ci siamo"
                    type: "debug"
                }

                ListElement {
                    message: "era orasssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss"
                    type: "error"
                }
            }

            delegate: Rectangle {
                id: background

                color: "#FF9999"
                width: mqg_view_console_log.width
                height: msg.height

                Row {
                    Rectangle {
                        color: "#FF3333"
                        height: msg.height
                        radius: 2
                        width: 12
                    }

                    Text {
                        id: msg

                        color: "#550000"

                        font.pointSize: 11
                        leftPadding: 10
                        rightPadding: 20
                        text: message
                        width: background.width
                        wrapMode: Text.Wrap
                    }
                }
            }
        }
    }
}
