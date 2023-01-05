/*
* FILE : exam.cpp
* PROJECT : PROG1345 - Final Exam
* PROGRAMMER : Marcus Kanhoye
* FIRST VERSION : 2023-01-05
* DESCRIPTION :
* Merkkin Airlines is a rather extremely unusual airline. It's unusual because it likes customers with certain names. 
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

bool rangeChecker(int);
void displayPassenger(int, string, string, float, string);

int main(int argc, char** argv)
{
	string temp;
	string line;
	int row_number;
	string seat_location;
	string passengers_name;
	float fare, total_fare = 0.0;
	string fav_per;

	cout << "Please enter Favourite passenger name: ";
	cin >> fav_per;

	ifstream fin("passengers.info");;
	fin.exceptions(ifstream::badbit);


	if (!fin) 
	{ 
		cout << "Error: File not found or corrupted " << endl; 
		return 0; 
	}

	while (getline(fin, line))
	{
		stringstream t(line);

		getline(t, temp, ',');
		row_number = std::stoi(temp);
		if (!rangeChecker(row_number))
		{
			cout << "Error: Row number is out of range" << endl;
			system("pause");
			return 0;
		}

		getline(t, temp, ',');
		seat_location = temp;
		if (seat_location.length() > 1)
		{
			cout << "Error: Seat Location is out of range" << endl;
			system("pause");
			return 0;
		}

		getline(t, temp, ',');
		passengers_name = temp;
		if (passengers_name.length() > 16)
		{
			cout << "Error: Passengers Name is out of range" << endl;
			system("pause");
			return 0;
		}

		getline(t, temp, ',');
		fare = stof(temp);
		
		total_fare = total_fare + fare;
		displayPassenger(row_number, seat_location, passengers_name, fare, fav_per);
	}

	cout << "\nTotal fares paid: $" << total_fare << endl;

	fin.close();

	cout << endl;
	system("pause");
	return 0;
}

bool rangeChecker(int row_number)
{
	if (row_number > 99)
	{
		return false;
	}
	return true;
}

void displayPassenger(int row_number, string seat_location, string passengers_name, float fare, string fav_per)
{
	if (passengers_name.find(fav_per) != std::string::npos)
	{
		cout << "Seat " << row_number << seat_location << ": " << passengers_name << " paid $" << fare << " (Merkkin Airlines likes them)" << endl;
	}
	else
	{
		cout << "Seat " << row_number << seat_location << ": " << passengers_name << " paid $" << fare << endl;
	}
}