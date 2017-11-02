import QtQuick          2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts  1.3

Item {
    signal submit(string command)

    function error(message) {

    }

    function log(message) {
        logger.append("<font color='grey'>" + message.text + "</font>")
    }

    function scriptException(error) {
        logger.append("<font color='red'>" + error.message + "</font>")
    }

    function scriptResult(result) {
        if (result !== undefined) {
            logger.append("<font color='blue'>" + result + "</font>")
        }
    }

    ColumnLayout {
        id: layout

        anchors.fill: parent

        ScrollView {
            id: view

            Layout.fillWidth: true
            Layout.maximumHeight: 100

            TextArea {
                id: commandInput

                placeholderText: qsTr("Insert command...")
                wrapMode: TextArea.Wrap

                Keys.onReturnPressed: {
                    logger.append("* " + commandInput.text)
                    submit(commandInput.text)
                    clear()
                }
            }
        }

        TextEdit {
            id: logger

            Layout.fillHeight: true
            Layout.fillWidth: true

            leftPadding: 5
            textFormat: TextEdit.RichText
            readOnly: true
            wrapMode: TextEdit.Wrap
        }
    }
}
