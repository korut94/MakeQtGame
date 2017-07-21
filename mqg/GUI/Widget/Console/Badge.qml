import QtQuick 2.9

Item {
    property    color       color
    property    Gradient    gradient
    property    real        distance: 5
    property    Item        content

    height: childrenRect.height
    width: childrenRect.width

    Rectangle {
        id: cornerLeft

        anchors.horizontalCenter: body.left
        color: body.color
        gradient: parent.gradient
        height: body.height
        radius: width * 0.5
        width: height
    }

    Rectangle {
        id: cornerRight

        anchors.horizontalCenter: body.right
        color: body.color
        gradient: parent.gradient
        height: body.height
        radius: width * 0.5
        width: height
    }

    Rectangle {
        id: body

        color: parent.color
        gradient: parent.gradient
        height: content.height
        // TODO: write a explanation
        width: content.width + 2 * distance - height

        Item {
            anchors.centerIn: body
            children: content
            height: content.height
            width: content.width
        }
    }
}
