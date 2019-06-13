## Uebung 4.3

1. Launch-file ausführen.
`roslaunch turtlebot_highlevel_controller turtlebot_highlevel_controller.launch`

2. gmapping starten:
`rosrun gmapping slam_gmapping scan:=/scan _odom_frame:=odom`

3. Bewegen(z.b. über 2D Goal setzen in RVIZ)

4. Nachdem Karte ganz erkannt:
`rosrun map_server map_saver -f gmapping_map`

[Screenshots](https://github.com/nebendachs/mobile-roboter/tree/task3/turtlebot_highlevel_controller/imgs)

![Image0](https://github.com/nebendachs/mobile-roboter/blob/task4/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2011-32-06.png "Image 0")

![Image1](https://github.com/nebendachs/mobile-roboter/blob/task4/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2011-34-30.png "Image 1")

![Image2](https://github.com/nebendachs/mobile-roboter/blob/task4/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2011-34-39.png "Image 2")

![Image3](https://github.com/nebendachs/mobile-roboter/blob/task4/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2011-34-45.png "Image 3")

![Image4](https://github.com/nebendachs/mobile-roboter/blob/task4/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2011-34-52.png "Image 4")

![Image5](https://github.com/nebendachs/mobile-roboter/blob/task4/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2011-35-00.png "Image 5")
