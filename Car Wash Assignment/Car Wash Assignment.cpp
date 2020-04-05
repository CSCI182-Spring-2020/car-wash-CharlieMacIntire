// Car Wash Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Cars.h"
#define WASH_TIME 3

int main()
{
	int probability;
	cout << "Probability of a Car Showing up: ";
	cin >> probability;

	int hours;
	cout << "Hours (In Minutes) you would like to simulate: ";
	cin >> hours;

		// Seed the random generator (near the top)
		srand(time(NULL));
		// For each minute, get a random value.  If you do it like this,
		// you get a number between 0-99
		

		int nCarsWashed = 0;
		int waitingCar = 0;
	// Below we check if it's within the probability
	// nSimCarProbPercentage is the percentage entered by the user
		Cars s1;
		for (int i = 0; i < hours; i++)
		{
			int q = rand() % 100;

			if (i % 3 == 0) {

				if (q < probability)
				{
					// Process a car into the queue
					s1.QueueItem(i);
					nCarsWashed = nCarsWashed + 1;
				}
			}
			else {
				waitingCar = waitingCar + 1;
			}
	
			s1.DequeueItem();
		}
		
		int avgwaitTime = hours / nCarsWashed;
		cout << "Number of Cars Washed: " << nCarsWashed << endl;
		cout << "Average wait time during the simulation: " << avgwaitTime << endl;
		cout << "Number of Cars in line at close of simulation: " << waitingCar << endl;

		

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
