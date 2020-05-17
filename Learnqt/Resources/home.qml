import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Item {
    id: item
    Button{
        text: "this is a button"
    }
}

//ApplicationWindow {
//    visible: true
//    width: 640
//    height: 480
//    title: qsTr("Tabs")
//    function showRadio(){
//        console.log(first.checked, second.checked, third.checked)
//    }

//    ColumnLayout {
//        CheckBox{
//            checked: false
//            text: qsTr("性别")
//            onClicked: {
//                console.log("clicked" + checked)
//            }
//            onCheckedChanged: {
//                console.log("changed : " + checked)
//            }
//        }

//        RadioButton{
//            id: first
//            text: "一年级"
//            onClicked: {
//                showRadio()
//            }
//        }



//        RadioButton{
//            id: second
//            text: "二年级"
//            onClicked: {
//                showRadio()
//            }

//        }

//        RadioButton{
//            id: third
//            text: "三年级"
//            onClicked: {
//                showRadio()
//            }
//        }

//        DelayButton{
//            text: "delay button"
//            delay: 3000
//            onProgressChanged: {
//                showRadio()
//            }
//        }
//        Button {
//            id : testBtn
//            text: "test"
//            x: 10
//            y: 10
//            onClicked: {
//                aaa()
//            }
//        }

//        Button {
//            text: "this is a label"
//            width: 500
//        }

//    }
//    property string name: "value"

//    function aaa(){
//        console.log(name);
//    }
//}
