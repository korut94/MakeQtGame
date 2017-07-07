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
                }
            }
        }

        ScrollView {
            id: mqg_view_console_log

            Layout.fillWidth: true
            Layout.fillHeight: true

            TextArea {
                id: mqg_console_log

                readOnly: true
                wrapMode: TextArea.Wrap
            }
        }
    }
}
