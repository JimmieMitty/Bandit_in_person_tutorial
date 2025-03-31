# Bandit Tutorial

![Bandit the Gamer](./bandit.jpeg)  

## Description
This repository is designed for Capstone students to learn the basics of ROS and Bandit.

# Getting Started
## Understanding the File Structure 
The ROS Noetic file structure with Catkin for the `tutorial` workspace and the `bandit_tutorials` package typically includes the following:

- **src/**: Contains the source code for your packages, including `bandit_tutorials`.
- **CMakeLists.txt**: A configuration file for building your packages using CMake.
- **package.xml**: Defines package metadata such as dependencies and versioning.
- **devel/**: A workspace where built files are stored temporarily during development.
- **build/**: Contains intermediate build files.
- **install/**: Stores the final installed files after building.

### Optional: Creating the Workspace and Package
To create the `tutorial` Catkin workspace and the `bandit_tutorials` package, follow these steps:
1. Create a directory for your workspace:  
    ```bash
    mkdir -p ~/tutorial/src
    ```
2. Navigate to the workspace:  
    ```bash
    cd ~/tutorial/
    ```
3. Initialize the workspace:  
    ```bash
    catkin_make
    ```
4. Navigate to the `src` directory:  
    ```bash
    cd src
    ```
5. Create the `bandit_tutorials` package:  
    ```bash
    catkin_create_pkg bandit_tutorials std_msgs rospy roscpp
    ```

This structure helps organize and build ROS packages efficiently.

Inside the `tutorial` workspace, within the `bandit_tutorials` package, you should find two files: `cmd_vel_publish_c.cpp` and `cmd_vel_publish.py`. These files contain basic code to publish messages to a specific ROS topic called `/mobile_base_controller/cmd_vel`. 

To verify the existence of this topic, use the development PC or SSH into Bandit and run:
```bash
rostopic list
```

## Running Test Code
In this example, we'll run the Python file `cmd_vel_publish.py`. Follow these instructions to upload and execute the file:

1. Sync your code to Bandit:  
    ```bash
    ./sync.sh
    ```
2. SSH into Bandit:  
    ```bash
    ssh pal@bandit
    ```
3. Navigate to the directory:  
    ```bash
    cd /Tutorials/tutorial
    ```
4. Build your files (especially if using C++):  
    ```bash
    catkin_make
    ```
5. Source your built files:  
    ```bash
    source ./devel/setup.bash
    ```
6. Run the code:  
    ```bash
    rosrun bandit_tutorials cmd_vel_publish.py
    ```