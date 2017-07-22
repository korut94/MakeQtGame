import QtQuick 2.9

Item {
    id: container

    property int        amount
    property Gradient   gradient
    property Gradient   gradientCounter
    property string     title

    height: content.height

    Rectangle {
        id: content

        anchors.fill: parent
        gradient: container.gradient
        height: msg.height

        Text {
            id: msg

            anchors.verticalCenter: parent.verticalCenter
            bottomPadding: topPadding
            color: "white"
            font.bold: true
            font.pointSize: 9
            leftPadding: 7
            text: title
            topPadding: 4.5
        }

        Badge {
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            gradient: gradientCounter
            content: Text {
                color: "#fafafa"
                font.bold: true
                padding: 1
                text: amount
            }
        }
    }
}
