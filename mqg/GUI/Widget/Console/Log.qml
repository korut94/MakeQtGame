import QtQuick 2.9
import QtQuick.Layouts 1.3

Item {
    id: container

    property var logMessages

    height: logContent.contentHeight

    RowLayout {
        anchors.fill: parent
        spacing: 0

        Rectangle {
            id: border

            Layout.fillHeight: true
            Layout.preferredWidth: 6

            color: "#000099"
        }

        ListView {
            id: logContent

            Layout.fillWidth: true

            height: contentHeight
            model: logMessages

            delegate: Component {
                OutputLine {
                    backgroundColor: "#bbbbff"
                    textColor: "#000066"
                    message: model.msg
                    width: logContent.width
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
                width: logContent.width
            }
        }
    }
}
