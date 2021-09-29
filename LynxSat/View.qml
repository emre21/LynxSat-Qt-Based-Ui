import QtQuick 2.0

import QtLocation 5.6
import QtPositioning 5.6
import QtQuick3D 1.15
Item {
    id : root
    property real map_X: 40.218010
    property real map_Y: 28.881287
    property real render_euler_1:0.0
    property real render_euler_2:0.0
    property real render_euler_3:0.0


Rectangle
{
    id : mapRect
    width: parent.width/2
    height: parent.height
    visible: true

    Plugin {
        id: mapPlugin
        name: "esri" // "mapboxgl", "esri", ...
        // specify plugin parameters if necessary
        // PluginParameter {
        //     name:
        //     value:
        // }
    }

    Map {

        MapCircle{
            center: QtPositioning.coordinate(map_X, map_Y)
            color: "red"
            radius: 30
        }

        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(map_X, map_Y) // Oslo
        zoomLevel: 14
    }

}
    Rectangle{
        id: viewRect
        x : mapRect.width
        y : 0
        width: parent.width/2
        height: parent.height

        View3D
        {
            Text {
                id: state
                text: qsTr("STATE : STABLE\nROLL  : \nPITCH  : \nYAW : \n")
                //text: qsTr(render_euler_1)+"\n"+qsTr(render_euler_2)+"\n"+qsTr(render_euler_3)
                color: "red"
            }
            anchors.fill: parent
            environment: SceneEnvironment{
                clearColor: "skyblue"
            }


            PerspectiveCamera {
                position: Qt.vector3d(0, 0, 300) // 0 , 200, 300
                eulerRotation.x: 0 // -30
            }


            DirectionalLight {
                eulerRotation.x: -30
                eulerRotation.y: -70
            }


            Model {
                position: Qt.vector3d(0, 0, 0)
                source: "#Cylinder"
                scale: Qt.vector3d(1.2, 2, 1.2)
                materials: [ DefaultMaterial {
                        diffuseColor: "grey"
                    }
                ]
                eulerRotation: Qt.vector3d(render_euler_1,render_euler_2,render_euler_3)
            }



        }
    }

}
