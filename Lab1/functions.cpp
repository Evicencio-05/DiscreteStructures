// Ethan Vicencio

#include "functions.h"

#include <iostream>
#include <iomanip>

using namespace std;

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
    return inches / 39.3701;
}

// converts meters/second to miles/hour
double convertSpeed(double metersPerSec)
{
    return (metersPerSec * 1609.34) / 3600; 
}

// determines velocity (meters/second) using the distance (in meters)
// and time (in seconds)
// velocity assumed to be constant
double getSpeed(double distance, double seconds)
{
    return distance / seconds;
}