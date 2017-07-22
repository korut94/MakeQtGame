import QtQuick 2.9

Item {
    id: container

    readonly property var logMessages : model.log

    height: content.height

    Row {
        id: content

        spacing: 0
        width: parent.width

        Rectangle {
            id: border

            color: "#000099"
            height: logList.height
            width: 6
        }

        ListView {
            id: logList

            height: contentHeight
            model: logMessages
            width: parent.width - border.width

            delegate: Component {
                OutputLine {
                    color: "#bbbbff"
                    textColor: "#000066"
                    message: model.message
                    width: logList.width
                }
            }

            header: Header {
                amount: logMessages.count
                gradient: Gradient {
                    GradientStop { position: 0; color: "#4444ff" }
                    GradientStop { position: 1; color: "#2222bb" }
                }
                gradientCounter: Gradient {
                    GradientStop { position: 0; color: "#0000bb" }
                    GradientStop { position: 1; color: "#6666ff" }
                }
                title: "Logging"
                width: logList.width
            }
        }
    }
}
