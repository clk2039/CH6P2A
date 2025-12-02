/*
File Name: CH6P2.cpp
Github URL: https://github.com/clk2039/CH6P2A.git
Programmer: Kit Miller
Date: December 2025
Requirements: Write a modular, procedural program that uses functions to determine which geographic regions within a major city
(North, South, East, West, Central) had the fewest automobile accidents last year. Validate the input, do not accept accidents less than 0.
*/

#include <iostream>
using namespace std;

/* The function getRegInfo asks the user the name of a region and the number of accidents that occured in the last year in that region.
Input - Name of region and number of accidents.
Preconditions - Number of accidents must be 0 or greater.
Postconditions - Returns the name of the region and the number of accidents.
*/
void getRegInfo(string& region, int& accidents)
{
	//Get region name
	cout << "Enter the region, North, South, East, West, or Central: ";
	cin >> region;
	while (region != "North" && region != "South" && region != "East" && region != "West" && region != "Central")
	{
		cout << "Please enter North, South, East, West, or Central: ";
		cin >> region;
	}
	//Get number of accidents
	cout << "Enter the number of reported accidents in " << region << " last year: ";
	cin >> accidents;
	while (accidents < 0)
	{
		cout << "It would be great if negative accidents were real, try again: ";
		cin >> accidents;
	}
}
/* The function isLower determines if the number of accidents in the current region is lower than the lowest number of accidents recorded so far.
Input - Current region's number of accidents and lowest number of accidents recorded.
Postconditions - Returns a Boolean value, true if current region's accidents are lower, false otherwise.
*/
bool isLower(int currentAccidents, int& lowestAccidents)
{
	if (currentAccidents < lowestAccidents)
	{
		lowestAccidents = currentAccidents;
		return true;
	}
	else
	{
		return false;
	}
}
/* The function showLowest gets the name of the region with the lowest number of accidents and displays both to the user.
Input - Name of region with lowest accidents and number of accidents.
Postconditions - Displays the region and number of accidents to the user.
*/
void showLowest(string region, int accidents)
{
	cout << "The region with the fewest accidents last year was " << region << " with " << accidents << " accidents." << endl;
	cout << "As of last year, it was the safest." << endl;
}

/* This program determines the safest driving region in the city based on the number of accidents reported for each in the last year.
*/
int main()
{
	// Region names
	string North = "North";
	string South = "South";
	string East = "East";
	string West = "West";
	string Central = "Central";

	// Variables to hold number of accidents
	int northAccidents, southAccidents, eastAccidents, westAccidents, centralAccidents;

	// Variables to hold lowest accidents and region name
	int lowestAccidents = INT_MAX;
	string safestRegion;

	// Get accident info for each region
	getRegInfo(North, northAccidents);

	if (isLower(northAccidents, lowestAccidents))
	{
		safestRegion = North;
	}
	getRegInfo(South, southAccidents);
	if (isLower(southAccidents, lowestAccidents))
	{
		safestRegion = South;
	}
	getRegInfo(East, eastAccidents);
	if (isLower(eastAccidents, lowestAccidents))
	{
		safestRegion = East;
	}
	getRegInfo(West, westAccidents);
	if (isLower(westAccidents, lowestAccidents))
	{
		safestRegion = West;
	}
	getRegInfo(Central, centralAccidents);
	if (isLower(centralAccidents, lowestAccidents))
	{
		safestRegion = Central;
	}

	// Show the region with the lowest accidents
	showLowest(safestRegion, lowestAccidents);

	return 0;


}