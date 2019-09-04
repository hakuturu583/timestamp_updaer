cmake_minimum_required(VERSION 2.8.3)
project(timestamp_updater)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  nav_msgs
  sensor_msgs
)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES timestamp_updater
  CATKIN_DEPENDS roscpp nav_msgs sensor_msgs
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(timestamp_updater_node src/timestamp_updater.cpp src/timestamp_updater_node.cpp)
target_link_libraries(timestamp_updater_node ${catkin_LIBRARIES})

# install executables/libs
install(TARGETS timestamp_updater_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

# install headers
install(DIRECTORY include
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)

install(DIRECTORY launch
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
        USE_SOURCE_PERMISSIONS)