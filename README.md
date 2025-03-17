# Leader-Follower Train

## Overview

This project demonstrates a multi-robot system developed for UW's EEP520 Software for Embedded Systems course using Elma and Enviro. In this project, one **Leader** robot continuously moves along a predetermined looping path while one or more **Follower** robots maintain a respectful distance behind the Leader. The Follower robots can be chained together to form a dynamic train. Future improvements may include advanced flocking behaviors or dynamic leader assignment.

**Key Features:**

- **Leader Robot:** Moves along a looping path (for example, a circle or rectangle) autonomously.
- **Follower Robots:** Use range sensor data and position feedback to follow the Leader (or the preceding Follower) at an optimal distance.
- **Train Formation:** Multiple Follower robots form a train, each following the one in front.
- **Extendable Logic:** The system is designed for easy extension with features like obstacle avoidance and flocking behaviors.

## Installation / Setup

### Prerequisites

- **Docker:** Install Docker from the [official documentation](https://docs.docker.com/install/) for your platform.
- **Git:** To clone the repository.
- **Enviro v1.6:** This project utilizes Enviro version 1.6. More details can be found [here](https://github.com/klavinslab/enviro).

### 1. Cloning the Repository

Open your terminal, navigate to a suitable directory, and clone the repository:

```bash
git clone https://github.com/yourusername/LeaderFollowerTrain.git
```

### 2. Starting Docker

Use the appropriate command for your platform.

For MAC:

```bash
docker run -p80:80 -p8765:8765 -v $PWD:/source -it klavins/enviro:v1.61 bash
```

### 3. Building and Running the Simulation

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

- **Train Formation:**  
  With multiple Follower robots configured, a train formation is created where each robot follows the one ahead, resulting in a coordinated, dynamic train.

## Summary

This project demonstrates the implementation of a multi-robot leader-follower system using Enviro and Elma. The main challenges addressed include:

- **Path Planning for the Leader:**  
  Designing and implementing a looping path for the Leader robot.

- **Sensor-Based Following:**  
  Enabling Follower robots to use range data and position feedback to maintain an optimal following distance.

- **Train Formation:**  
  Coordinating multiple Follower robots to form a stable train.

- **Modular and Extendable Design:**  
  Building the system so that further extensions (such as obstacle avoidance, dynamic task allocation, or flocking behaviors) can be integrated easily.

## Acknowledgements

Special thanks to Dr. Klavins for providing the Enviro platform and example code that significantly aided the development of this project. Thanks also to my colleagues and mentors for their invaluable debugging support and feedback.
