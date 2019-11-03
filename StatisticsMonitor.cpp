/*
Stephen White
002323381
stwhite@chapman.edu
Assignment 4 Registrar's office
Data Structures Section 1
*/

#include "StatisticsMonitor.h"

StatisticsMonitor::StatisticsMonitor()
{
	meanWaitTime = 0;
	medianWaitTime = 0;
	longestWaitTime = 0;
	numWaitingOverTenMin = 0;

	meanIdleTime = 0;
	longestIdleTime = 0;
	numIdleOverFiveMin = 0;
}

StatisticsMonitor::~StatisticsMonitor()
{

}