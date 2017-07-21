import QtQuick 2.9
import QtQuick.Layouts 1.3

Item {
    id: container

    property var warnMessages

    height: warnContent.contentHeight

    RowLayout {
        anchors.fill: parent
        spacing: 0

        Rectangle {
            id: border

            Layout.fillHeight: true
            Layout.preferredWidth: 6

            color: "#ff9800"
        }

        ListView {
            id: warnContent

            Layout.fillWidth: true

            height: contentHeight
            model: warnMessages

            delegate: Component {
                OutputLine {
                    backgroundColor: "#fffacd"
                    textColor: "#ff3f00"
                    message: model.msg
                    width: warnContent.width
                }
            }

            header: Header {
                amount: warnMessages.count
                gradient: Gradient {
                    GradientStop { position: 0; color: "#fdd835" }
                    GradientStop { position: 1; color: "#f9a825" }
                }
                gradientCounter: Gradient {
                    GradientStop { position: 0; color: "#ff6f00" }
                    GradientStop { position: 1; color: "#fdd835" }
                }
                title: "Warning"
                width: warnContent.width
            }
        }
    }
}
