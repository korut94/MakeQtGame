import QtQuick 2.9
import QtQuick.Layouts 1.3

Item {
    id: container

    readonly property var result : model.result

    height: content.height

    states: State {
        name: "withResultValue"
        when: typeof container.result !== "undefined"

        PropertyChanges {
            target: alert
            text: "<b>" + qsTr("Done") + "!</b> "
                  + qsTr("Result") + ": "
                  + "<i>" + typeof container.result + "</i>"
        }

        PropertyChanges {
            target: load
            sourceComponent: text_result
        }
    }

    RowLayout {
        anchors.fill: parent
        spacing: 0

        Rectangle {
            id: border

            Layout.fillHeight: true
            Layout.preferredWidth: 6

            color: "#00c853"
        }

        Rectangle {
            Layout.fillHeight: true
            Layout.fillWidth: true

            color: "#dff0d8"

            Column {
                id: content

                padding: 7
                spacing: 3
                width: parent.width

                Text {
                    id: alert

                    color: "#3c763d"
                    font.pointSize: 10
                    text: "<b>" + qsTr("Done") + "!</b>"
                }

                Loader { id: load }

                Component {
                    id: text_result

                    Rectangle {
                        color: "#e8f5e9"
                        height: result.height
                        radius: 5
                        width: result.width

                        Text {
                            id: result

                            color: "#1b5e20"
                            padding: 5
                            text: stringify(container.result)
                            width: content.width
                                   - content.leftPadding
                                   - content.rightPadding
                            wrapMode: Text.Wrap
                        }
                    }
                }
            }
        }
    }

    function stringify(value) {
        if (typeof value !== "object") {
            return String(value)
        } else {
            return JSON.stringify(value, null, 4).replace(/\"(.*)\":/g, "$1:")
        }
    }
}
