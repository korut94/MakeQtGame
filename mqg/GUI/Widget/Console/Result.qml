import QtQuick 2.9
import QtQuick.Layouts 1.3

Item {
    id: container

    property var result

    height: childrenRect.height

    states: State {
        name: "withResultValue"
        when: typeof container.result !== "undefined"

        PropertyChanges {
            target: alert
            Layout.bottomMargin: 0
            text: "<b>" + qsTr("Done") + "!</b> "
                  + qsTr("As result")
                  + " <i>" + typeof container.result + "</i>"
        }

        PropertyChanges {
            target: body_result
            visible: true
        }

        PropertyChanges {
            target: text_result
            text: JSON.stringify(container.result)
        }
    }

    RowLayout {
        spacing: 0
        width: parent.width

        Rectangle {
            id: border

            Layout.fillHeight: true
            Layout.preferredWidth: 6

            color: "#00c853"
        }

        Rectangle {
            Layout.fillWidth: true

            color: "#dff0d8"
            height: childrenRect.height

            ColumnLayout {
                id: content

                readonly property int margin: 7

                spacing: 3
                width: parent.width

                Text {
                    id: alert

                    Layout.fillWidth: true
                    Layout.margins: parent.margin

                    color: "#3c763d"
                    font.pointSize: 10
                    text: "<b>" + qsTr("Done") + "!</b>"
                }

                Rectangle {
                    id: body_result

                    // Don't show the item until a result value is proved
                    visible: false

                    Layout.bottomMargin: parent.margin
                    Layout.fillWidth: true
                    Layout.leftMargin: parent.margin
                    Layout.rightMargin: parent.margin

                    color: "#e8f5e9"
                    height: childrenRect.height
                    radius: 5

                    Text {
                        id: text_result

                        padding: 5
                        width: parent.width
                        wrapMode: Text.Wrap
                    }
                }
            }
        }
    }
}
