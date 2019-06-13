## Uebung 4.3

1. Launch-file ausführen.
`roslaunch turtlebot_highlevel_controller turtlebot_highlevel_controller.launch`

2. Über *action_topic* Ziel-Position (3, 1, 0) angeben:
`rostopic pub /action_topic turtlebot_highlevel_controller/ActionMessage '{cancel: false, target: {x: 3.0, y: 1.0, z: 0.0}}'`

3. Über *action_topic* Ziel-Position (-4, 0, 0) angeben:
`rostopic pub /action_topic turtlebot_highlevel_controller/ActionMessage '{cancel: false, target: {x: -4.0, y: 0.0, z: 0.0}}'`

4. Über *action_topic* action abbrechen:
`rostopic pub /action_topic turtlebot_highlevel_controller/ActionMessage '{cancel: true, target: {x: 0.0, y: 0.0, z: 0.0}}'`

[Screenshots](https://github.com/nebendachs/mobile-roboter/tree/task2/turtlebot_highlevel_controller/imgs)

![Image0](https://github.com/nebendachs/mobile-roboter/blob/task2/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2013-37-42.png "Image 0")

![Image1](https://github.com/nebendachs/mobile-roboter/blob/task2/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2013-37-47.png "Image 1")

Nach Befehl 2:
![Image2](https://github.com/nebendachs/mobile-roboter/blob/task2/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2013-40-32.png "Image 2")

![Image3](https://github.com/nebendachs/mobile-roboter/blob/task2/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2013-40-28.png "Image 3")

![Image4](https://github.com/nebendachs/mobile-roboter/blob/task2/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2013-40-44.png "Image 4")

Nach Befehl 3:
![Image5](https://github.com/nebendachs/mobile-roboter/blob/task2/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2013-42-48.png "Image 5")

Nach Befehl 4:
![Image6](https://github.com/nebendachs/mobile-roboter/blob/task2/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2013-43-10.png "Image 6")

![Image7](https://github.com/nebendachs/mobile-roboter/blob/task2/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2013-43-05.png "Image 7")
