#ifndef FOLLOWER_ROBOT_H
#define FOLLOWER_ROBOT_H

#include "enviro.h"
#include <string>

using namespace enviro;

class FollowerController : public Process, public AgentInterface {
  public:
    FollowerController() : Process(), AgentInterface(), leader_id(-1) {}
    void init();
    void start();
    void update();
    void stop();

    void set_leader_id(int id) { leader_id = id; }

  private:
    int leader_id;
    double t = 0;
    double desired_dist = 30;
    int current_target;
};

class FollowerRobot : public Agent {
  public:
    FollowerRobot(json spec, World& world);
  private:
    FollowerController fc;
};

DECLARE_INTERFACE(FollowerRobot)

#endif
