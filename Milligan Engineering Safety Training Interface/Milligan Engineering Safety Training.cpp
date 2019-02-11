/*
Project Name: Milligan Engineering Safety Training Interface
Author: Henry Holben
Description: A convenient interface that will allow Milligan College Engineering proffessors to check for students' lab equipment safety training
Most recent changes made on: 7 February 2019
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
	string studentname;
	string trainingname;
	int reboot;


	//Identify Today's Date

	int Today[3] = { 2, 9, 2019 };

	/*
	time_t now = time(NULL);
	tm nowtm=*(gmtime(&now));

	cout <<"Year =" << (timePtr->tm_year);
	*/


	// Get Loopy

	bool GetL00py;
	GetL00py = true;
	while (GetL00py == true)
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
			cout << "\n \n You are looking for training completed by \t " << studentname;

			// turn that student name into an ascii number
			
			int NameLetterNumber = 0;
			cout << "\n \n"<< studentname << "s name in ASCII characters is: \n";
			while (studentname[NameLetterNumber] > 32) 
			{
				int ASCIIcharacter = studentname[NameLetterNumber];
					cout << ASCIIcharacter;
					NameLetterNumber++;
			};// the obvious problem to fix here is that a space entered in the name will stop the program in the middle of a full name


			// StudentProfiles

			const int NumberOfStudents = 10; //we will use this to identify 11 students




			// Right now we have three students: 000, 001, 011

			int StudentNamesArray[10] = {1, 2, 3, 0, 0, 0, 0, 0, 0, 0};
			bool ThreeDPrint[3] = {false, true, true};

		//Bob the student

					// training array: {0: solder trained? 1 or 0, 1: Month solder trained, 2: Day solder trained, 3: Year solder trained, 4: toolbox trained?, 5: Month toolbox trained, 6: Day toolbox trainined, 7: Year toolbox trained}
		//if (studentname = 'Bob'){
			int Training[8] = { 1, 1, 20, 2019, 0, 0, 0, 0 };

			if (Training[0] == 1) {
				int MonthsElapsedSinceSolderTraining = ((Today[1]) * 12 + Today[0]) - (Training[1] * 12 + Training[0]);
				cout <<"\n \n" << studentname << "\n \t was trained in soldering";
			}
			else
			{
				cout << "";

			}

			/*}
			else { cout << "No information available"; }*/


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

			// let's see who's trained

			if (option1 == 2) {
				cout << "What training are you interested in?";
				cin >> trainingname;
				cout << "you are looking for students who have completed \n" << "\n training.";
			}
			// Stop. Please Stop.

			GetL00py = false;
		};
	};
	return (0);
}


