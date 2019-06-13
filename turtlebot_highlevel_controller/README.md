## Uebung 4.5

1. Launch-file ausführen.
`roslaunch turtlebot_highlevel_controller turtlebot_highlevel_controller_rosbag.launch`

2. gmapping starten:
`rosrun gmapping slam_gmapping scan:=/scan _odom_frame:=odom`

3. Rosbag-file abspielen:
`rosbag play bagfiles/mapping.bag`

4. Nachdem 3. fertig ist Karte unter /maps speichern:
`rosrun map_server map_saver -f gmapping_map_rosbag`

Hinweis: Der Roboter ist auf den Screenshots nicht zu sehen.

[Screenshots](https://github.com/nebendachs/mobile-roboter/tree/task5/turtlebot_highlevel_controller/imgs)

![Image0](https://github.com/nebendachs/mobile-roboter/blob/task5/turtlebot_highlevel_controller/maps/gmapping_map_rosbag.pgm "Image 0")

![Image1](https://github.com/nebendachs/mobile-roboter/blob/task5/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2010-50-08.png "Image 1")

![Image2](https://github.com/nebendachs/mobile-roboter/blob/task5/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2010-50-17.png "Image 2")

![Image3](https://github.com/nebendachs/mobile-roboter/blob/task5/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2010-50-24.png "Image 3")

![Image4](https://github.com/nebendachs/mobile-roboter/blob/task5/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2010-50-31.png "Image 4")

![Image5](https://github.com/nebendachs/mobile-roboter/blob/task5/turtlebot_highlevel_controller/imgs/Bildschirmfoto%20vom%202019-06-13%2010-50-38.png "Image 5")
