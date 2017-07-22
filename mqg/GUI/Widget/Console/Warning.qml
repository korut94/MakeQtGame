import QtQuick 2.9

Item {
    id: container

    readonly property var warningMessages : model.warning

    height: content.height

    Row {
        id: content

        spacing: 0
        width: parent.width

        Rectangle {
            id: border

            color: "#ff9800"
            height: warningList.height
            width: 6
        }

        ListView {
            id: warningList

            height: contentHeight
            model: warningMessages
            width: parent.width - border.width

            delegate: Component {
                OutputLine {
                    color: "#fffacd"
                    textColor: "#ff3f00"
                    message: model.message
                    width: warningList.width
                }
            }

            header: Header {
                amount: warningMessages.count
                gradient: Gradient {
                    GradientStop { position: 0; color: "#fdd835" }
                    GradientStop { position: 1; color: "#f9a825" }
                }
                gradientCounter: Gradient {
                    GradientStop { position: 0; color: "#ff6f00" }
                    GradientStop { position: 1; color: "#fdd835" }
                }
                title: "Warning"
                width: warningList.width
            }
        }
    }
}
