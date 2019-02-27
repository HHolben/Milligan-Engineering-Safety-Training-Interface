/*
Project Name: Milligan Engineering Safety Training Interface
Author: Henry Holben
Description: A convenient interface that will allow Milligan College Engineering proffessors to check for students' lab equipment safety training
Most recent changes made on: 15 February 2019
*/

//set up

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//Start Main function
int main()
{

	// Declare some variables
	int option1;
	int studentnumber;
	string studentname;
	string trainingname;
	int TrainingNumber;
	int reboot;


	//Identify Today's Date

	double Today[3] = { 2, 15, 2019 };
	double now = time(NULL);

	float CurrentSemester = 2019.0;

	/*
	time_t now = time(NULL);
	tm nowtm=*(gmtime(&now));

	cout <<"Year =" << (timePtr->tm_year);



	//Seconds since 12:00 AM 1 / 1 / 1970 Convert from day, month, year

	int daysinmonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int yearVal, monthVal, day, val;
	double Time;
	Time += (yearVal - 1970) * 365;
	Time = (yearVal - 1970) / 4;
	for (int i=, i < month, i++);
	{
		time_t = days[inmonth[i]];
	}
	int timet=day;
	Time = timet * 24 * 60 * 60;

	*/

	// StudentProfiles

	const int NumberOfStudents = 10; //we will use this to identify 9 students
	int StudentNumbersArray[NumberOfStudents] = { 0, 1, 2, 3,4, 5, 6, 7, 8, 9 };
	string StudentNamesArray[NumberOfStudents] = { "Brutus Buffalo", "Bob", "Sue", "Joe" };
	//Trainings:

	//Uses .5 for fall, 0.3 for Summer, and .0 for spring semesters

			/*Bob (1) was trained last august. His certifications have expired
			Eve (2) was trained in January. Her certifications are current.
			Joe(3) was never trained in anything
			*/

	float ThreeDPrint[NumberOfStudents] = { 2019.0, 2018.5, 2019.0 }; //3D Printing
	float DrillPress[NumberOfStudents] = { 0, 2018.5, 2018.0 }; //Drill Press
	float FundToolBox[NumberOfStudents] = { 0, 2018.5, 2018.0 }; //Mechanical 1 (Fundamental Toolbox)
	float SawBand[NumberOfStudents] = { 0, 2018.5, 2018.0 }; //Band Saw
	float SawCircular[NumberOfStudents] = { 0, 2018.5, 2018.0 }; //Circular Saw
	float Solder[NumberOfStudents] = { 0, 2018.5, 2018.0 }; // Soldering and Crimping

	// Get Loopy

	bool GetL00py;
	GetL00py = true;
	while (GetL00py)
	{
		// Reset Variables

		option1 = 0;
		reboot = 0;

		// decide whether we are looking for students or for training
		cout << "Students or Training?";
		cout << "\n Students \t 1";
		cout << "\n Training \t 2";
		cout << "\n Quit \t \t 3 \n \n";
		cin >> option1;

		//Let's find some students

		if (option1 == 1) {
			cout << "Who are you looking for?";
			cin >> studentname;
			cout << "\n \n You are looking for training completed by " << studentname << ".";

			// Relate input name to a number

			
			for (int NameSearchIteration = 0;NameSearchIteration <= NumberOfStudents;NameSearchIteration++)
			{
				if (StudentNamesArray[NameSearchIteration] == studentname)
				{
					studentnumber = NameSearchIteration; //We found them!
					cout << "\n" << studentname << " is student number " << studentnumber;
				}
			};

			//Check for Student's Training

			//3D Printing
			if (ThreeDPrint[studentnumber] == CurrentSemester)
			{
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

			// turn that student name into an ascii number

			
			cout << "\n \n" << studentname << "'s name in ASCII characters is: ";
			for (int NameLetterNumber = 0; studentname[NameLetterNumber] > 32; NameLetterNumber++)
			{
				int ASCIIcharacter = studentname[NameLetterNumber];
				cout << ASCIIcharacter;
			};// the obvious problem to fix here is that a space entered in the name will stop the program in the middle of a full name
			cout << studentname << "\t has completed \t";

			// Restart

			cout << "\n \n Enter any any character to Restart \n";
			cin >> reboot;
			if (reboot = 1) {
				GetL00py = false;
			}
			else {
				GetL00py = false;
			}
		}
		else {

			//let's see who's trained
			if (option1 == 2) {
				cout << "What training are you interested in? \n";
				cout << "\n \t 3d Printing \t 1";
				cout << "\n \t Drill Press \t 2";
				cout << "\n \t Mechanical 1 Fundamental Toolbox \t 3";
				cout << "\n \t Band saw \t 4";
				cout << "\n \t Circular saw \t 5";
				cout << "\n \t Soldering and crimping \t 6 \n \n";
				cin >> TrainingNumber;

				//soldering
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
					//Find students with expired soldering training
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
			cin >> trainingname;
			cout << "you are looking for students who have completed \n" << "\n training.";
		}
		// Stop. Please Stop.

		GetL00py = false;
	};
	return (0);
}
