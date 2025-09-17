// Ethan Vicencio

#include "functions.h"

#include <iostream>
#include <iomanip>

using namespace std;

static double INCHES_IN_A_METER = 39.37;
static double SPEED_CONVERSION = 2.2374;

// Implement the functions from functions.h here

// Asks user for input using prompt
// until user enters positive number
double getInput(const std::string& prompt)
{
    bool done = false;
    double input = 0.0;
    while (!done)
    {
        cout << prompt;
        double temp = 0.0;
        cin >> temp;
        if (temp > 0)
        {
            input = temp;
            done = true;
        }
    }

    return input; 
}

// converts inches to meters
double convertDistance(double inches)
{
    return inches / INCHES_IN_A_METER;
}

// converts meters/second to miles/hour
double convertSpeed(double metersPerSec)
{
    return metersPerSec * SPEED_CONVERSION; 
}

// determines velocity (meters/second) using the distance (in meters)
// and time (in seconds)
// velocity assumed to be constant
double getSpeed(double distance, double seconds)
{
    return distance / seconds;
}