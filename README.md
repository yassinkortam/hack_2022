# Alien Years

## const.h

contains all the constant value variables for the program (pinouts, hardware specs, etc).

## initialize.h

Ensures that all user inputs are within hardware bounds, i.e. servo angles do not exceed 180 degrees and analog values do not exceed +-240.

## control.h

Manipulates the drive system to implement user inputs, i.e. drives forwards, backwards, and turns depending on values prepared by initialize().

## main.cpp

Driver program. Takes user inputs and executes functions from the above header files.

##display.into

Displays facial 
expressions on LCD
