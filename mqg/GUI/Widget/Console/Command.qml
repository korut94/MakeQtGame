import QtQuick 2.9

Rectangle {
    id: background

    height: title.height

    states: [
        State {
            name: "error"
            PropertyChanges {
                target: background
                color: "#dd0000"
            }
        },
        State {
            name: "success"
            PropertyChanges {
                target: background
                color: "#00c853"
            }
        }
    ]

    Text {
        id: title

        color: "white"
        font.weight: Font.DemiBold
        padding: 5
        width: parent.width
        text: model.command
        wrapMode: Text.Wrap
    }
}
