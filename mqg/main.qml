import QtQuick          2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts  1.3
import QtQuick.Window   2.2

import mqg.Core         1.0
import mqg.GUI          1.0

Window {
    id: window

    title: "Make Qt Game"
    minimumWidth: 800
    minimumHeight: 600
    visible: true

    RowLayout {
        id: window_layout

        anchors.fill: parent

        Rectangle {
            id: mqg_world

            color: "red"

            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Console {
            id: mqg_console

            Layout.minimumWidth: 150
            Layout.preferredWidth: window.width / 3
            Layout.fillHeight: true
        }
    }

    Engine {
        onErrorOccurred: console.log(error)

        Component.onCompleted: {
            setGlobalObject("mqg_console", mqg_console);

            mqg_console.submit.connect(evaluate)
        }
    }
}
