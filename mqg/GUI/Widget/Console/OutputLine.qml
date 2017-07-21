import QtQuick 2.9

Rectangle {
    id: background

    property color backgroundColor
    property color borderColor
    property color textColor
    property string message

    color: backgroundColor
    height: msg.height

    Text {
        id: msg

        color: textColor
        font.pointSize: 12
        leftPadding: 10
        rightPadding: 20
        text: message
        width: background.width
        wrapMode: Text.Wrap
    }
}
