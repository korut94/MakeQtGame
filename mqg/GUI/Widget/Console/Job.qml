import QtQuick 2.9
import QtQuick.Layouts 1.3

Item {
    id: container

    height: layout.height

    ColumnLayout {
        id: layout

        spacing: 0
        width: container.width

        Command { command: model.command; Layout.fillWidth: true }

        Rectangle {
            Layout.fillWidth: true

            color: "black"
            height: 2
        }

        Log { logMessages: model.log; Layout.fillWidth: true }

        Warning { warnMessages: model.warning; Layout.fillWidth: true }

        Loader {
            property alias container_width : layout.width
            property var model_error: model.error
            property var model_result: model.result

            Component {
                id: result

                Result { result: model_result; width: container_width }
            }

            Component {
                id: error

                Error { width: container_width }
            }

            sourceComponent: (model.error === undefined) ? result : error
        }
    }

    Rectangle {
        id: borderTop

        anchors.top: layout.top
        color: "#000000"
        height: 1
        width: layout.width
    }

    Rectangle {
        id: borderBottom

        anchors.top: layout.bottom
        color: "#000000"
        height: 1
        width: layout.width
    }
}
