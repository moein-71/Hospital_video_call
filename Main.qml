import QtQuick

Window {
    id: window
    width: 1280
    height: 720
    visible: true
    title: qsTr("Hospital")
    color: "#222222"

    Rectangle {// width : 1000 , height : 505
        id : video_screen
        width: window.width / 128 * 100
        height : window.height / 72 * 50.5
        anchors.top: parent.top
        anchors.left: parent.left

        Text {
            id: what_click_now
            anchors.centerIn: parent
            text: backend.click
            font.pixelSize: 100
        }
    }

    Rectangle {
        width: window.width / 128 * 28
        height: window.height
        anchors.right : parent.right
        color: "#000033"
        Column {
            spacing : 20
            anchors.horizontalCenter: parent.horizontalCenter
            Rectangle {
                id : analog_clock
                width : window.width / 128 * 24
                height : window.height / 72 * 24 //
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top : parent.top
                anchors.topMargin: 15
                color : "#000033"

                Clock {}
            }
            Rectangle {
                id : digital_clock
                width : window.width / 128 * 24
                height : window.height / 72 * 8
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top : analog_clock.bottom
                anchors.topMargin: 10
                color : "#000033"

                Text {
                    anchors.centerIn: parent
                    text: currunt_time.time === "" ? "00:00:00" : currunt_time.time
                    font.pixelSize: 40
                    color: "white"
                }
            }
            Rectangle {
                id : show_date
                width : window.width / 128 * 24
                height : window.height / 72 * 8
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top : digital_clock.bottom
                anchors.topMargin: 0
                color : "#000033"

                Text {
                    anchors.centerIn: parent
                    text: currunt_time.date === "" ? "0000-00-00" : currunt_time.date
                    font.pixelSize: 40
                    color: "white"
                }
            }
            Rectangle {
                id : company
                width : window.width / 128 * 24
                height : window.height / 72 * 8
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top : show_date.bottom
                anchors.topMargin: 15
                color : "red"
            }
        }
    }

    Rectangle {
        width: window.width
        height: window.height / 72 * 21.5
        anchors.bottom: parent.bottom
        color: "#000033"

        Row {
            anchors.verticalCenter: parent.verticalCenter

            Rectangle {
                id: first_rec
                width : window.width / 128 * 36
                height : window.height / 72 * 18.5
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 15
                color : "#000033"

                Column {
                    spacing: 15
                    anchors.horizontalCenter: parent.horizontalCenter

                    Rectangle {
                        id: video_routing
                        width: window.width / 128 * 36
                        height: window.height / 72 * 8.5
                        anchors.horizontalCenter: parent.horizontalCenter
                        color : "white"
                        Text {
                            anchors.centerIn: parent
                            text: qsTr("Video Routing")
                            font.pixelSize: 40
                        }

                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                backend.click = "Video Routing"
                            }
                        }

                    }
                    Rectangle {
                        id: timer
                        width: window.width / 128 * 36
                        height: window.height / 72 * 8.5
                        anchors.horizontalCenter: parent.horizontalCenter
                        color : "darkgreen"
                    }
                }

                Rectangle {
                    id: second_rec
                    width : window.width / 128 * 36
                    height : window.height / 72 * 18.5
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: first_rec.right
                    anchors.leftMargin: 15
                    color : "#000033"

                    Column {
                        spacing: 15
                        anchors.horizontalCenter: parent.horizontalCenter

                        Rectangle {
                            id: video_conference
                            width: window.width / 128 * 36
                            height: window.height / 72 * 8.5
                            anchors.horizontalCenter: parent.horizontalCenter
                            color : "white"

                            Text {
                                anchors.centerIn: parent
                                text: qsTr("Video Conference")
                                font.pixelSize: 40
                            }

                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    backend.click = "Video Conferenceg"
                                }
                            }

                        }
                        Row {
                            spacing: 10
                            anchors.horizontalCenter: parent.horizontalCenter
                            // anchors.left: parent.left
                            // anchors.bottom: parent.bottom

                            Rectangle {
                                id: pacs_click
                                width: window.width / 128 * 17.5
                                height: window.height / 72 * 8.5
                                anchors.verticalCenter: parent.verticalCenter
                                color : "blue"

                                Text {
                                    anchors.centerIn: parent
                                    text: qsTr("PACS")
                                    font.pixelSize: 40
                                    color: "white"
                                }

                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: {
                                        backend.click = "PACS"
                                    }
                                }
                            }

                            Rectangle {
                                id: his_click
                                width: window.width / 128 * 17.5
                                height: window.height / 72 * 8.5
                                anchors.verticalCenter: parent.verticalCenter
                                color : "blue"

                                Text {
                                    anchors.centerIn: parent
                                    text: qsTr("HIS")
                                    font.pixelSize: 40
                                    color: "white"
                                }

                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: {
                                        backend.click = "HIS"
                                    }
                                }
                            }
                        }
                    }
                }
                Rectangle {
                    id: third_rec
                    width: window.width / 128 * 23.5
                    height: window.height / 72 * 18.5
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: second_rec.right
                    anchors.leftMargin: 15
                    color : "#000033"

                    Column {
                        spacing: 15
                        anchors.horizontalCenter: parent.horizontalCenter

                        Rectangle {
                            id: archiving
                            width: window.width / 128 * 23.5
                            height: window.height / 72 * 8.5
                            anchors.horizontalCenter: parent.horizontalCenter
                            color : "white"

                            Text {
                                anchors.centerIn: parent
                                text: qsTr("Archiving")
                                font.pixelSize: 40
                            }

                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    backend.click = "Archiving"
                                }
                            }

                        }
                        Rectangle {
                            id: next
                            width: window.width / 128 * 23.5
                            height: window.height / 72 * 8.5
                            anchors.horizontalCenter: parent.horizontalCenter
                            color : "darkred"

                            Text {
                                anchors.centerIn: parent
                                text: qsTr("Next")
                                font.pixelSize: 40
                                color: "white"
                            }

                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    backend.click = "Next"
                                }
                            }
                        }
                    }
                }
                Rectangle {
                    id: fourth_rec
                    width: window.width / 128 * 24.5
                    height: window.height / 72 * 18.5
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: third_rec.right
                    anchors.leftMargin: 15

                    color : "#000033"

                    Column {
                        spacing: 15
                        anchors.horizontalCenter: parent.horizontalCenter

                        Rectangle {
                            id: end_surgery
                            width: window.width / 128 * 24.5
                            height: window.height / 72 * 10.5
                            anchors.horizontalCenter: parent.horizontalCenter
                            color : "white"

                            Text {
                                anchors.centerIn: parent
                                text: qsTr("End Surgery")
                                font.pixelSize: 40
                            }

                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    backend.click = "End Surgery"
                                }
                            }

                        }

                        Row {
                            spacing: 15
                            anchors.horizontalCenter: end_surgery.horizontalCenter
                            // anchors.left: parent.left

                            Rectangle {
                                id: none_1
                                width: window.width / 128 * 11.5
                                height: window.height / 72 * 6.5
                                anchors.verticalCenter: parent.verticalCenter
                                color : "blue"

                                Text {
                                    anchors.centerIn: parent
                                    text: qsTr("<")
                                    font.pixelSize: 40
                                    color: "white"
                                }

                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: {
                                        backend.click = "none <"
                                    }
                                }
                            }

                            Rectangle {
                                id: none_2
                                width: window.width / 128 * 11.5
                                height: window.height / 72 * 6.5
                                anchors.verticalCenter: parent.verticalCenter
                                color : "blue"

                                Text {
                                    anchors.centerIn: parent
                                    text: qsTr(">")
                                    font.pixelSize: 40
                                    color: "white"
                                }

                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: {
                                        backend.click = "none >"
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
