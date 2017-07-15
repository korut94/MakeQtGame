import QtQuick          2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts  1.3
import QtQuick.Window   2.2

import mqg.Core.Engine          1.0
import mqg.GUI.Widget.Console   1.0

Window {
    id: window

    title: "Make Qt Game"
    minimumWidth: 800
    minimumHeight: 600
    visible: true

    RowLayout {
        id: window_layout

        spacing: 0

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
        id: engine

        env: Environment {
            readonly property var close: function () { window.close() }
            readonly property var out: mqg_console
            readonly property var window: window
        }

        onErrorOccurred: console.log(error)

        Component.onCompleted: {
            mqg_console.submit.connect(evaluate)

            loadEnvironment()
        }
    }
}
