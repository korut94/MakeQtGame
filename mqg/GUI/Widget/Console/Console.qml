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
                    command: "mqg.window.setShowFullScreen()",
                    log: [
                        { message: "1 smfsdpmfmpsdomfsdopfmsdpofmsdpofmsdpofmspdo" },
                        { message: "2" },
                        { message: "3" }
                    ],
                    warning: [
                        { message: "Division by zero" }
                    ],
                    status: "error",
                    error: {
                        name: "SyntaxError",
                        message: "Expected token `identifier`",
                        fileName: "file:///home/andreamnt94/Project/MakeQtGame/build-MakeQtGame-Desktop-Profile/mqg/GUI/Widget/Console/Console.qml",
                        lineNumber: 1,
                        stack: "file:///home/andreamnt94/Project/MakeQtGame/build-MakeQtGame-Desktop-Profile/mqg/GUI/Widget/Console/Console.qml"
                    },
                    result: "(90 + 34 * 76) / 2  = " + (90 + 34 * 76) / 2
                })
            }
        }
    }
}
