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
            id: mqg_console_output

            Layout.fillWidth: true
            Layout.fillHeight: true

            clip: true
            spacing: 20
            verticalLayoutDirection: ListView.BottomToTop

            Component {
                id: jobDelegate

                Job {
                    width: mqg_console_output.width
                }
            }

            model: ListModel { id: console_output_model }
            delegate: jobDelegate

            Component.onCompleted: {
                console_output_model.append({
                    command: "Any valid command",
                    log: [
                        // { msg: "1" },
                        // { msg: "2" },
                        // { msg: "3" }
                    ],
                    warning: [
                        { msg: "Division by zero" }
                    ],
                    error: undefined,
                    result: { x:12, y:23, message:"Ehi ma che ho!!!" }
                })
            }
        }
    }
}
