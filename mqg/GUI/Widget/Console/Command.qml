import QtQuick 2.9

Rectangle {
    property string command

    height: title.height
    color: "#C0C0C0"

    Text {
        id: title

        bottomPadding: 5
        leftPadding: 5
        text: "<b> > </b> " + command
        topPadding: 5
    }
}
