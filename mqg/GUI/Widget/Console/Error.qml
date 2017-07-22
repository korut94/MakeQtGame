import QtQuick 2.9
import QtQuick.Layouts 1.3

Item {
    id: container

    readonly property var error : model.error

    height: content.height

    RowLayout {
        anchors.fill: parent
        spacing: 0

        Rectangle {
            id: border

            Layout.fillHeight: true
            Layout.preferredWidth: 6

            color: "#dd0000"
        }

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true

            color: "#f2dede"

            Column {
                id: content

                padding: 7
                spacing: padding
                width: parent.width

                Row {
                    spacing: 5
                    width: parent.width

                    Text {
                        id: title

                        color: "#a94442"
                        text: "<b>" + container.error.name + "</b>: "
                    }

                    Text {
                        color: "#a94442"
                        text: container.error.message
                        width: parent.width
                               - parent.spacing
                               - title.width
                               - content.rightPadding
                        wrapMode: Text.WordWrap
                    }
                }

                Column {
                    spacing: 5
                    width: parent.width

                    Row {
                        spacing: 2
                        width: parent.width

                        Text {
                            id: lblLocation

                            color: "#a94442"
                            font.pointSize: 9
                            text: qsTr("Location") + ": "
                        }

                        Text {
                            color: "#a94442"
                            font.pointSize: 9
                            text: "<a href='#'>"
                                  + container.error.fileName + ":"
                                  + container.error.lineNumber
                                  + "</a>"
                            width: parent.width
                                   - parent.spacing
                                   - lblLocation.width
                                   - content.rightPadding
                                   - content.leftPadding
                            wrapMode: Text.WordWrap
                        }
                    }

                    Column {
                        spacing: 2
                        width: parent.width

                        Text {
                            color: "#a94442"
                            font.pointSize: 9
                            text: qsTr("Stack trace") + ": "
                        }

                        Rectangle {
                            color: "#ffebee"
                            height: stack.height
                            radius: 5
                            width: stack.width

                            Text {
                                id: stack

                                color: "#b71c1c"
                                padding: 5
                                text: container.error.stack
                                width: content.width
                                       - content.leftPadding
                                       - content.rightPadding
                                wrapMode: Text.WordWrap
                            }
                        }
                    }
                }
            }
        }
    }
}
