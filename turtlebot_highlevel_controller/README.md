## Uebung 4.3

1. Launch-file ausführen.
`roslaunch turtlebot_highlevel_controller turtlebot_highlevel_controller.launch`

2. gmapping starten:
`rosrun gmapping slam_gmapping scan:=/scan _odom_frame:=odom`

3. Bewegen(z.b. über 2D Goal setzen in RVIZ)

4. Nachdem Karte ganz erkannt:
`rosrun map_server map_saver -f gmapping_map`

[Screenshots](https://github.com/nebendachs/mobile-roboter/tree/task3a/turtlebot_highlevel_controller/imgs)

![Image0](https://github.com/nebendachs/mobile-roboter/blob/task3a/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2011-50-55.png "Image 0")

![Image1](https://github.com/nebendachs/mobile-roboter/blob/task3a/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2011-49-02.png "Image 1")

![Image2](https://github.com/nebendachs/mobile-roboter/blob/task3a/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2011-49-07.png "Image 2")

![Image3](https://github.com/nebendachs/mobile-roboter/blob/task3a/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2011-49-15.png "Image 3")

![Image4](https://github.com/nebendachs/mobile-roboter/blob/task3a/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2011-49-27.png "Image 4")

![Image5](https://github.com/nebendachs/mobile-roboter/blob/task3a/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2011-50-55.png "Image 5")
