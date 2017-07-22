import QtQuick 2.9

Item {
    id: container

    height: layout.height

    states: [
        State {
            name: "error"
            when: model.status === "error"

            PropertyChanges {
                target: status
                sourceComponent: error
            }
        },
        State {
            name: "success"
            when: model.status === "success"

            PropertyChanges {
                target: status
                sourceComponent: success
            }
        }
    ]

    Column {
        id: layout

        spacing: 0
        width: parent.width

        Command { state: container.state; width: parent.width }
        Loader { id: status }
        Log { width: parent.width }
        Warning { width: parent.width }

        Component { id: success; Result { width: layout.width } }
        Component { id: error; Error { width: layout.width } }
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
