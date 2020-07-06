#include <iostream>
#include "abb_librws/rws_interface.h"

int main(int argc, char** argv)
{
  //----------------------------------------------------------
  // Preparations
  //----------------------------------------------------------
  // Retrive the ROS parameter for the RWS server's IP-address.
  std::string rws_ip_address = "192.168.10.254";

  // Create a RWS interface:
  // * Sets up a RWS client (that can connect to the robot controller's RWS server).
  // * Provides APIs to the user (for accessing the RWS server's services).
  //
  // Note: It is important to set the correct IP-address here, to the RWS server.
  abb::rws::RWSInterface rws_interface(rws_ip_address);

  //----------------------------------------------------------
  // Collect info from the robot controller
  //----------------------------------------------------------
  std::cout << "========== Collecting info sample ==========" << std::endl;

  // Read status signals.
  std::cout << "Auto mode: " << rws_interface.isAutoMode() << std::endl;
  std::cout << "Motor on: " << rws_interface.isMotorOn() << std::endl;
  std::cout << "RAPID running: " << rws_interface.isRAPIDRunning() << std::endl;

  while(true)
  {
    // Read current jointtarget.
    abb::rws::JointTarget current_jointtarget;
    if (rws_interface.getMechanicalUnitJointTarget("ROB_1", &current_jointtarget))
    {
      std::cout << "Current jointtarget: " << current_jointtarget.constructString() << std::endl;
      sleep(1);
    }
  }

  while (true)
  {
    // Read current robtarget.
    abb::rws::RobTarget current_robtarget;
    if (rws_interface.getMechanicalUnitRobTarget("ROB_1", &current_robtarget))
    {
      std::cout << "Current robtarget: " << current_robtarget.constructString() << std::endl;
      sleep(1);
    }
  }

  return 0;
}
