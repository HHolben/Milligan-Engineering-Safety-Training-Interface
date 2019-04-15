/*
Project Name: Milligan Engineering Safety Training Interface
Author: Henry Holben
Description: A convenient interface that will allow Milligan College Engineering proffessors to check for students' lab equipment safety training
Most recent changes made on: 15 March 2019
*/

//set up
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
#include <limits>
using namespace std;

//Global Variables
int ThisYearInt;
double CurrentSemester;
int TimePar;
string CurrentMonth;
int DayOfMonth;
int DaysSinceNewYears;
double ThreeDPrintOne;
int LeapYear;
string studentname;

// StudentProfiles
const int NumberOfStudents = 10; //we will use this to identify 9 students
int StudentNumbersArray[NumberOfStudents] = { 0, 1, 2, 3,4, 5, 6, 7, 8, 9 };
string StudentNamesArray[NumberOfStudents] = { "Brutus Buffalo", "Bob", "Sue", "Joe" };
//Trainings:


//Uses .5 for fall, 0.3 for Summer, and .0 for spring semesters

		/*
		Bob (1) was trained last august. His certifications have expired
		Eve (2) was trained in January. Her certifications are current.
		Joe (3) was never trained in anything
		*/



const int NumberOfTrainings = 6;
string TrainingNamesArray[NumberOfTrainings] = { "3D Printing", "Drill Press", "Mechanical 1 Fundamental Toolbox", "Band Saw", "Circular Saw", "Electrical 1: Soldering and Crimping" };
double ThreeDPrint[NumberOfStudents] = { 2019.0, 2018.5, 2019.0 }; //3D Printing
double DrillPress[NumberOfStudents] = { 0, 2018.5, 2018.0 }; //Drill Press
double FundToolBox[NumberOfStudents] = { 0, 2018.5, 2018.0 }; //Mechanical 1 (Fundamental Toolbox)
double SawBand[NumberOfStudents] = { 0, 2018.5, 2018.0 }; //Band Saw
double SawCircular[NumberOfStudents] = { 0, 2018.5, 2018.0 }; //Circular Saw
double Solder[NumberOfStudents] = { 0, 2018.5, 2018.0 }; // Soldering and Crimping

//Programmer Defined Function Prototypes

void YearTimeFinder(int(TimePar));
//Precondition: Uses Time(Null), the number of seconds since 0:00 January 1 1970.
//Postconidtion: Gives the current year (will later give day, month, and year)

void listPrinter(string StudentNamesArray[], int NumberOfStudents);
//Precondition: Uses an array of strings and the integer of entries in that array
//Post condition: Lists all studnets and trainings that have been entered into the system

