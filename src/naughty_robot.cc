// naughty_robot.cc
#include "naughty_robot.h"
#include <cmath>
#include <iostream>

using namespace std;

void NaughtyController::init() {
}

void NaughtyController::start() {
}

void NaughtyController::update() {

  t += 0.02; 
  double R = 200.0;
  double cx = 0.0;
  double cy = 0.0;

  double target_x = cx + R * cos(t);
  double target_y = cy + R * sin(t);

  move_toward(target_x, target_y, 75);
}

void NaughtyController::stop() {
}
