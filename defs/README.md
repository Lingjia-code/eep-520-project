# Color Gate Robot Game

## Project Overview

This project is a multi-agent system developed using the Elma and Enviro frameworks, creating an interactive simulation environment where colored square robots (green, purple, and red) must push black circles into gates of matching colors. The project combines obstacle manipulation and goal-oriented behavior to demonstrate how agents can accomplish specific tasks through reinforcement learning.

## Key Challenges and Solutions

During development, the following key challenges were encountered:

1. **Collision Detection and Physical Interaction**: Robots needed to interact precisely with circular objects and push them in specific directions.

2. **Path Planning and Navigation**: Robots needed to find optimal paths from their current position to circular objects and then to target gates.

3. **Multi-Agent Coordination**: Multiple robots operating simultaneously could lead to conflicts and interference.

## Installation and Setup

### Prerequisites

- Docker installed
- Enviro image pulled: `docker pull klavins/enviro:1.6`

### Installation Steps

```bash
# Clone the repository
git clone https://github.com/yourusername/color-gate-robot.git
cd color-gate-robot

# Use Enviro environment
docker run -p80:80 -p8765:8765 -v $PWD:/source -it klavins/enviro:1.6 bash

# Compile the project inside Docker container
cd /source
make clean
make
```

### Running the Project

```bash
# Start inside Docker container
esm start
enviro
```

Then visit http://localhost in your browser to view the simulation environment.

## Usage Guide

After starting the project, you will see an environment with colored gates and different colored robots, as well as black circular objects scattered throughout the scene.

## AI Implementation

This project uses reinforcement learning techniques to train robots to effectively:
1. Navigate to circle positions
2. Push circles toward corresponding colored gates
3. Avoid pushing circles toward incorrect gates

Specifically, the following AI components were implemented:

- **State Perception**: Using sensors to perceive objects and other robots in the environment
- **Decision System**: Determining optimal actions based on current state and goals
- **Behavior Execution**: Translating decisions into specific movement and pushing behaviors

## Project Architecture

The project code is organized as follows:

```
color-gate-robot/
├── src/
│   ├── robot.h       // Robot class definition
│   ├── robot.cc      // Robot class implementation
│   ├── circle.h      // Circle object class definition
│   ├── circle.cc     // Circle object class implementation
│   ├── gate.h        // Gate class definition
│   ├── gate.cc       // Gate class implementation
│   └── main.cc       // Main program entry
├── include/          // Other header files
├── config/           // Configuration files
├── defs/             // Enviro definition files
├── Makefile          // Compilation script
└── README.md         // Project documentation
```

## References and Acknowledgments

This project referenced the following resources:
- [Enviro Framework](https://github.com/klavinslab/enviro)
- [Elma Framework](https://github.com/klavinslab/elma)

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