//Start Main function
int main()
{
	//Say what day it is
	YearTimeFinder(TimePar);
	cout << "Day" << DaysSinceNewYears << "\n";
	cout << "Day of this Month: " << DayOfMonth << "\n";



	cout << "Today's date is:" << " " << DayOfMonth << " " << CurrentMonth << " " << ThisYearInt;
	cout << "\n";


	//Title
	cout << "_____________________________________________\n";
	cout << "Milligan Engineering Safety Training Database\n";
	cout << "_____________________________________________\n \n";

	// Get Loopy
	bool GetL00py;
	GetL00py = true;
	while (GetL00py)
	{
		// Declare some variables for the loop
		int option1 = 0;
		int studentnumber;

		string trainingname;
		int TrainingNumber;
		int reboot;

		// Home menu: decide whether we are looking for students or for training
		cout << "-----------Home Menu----------- \n \n";
		cout << "Students or Training?";
		cout << "\n Students \t 1";
		cout << "\n Training \t 2";
		cout << "\n Print all \t 3";
		cout << "\n Quit \t \t 4 \n \n";

		cout << "------------------------------- \n";
		cin >> option1;

		//But what if the user enters the wrong value type?





		//Let's find some students

		if (option1 == 1) {
			cout << "--------------Students-------------- \n";
			cout << "\n \n Who are you looking for? \n";
			cin >> studentname;


			// Relate input name to a number
			int NameSearchIteration;
			for (NameSearchIteration = 0;NameSearchIteration <= NumberOfStudents;NameSearchIteration++)
			{
				if (StudentNamesArray[NameSearchIteration] == studentname)
				{
					studentnumber = NameSearchIteration; //We found them!
					cout << "\n" << studentname << " is student number " << studentnumber;
				}
			};
			if (NameSearchIteration > NumberOfStudents)
			{
				"No student was found by that name.";
				GetL00py = false;
			}


			//Check for Student's Training

				// training array: {0: solder trained? 1 or 0, 1: Month solder trained, 2: Day solder trained, 3: Year solder trained, 4: toolbox trained?, 5: Month toolbox trained, 6: Day toolbox trainined, 7: Year toolbox trained}
	//if (studentname = 'Bob'){
			int Training[8] = { 1, 1, 20, 2019, 0, 0, 0, 0 };

			//3D Printing
			if (ThreeDPrint[studentnumber] == CurrentSemester)
			{//Tim found error here- student number is being used without being initialized
				cout << "\n" << studentname << " was trained in 3d Printing during the " << ThreeDPrint[studentnumber] << " semester. " << studentname << "'s training is current. \n";
			}
			if (ThreeDPrint[studentnumber] < CurrentSemester)
			{
				cout << "\n" << studentname << " was trained in 3d Printing in the " << ThreeDPrint[studentnumber] << " semester. " << studentname << "'s training has expired. \n";
			}
			if (ThreeDPrint[studentnumber] == 0)
			{
				cout << "\n" << studentname << " was never trained in 3d Printing at Milligan. \n";
			}


			cout << studentname << "\t has completed \t \n \n \n";
		}
		//let's see who's trained
		if (option1 == 2) 
		{
			cout << "--------------Training-------------- \n";
			cout << "What training are you interested in? \n";
			cout << "\n \t 3d Printing \t 1";
			cout << "\n \t Drill Press \t 2";
			cout << "\n \t Mechanical 1 Fundamental Toolbox \t 3";
			cout << "\n \t Band saw \t 4";
			cout << "\n \t Circular saw \t 5";
			cout << "\n \t Soldering and crimping \t 6 \n \n";
			cout << "------------------------------------ \n";
			cin >> TrainingNumber;

			//3d printing
			if (TrainingNumber = 1)
			{
				// Find students with current 3d printing training
				cout << "\t Students with current training in 3d printing: \n \n";
				for (int StudentSearchIteration = 0; StudentSearchIteration <= NumberOfStudents; StudentSearchIteration++)
				{
					if (ThreeDPrint[StudentSearchIteration] == CurrentSemester)
					{
						cout << StudentNamesArray[StudentSearchIteration];
						cout << "\n";
					};
				};
				//Find students with expired 3d-printing training
				cout << "\t Students with outdated training in 3d printing: \n \n";
				for (int StudentSearchIteration = 0; StudentSearchIteration <= NumberOfStudents; StudentSearchIteration++)
				{
					if (ThreeDPrint[StudentSearchIteration] != CurrentSemester)
					{
						if (ThreeDPrint[StudentSearchIteration] != 0)
						{
							cout << StudentNamesArray[StudentSearchIteration];
							cout << "\n";
						}
					};
					StudentSearchIteration++;
				};
			};
		}
		// Stop. Please Stop.
		if (option1 == 4)
		{
			GetL00py = false;
		}
		if (option1==4)
		{			


	};
	return (0);
}

//YearTimeFinder function
YearTimeFinder(int(TimePar))
{
	double SecondsSince1970 = time(NULL);
	double DaysSince1970 = ((SecondsSince1970 / 60) / 60) / 24;//number of days
	double YearsSince1970 = DaysSince1970 / 365.25;//number of years
	double ThisYeardouble = 1970 + YearsSince1970;
	ThisYearInt = static_cast<int>(ThisYeardouble);
	int FebruaryDays = 0;

	//Find number of seconds since new years
	float SecondsSinceNewYears = SecondsSince1970 - (static_cast<float>(ThisYearInt) - 1970) * 60 * 60 * 24 * 365.25;
	int DaysSinceNewYears = static_cast<int>(SecondsSinceNewYears / (60 * 60 * 24)) + 1;

	//Month Name

	//Check for leap year

	int LeapYearCheck = ThisYearInt - 1972; // First leap year since 1970: 1972

	if (LeapYearCheck % 4 == 0)
	{
		LeapYear = 0;
	}
	else
	{
		LeapYear = 29;
	}
	//Identify Month
	string CurrentMonthName[13] = { "SecretLevelMonth", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	int CurrentMonthDaysSum[13] = { 9, 31, FebruaryDays, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };



//listPrinter Function
listPrinter(int(ListPar))
{
	//List all students
	cout << "Students Enrolled: \n";
	for (int i = 0; i < NumberOfStudents;i++)
	{
		cout << "\t" << StudentNamesArray[i]<< "\n";
	}
	//list all trainings
	cout << "Trainings Enrolled: \n";
		for (int i = 0; i < NumberOfTrainings;i++)
		{
			cout << "\t " << TrainingNamesArray[i] << "\n";
		}

	//Identify Semester
	CurrentSemester = static_cast<double>(ThisYearInt);
	return;
}
//listPrinter Function
void listPrinter(string NamesArray[], int NumberOfNames)
{
	//Dump all trainings and students 
	for (int i = 0; i < NumberOfNames;i++)
	{
		cout << "\t " << NamesArray[i] << "\n";
	}
	return;
}

