cmake_minimum_required(VERSION 3.25)
project(test_ecal_cpp)

set(CMAKE_CXX_STANDARD 17)

find_package(eCAL 5.11.3 REQUIRED)
if(eCAL_FOUND)
    message(STATUS "eCAL FOUND, version:" ${eCAL_VERSION} ", directory: " ${eCAL_DIR})
endif()

set(CMAKE_FIND_LIBRARY_SUFFIXES ${CMAKE_STATIC_LIBRARY_SUFFIX})
find_package(CapnProto REQUIRED)
# include messages you'd like to use
set(CAPNPC_SRC_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}")
capnp_generate_cpp(CAPNP_SRCS CAPNP_HDRS
        thirdparty/ecal-common/src/capnp/header.capnp
        thirdparty/ecal-common/src/capnp/vector3.capnp
        thirdparty/ecal-common/src/capnp/imu.capnp
        thirdparty/ecal-common/src/capnp/image.capnp
        thirdparty/ecal-common/src/capnp/disparity.capnp
        thirdparty/ecal-common/src/capnp/so3.capnp
        thirdparty/ecal-common/src/capnp/se3.capnp
        thirdparty/ecal-common/src/capnp/detection2d.capnp
        thirdparty/ecal-common/src/capnp/cameracontrol.capnp
        thirdparty/ecal-common/src/capnp/cameraintrinsic.capnp
        thirdparty/ecal-common/src/capnp/sensorextrinsic.capnp
        thirdparty/ecal-common/src/capnp/twist3.capnp
        thirdparty/ecal-common/src/capnp/odometry3d.capnp
        thirdparty/ecal-common/src/capnp/vector2.capnp)

include_directories(
        ${CMAKE_CURRENT_BINARY_DIR}/thirdparty/ecal-common/src)

add_executable(test_ecal_cpp
        main.cpp
        ${CAPNP_SRCS}
        ${CAPNP_HDRS})
target_link_libraries(test_ecal_cpp
PRIVATE
CapnProto::capnp eCAL::core
)