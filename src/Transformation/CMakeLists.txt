cmake_minimum_required(VERSION 3.8)
project(Transformation)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2 REQUIRED)

add_executable(staticTransform src/static_camera_transformation.cpp)
add_executable(dynamicTransform src/dynamic_transformation.cpp)
add_executable(listenerTransform src/listener_transformation.cpp)



ament_target_dependencies(staticTransform geometry_msgs rclcpp tf2_ros tf2)

ament_target_dependencies(dynamicTransform geometry_msgs rclcpp tf2_ros tf2)

ament_target_dependencies(listenerTransform geometry_msgs rclcpp tf2_ros tf2)


install(TARGETS
  staticTransform
  dynamicTransform
  listenerTransform
  DESTINATION lib/${PROJECT_NAME}
)




ament_package()
