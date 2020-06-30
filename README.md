 <h2>State Machine Diagram</h2>
<img src="https://github.com/reelrbtx/SMACC/blob/master/smacc_sm_reference_library/sm_packml/docs/smacc_state_machine_20200205-104849.dot.svg" width="950" align="center" border="10"/> 

<h2>Description</h2> This example demonstrates the use of both OpenCV and MoveBase within the same state machine, with cross orthogonal communication between the navigation orthogonal and the perception orthogonal.<br></br>
 
 <a href="https://reelrbtx.github.io/SMACC_Documentation/master/html/namespacesm__moveit.html">Doxygen Namespace & Class Reference</a> 
 
 <h2>Build Instructions</h2>
Before you build, make sure you've installed all the dependencies...

```
rosdep install --from-paths src --ignore-src -r -y 
```

Then you build with either catkin build or catkin make...

```
catkin build
```

<h2>Operating Instructions</h2>
After you build, remember to source the proper devel folder...

```
source ~/catkin_ws/devel/setup.bash
```

And then run the launch file...

```
roslaunch sm_opencv_2 sm_opencv_2.launch
```

<h2>Viewer Instructions</h2>
If you have the SMACC Viewer installed then type...

```
rosrun smacc_viewer smacc_viewer_node.py
``` 

If you don't have the SMACC Viewer installed, click <a href="http://smacc.ninja/smacc-viewer/">here</a> for instructions.

