# Leader-Follower Robots

## Overview

This project demonstrates a multi-robot system developed using Elma and Enviro. In this project, one **Leader** robot continuously moves along a looping path while one or more **Follower** robots maintain a respectful distance behind the Leader. During the following, there will be a naughty robot disrupt the original path of leader and follower. Howerver, all the followers may go back and keep following the leader.

**Key Features:**

- **Leader Robot:** Moves along a looping path (for example, a circle or rectangle) autonomously.
- **Follower Robots:** Use range sensor data and position feedback to follow the Leader (or the preceding Follower) at an optimal distance.

## Installation / Setup

### Prerequisites

- **Docker:** Install Docker from the [official documentation](https://docs.docker.com/install/) for your platform.
- **Git:** To clone the repository.
- **Enviro v1.6:** This project utilizes Enviro version 1.6. More details can be found [here](https://github.com/klavinslab/enviro).

### 1. Starting Docker

Use the appropriate command for your platform.

```bash
docker run -p80:80 -p8765:8765 -v $PWD:/source -it klavins/enviro:v1.61 bash
```

### 2. Building and Running the Simulation

Once inside the Docker container, navigate to your project directory and execute the following commands:

```bash
esm start
make
enviro
```
Then, open your browser and navigate to http://localhost.

## Running the Simulation

- **Leader Robot:**  
  The Leader robot continuously follows its pre-programmed looping path (for example, a circular or rectangular path).

- **Follower Robots:**  
  Each Follower robot reads its configuration (via a hardcoded or dynamically assigned `leader_id`) and uses sensor data to maintain a set following distance from the Leader.

- **Naughty Robots:**
  Only one naughty robot may disrupts the original path of leader-followers. The robot continuously run its pre-programmed looping path.
  
## Summary

This project demonstrates the implementation of a multi-robot leader-follower system using Enviro and Elma. The main challenges addressed include:

- **Path Planning for the Leader:**  
  Designing and implementing a looping path for the Leader robot.

- **Sensor-Based Following:**  
  Enabling Follower robots to use range data and position feedback to maintain an optimal following distance.

- **Modular and Extendable Design:**  
  Building the system so that further extensions (such as obstacle avoidance, dynamic task allocation, or flocking behaviors) can be integrated easily.

## Acknowledgements
The project is built by Elma and ENVIRO, all documentations can be found in official github repository.
