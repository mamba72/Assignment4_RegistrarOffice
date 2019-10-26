/*
Stephen White
002323381
stwhite@chapman.edu
Assignment 4 Registrar's office
Data Structures Section 1
*/

#include <iostream>

using namespace std;

class StatisticsMonitor
{
public:
	StatisticsMonitor();
	~StatisticsMonitor();

	//student focused stats
	float meanWaitTime;
	unsigned int medianWaitTime;
	unsigned int longestWaitTime;
	unsigned int numWaitingOverTenMin;

	//window focused stats
	float meanIdleTime;
	unsigned int longestIdleTime;
	unsigned int numIdleOverFiveMin;

};