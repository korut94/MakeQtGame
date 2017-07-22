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

        anchors.horizontalCenter: startPoint.left
        color: startPoint.color
        gradient: parent.gradient
        height: startPoint.height
        radius: width * 0.5
        width: height
    }

    Rectangle {
        id: cornerRight

        anchors.horizontalCenter: startPoint.right
        color: startPoint.color
        gradient: parent.gradient
        height: startPoint.height
        radius: width * 0.5
        width: height
    }

    Rectangle {
        id: startPoint

        color: parent.color
        gradient: parent.gradient
        height: content.height
        // The expression in `width` property resolves the no overlapping
        // content inequation:
        // content.width / 2 + distance <= corner.width / 2 +
        // startPoint.width / 2;
        // just putting the other parameter in the right side, changing
        // the direction and multipling both side twice:
        // startPoint.width >= content.width + 2 * distance - corner.width
        // Doing this the badge will grow itself to fit the content and leaving
        // a space equal to the `distance` value on the both sides.
        // A negative value can be occurred when the length of content plus the
        // `distance` value is strictly less than the corner side lenght, but
        // QML accepts negative value for the `width` property so nothing is
        // done to prevent it.
        // As seen in the expression above the choice of which corner taking
        // the width it's irrelevant because the inequation is equal for both
        // sides.
        width: content.width + 2 * distance - cornerLeft.width

        Item {
            anchors.centerIn: startPoint
            children: content
            height: content.height
            width: content.width
        }
    }
}
