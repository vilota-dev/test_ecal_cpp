#include <thread>

#include <ecal/ecal.h>
#include <ecal/msg/capnproto/subscriber.h>
#include <capnp/odometry3d.capnp.h>

void onOdometry(const char* topicName, ecal::Odometry3d::Reader msg, const long long tns) {
    auto pose = msg.getPose();
    auto position = pose.getPosition();
    auto orientation = pose.getOrientation();
    std::cout << "=====================" << std::endl;
    std::cout << "position:" << std::endl
              << "x: " << position.getX() << std::endl
              << "y: " << position.getY() << std::endl
              << "z: " << position.getZ() << std::endl
              << "orientation" << std::endl
              << "x: " << orientation.getX() << std::endl
              << "y: " << orientation.getY() << std::endl
              << "z: " << orientation.getZ() << std::endl
              << "w: " << orientation.getW() << std::endl;
}

int main(int argc, char **argv) {
    // Initialize eCAL
    eCAL::Initialize(argc, argv, "Odometry Subscriber");

    eCAL::capnproto::CSubscriber<ecal::Odometry3d> subscriber("S0/vio_odom");

    subscriber.AddReceiveCallback(
        std::bind(&onOdometry,
                  std::placeholders::_1,
                  std::placeholders::_2,
                  std::placeholders::_3));

    while (eCAL::Ok())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    // finalize eCAL API
    eCAL::Finalize();
}
