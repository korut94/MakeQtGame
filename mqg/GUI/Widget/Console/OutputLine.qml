import QtQuick 2.9

Rectangle {
    id: background

    property color textColor
    property string message

    height: msg.height

    Text {
        id: msg

        bottomPadding: topPadding
        color: textColor
        leftPadding: 5
        text: message
        topPadding: 3
        width: background.width
        wrapMode: Text.Wrap
    }
}
