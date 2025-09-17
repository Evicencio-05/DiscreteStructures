// Ethan Vicencio

#include <iostream>
#include <string>
#include <iomanip>

#include "functions.h"

using namespace std;

int main(){

    // Implement your main program here using the functions declared in functions.h

	double distance = getInput("Enter the distance between the wires (inches): ");
	double times[4];
	for (size_t i = 0; i < 4; ++i)
	{
		times[i] = getInput("Enter time recorded (seconds): ");
	}

	cout << "Vehicle" << setw(20) << "Time (seconds)" << setw(20) << "Speed (m/s)"
		<< setw(20) << "Speed (mph)" << endl;
	for (size_t i = 0; i < 4; ++i){
		double distanceInMeters = convertDistance(distance);
		double speedInMetersPerSecond = getSpeed(distanceInMeters, times[i]);
		cout << setw(7) << left << i + 1 << setw(20) << setprecision(2) << fixed << right << times[i] << setw(20)
			<< speedInMetersPerSecond << setw(20) << convertSpeed(speedInMetersPerSecond)
			<< endl;
	}

	return 0;
}
