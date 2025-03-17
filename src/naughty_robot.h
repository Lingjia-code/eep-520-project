// naughty_robot.h
#ifndef NAUGHTY_ROBOT_H
#define NAUGHTY_ROBOT_H

#include "enviro.h"

using namespace enviro;

class NaughtyController : public Process, public AgentInterface {
  public:
  NaughtyController() : Process(), AgentInterface() {}
    void init();
    void start();
    void update();
    void stop();
  private:
    double t = 0;
};

class NaughtyRobot : public Agent {
  public:
  NaughtyRobot(json spec, World& world) : Agent(spec, world) {
      add_process(lc);
    }
  private:
    NaughtyController lc;
};

DECLARE_INTERFACE(NaughtyRobot)

#endif
