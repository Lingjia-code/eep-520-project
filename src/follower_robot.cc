#include "follower_robot.h"
#include <iostream>
#include <cmath>

using namespace std;

void FollowerController::init() {
    cout << "FollowerController init, leader_id = " << leader_id << endl;
}

void FollowerController::start() {
    cout << "FollowerController start" << endl;
}

void FollowerController::update() {
    if (!agent_exists(leader_id)) {
        cout << "Leader with id " << leader_id << " does not exist." << endl;
        damp_movement();
        return;
    }

    Agent &leader = find_agent(leader_id);

    if (leader_id == 1) {
        static const vector<pair<double,double>> waypoints = {
            {200, 200},
            {200, -200},
            {-200, -200},
            {-200, 200}
        };
    
        double target_x = waypoints[current_target].first;
        double target_y = waypoints[current_target].second;
    
        double dx = target_x - x();
        double dy = target_y - y();
        double dist = sqrt(dx * dx + dy * dy);
    
        if (dist < 20) {
            current_target = (current_target + 1) % waypoints.size();
            cout << "Reached waypoint. Switching to target index: " << current_target << endl;
        }
    
        move_toward(target_x, target_y, 10);
    } else {
        Agent &following = find_agent(leader_id - 1);
        double dx = following.x() - x();
        double dy = following.y() - y();
        double dist = sqrt(dx * dx + dy * dy);
        cout << "distance: " << dist << endl;

        if (dist > desired_dist) {
            move_toward(following.x(), following.y(), 15);
            cout << "Moving toward leader." << endl;
        } else {
            damp_movement();
            cout << "Within desired distance, slowing down." << endl;
        }
    }
}

void FollowerController::stop() {
    cout << "FollowerController stop" << endl;
}

FollowerRobot::FollowerRobot(json spec, World& world) : Agent(spec, world) {
    int leader_id_val = -1;
    if (spec.find("leader_id") != spec.end()) {
        leader_id_val = spec["leader_id"].get<int>();
    }
    fc.set_leader_id(leader_id_val);
    add_process(fc);
}
