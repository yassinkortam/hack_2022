# Alien Years

## Introduction

The goal of this hackathon was to create a steerable rover with a robotic arm that can be controlled via bluetooth. This project was completed in 3 days. Note that the code has been edited since the end of the competition, and is currently being improved.

https://etransfercenter.seas.ucla.edu/hack-2022/

## const.h

contains all the constant value variables for the program (pinouts, hardware specs, etc).

## initialize.h

Ensures that all user inputs are within hardware bounds, i.e. servo angles do not exceed 180 degrees and analog values do not exceed +-240.

## control.h

Manipulates the drive system to implement user inputs, i.e. drives forwards, backwards, and turns depending on values prepared by initialize().

## main.cpp

Driver program. Takes user inputs and executes functions from the above header files.

## display.ino

Displays facial 
expressions on LCD
