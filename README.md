# Final Project - Multi-Agent Hostage Rescue
[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
---
[![Build Status](https://github.com/mahimaarora2208/HumanDetecterAndTracker/actions/workflows/build_and_coveralls.yml/badge.svg)](https://github.com/mahimaarora2208/HumanDetecterAndTracker//actions/workflows/build_and_coveralls.yml)
[![Coverage Status](https://coveralls.io/repos/github/mahimaarora2208/HumanDetecterAndTracker/badge.png?branch=main)](https://coveralls.io/github/mahimaarora2208/HumanDetecterAndTracker?branch=main)
## Overview
This project simulates a Multi-agent system for search and rescue missions where we use turtlebot3 package in ROS2 Galactic. Our multi-agent system consists of 2- robots that are each specialized for a certain task. 8 turtlebots will be simulated as threats, another 8 turtlebots will be specific to neutralizing these threats and 4 people will be simulated using Aruco markers. The remaining 4 turtlebots will be used to rescue these 4 hostages.

## Final Project Team: Group 1

 - Naveen Mangla - Driver (https://github.com/nvnmangla)
 - Mahima Arora - Navigator (https://github.com/mahimaarora2208)
 - Abhinav Garg - Designer (https://github.com/15abhinavgarg)


## AIP Development

This project will be completed using AIP process with the involvement of 3 programmers using Pair-programming in turns. One of the programmer would be driver while other 2 would be navigator and design keeper. The detailed Product Backlog, Iteration Backlogs and Work Log are mentioned in the link given below :

[Agile Iterative Process](https://docs.google.com/spreadsheets/d/1lvFBjKfvxlf-LXtopkBy3UAMlyQPi31W/edit?usp=sharing&ouid=106728747057946217321&rtpof=true&sd=true)

## Important Links

[Phase 0 Proposal](https://drive.google.com/file/d/1Q7Ae7BqAT_y9z2TzFeA78kWwCRC0aNpY/view?usp=share_link)

[Phase 0 Video](https://drive.google.com/file/d/1j9FvWYJ_o5ee0BTNtfcTjndG6ISZVPU-/view)

[Phase 1 Video]() 

[UML Class Diagram Phase 0](https://drive.google.com/file/d/16ZB5cMJbd44Ys_4KVa8fdSBXSPN-JB1F/view?usp=sharing) # TO-D0 Needs to be updated

[Activity Diagram Phase 0](https://drive.google.com/file/d/1PFQ3R563C5RVZqSqUmu6HlybmQZDz23V/view?usp=sharing) # TO-D0 Needs to be updated

[Quad Chart](https://drive.google.com/file/d/1Q7Ae7BqAT_y9z2TzFeA78kWwCRC0aNpY/view?usp=share_link)

## Sprint Planning Notes
The below link contains combined notes of sprint 1 and sprint 2.
[Link](https://docs.google.com/document/d/1r_AImnCmMG55agtjQzNZ3n2YdrxkfY6n6iax4RRetbs/edit?usp=sharing) # TO-D0 Needs to be updated


# TO-D0 Needs to be updated Below this

## Downloading Dependencies
The main dependency that needs to be downloaded is openCV 4.2 or above.


```
# Installing Dependencies
sudo apt install -y g++ cmake make git libgtk2.0-dev pkg-config

# Cloning Git repository
git clone https://github.com/opencv/opencv.git;mkdir -p build && cd build

# CMAKE
cmake ../opencv;make -j4

# Installing OpenCV 
sudo make install
```



## How to build and run demo code
```
git clone https://github.com/nvnmangla/HumanDetecterAndTracker.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```


## To Generate and Check code coverage
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## To Generate Doxygen Documentation
open your terminal in your repository
```
doxywizard
```
Follow steps in GUI after selecting path of your repository.