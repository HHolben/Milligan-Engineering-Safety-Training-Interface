/*
Project Name: Milligan Engineering Safety Training Interface
Author: Henry Holben
Description: A convenient interface that will allow Milligan College Engineering proffessors to check for students' lab equipment safety training
Most recent changes made on: 12 April 2019
*/

// Move set up to standard header file, use instead #include "StandardHeaderFile.h"
//set up
#include "StandardHeaderFile.h"
#include "dateClass.h"
#include "TraineesClass.h"


//Global Variables

struct SecondsToDate
{


	int ThisYearInt;
	double CurrentSemester;
	int TimePar;
	string CurrentMonth;
	int DayOfMonth;
	int DaysSinceNewYears;
	double ThreeDPrintOne;
	int LeapYear;
};



	string StudentNamesArray[5];


//Early Test Student Names
const int NumberOfStudents = 10; //we will use this to identify 9 students
int StudentNumbersArray[NumberOfStudents] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//Trainings:


	//Uses .5 for fall, 0.3 for Summer, and .0 for spring semesters

		/*
		Bob (1) was trained last august. His certifications have expired
		Eve (2) was trained in January. Her certifications are current.
		Joe (3) was never trained in anything
		*/


struct Equipment
{

	double ThreeDPrint;
	double DrillPress;
	double FundToolBox;
	double SawBand;
	double SawCircular;
	double Solder;

};














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
		using namespace std;
		TraineesClass Trainee;
		SecondsToDate DateFinder;
		//File input

		//3D Print

		//go through the safety contract




		ifstream safetycontract;
		safetycontract.open("MilliganSafetyContract.csv");


		if (safetycontract.is_open())
		{


			//next? - look at page 355
			cout << "InStream is working. \n";

			int ColumnNumber = 1;

			while (safetycontract.good())
			{
				string line;
				getline(safetycontract, line, ',');
				if (line == "")
				{
					ColumnNumber++;
				}
				else
				{
					cout << ColumnName[ColumnNumber] << ": \t \t \t \t" << line << "\n";
				}

				ColumnNumber++;
				if (ColumnNumber > NumberOfColumns)
				{
					cout << "\n";
					ColumnNumber = 1;
					cout << "\n _____________________________________________\n";
				}
			}

		}

		else
		{
			cout << "InStream is not working. \n";
		}


		safetycontract.close();


		//Say what day it is
		YearTimeFinder(DateFinder.TimePar);
		cout << "Day" << DateFinder.DaysSinceNewYears << "\n";
		cout << "Day of this Month: " << DateFinder.DayOfMonth << "\n";



		cout << "Today's date is:" << " " << DateFinder.DayOfMonth << " " << DateFinder.CurrentMonth << " " << DateFinder.ThisYearInt;
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
			//maybe structure
			int option1 = 0;
			int studentnumber;
			string trainingname;
			int TrainingNumber;


			// Home menu: decide whether we are looking for students or for training
			cout << "-----------Home Menu----------- \n \n";
			cout << "Students or Training?";
			cout << "\n Students \t 1";
			cout << "\n Training \t 2";
			cout << "\n Print all \t 3";
			cout << "\n Quit \t \t 4 \n \n";

			cout << "------------------------------- \n";
			cin >> option1;

			Trainee.TrainingSearch();

			//But what if the user enters the wrong value type?
			if (cin.fail()) //if cin fails
			{
				cin.clear(); //clears the bad input
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignores the bad input
			}





			//Let's find some students

			if (option1 == 1)

				/*class Students {
				int TrainingDate, TrainingNumber;

				public:set_values(int, int);

			};
			*/


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

				//But what if the user enters the wrong value type...again?
				if (cin.fail()) //if cin fails 
				{
					cout << "\n Please enter a valid option number. \n";
				}
				//But what if someone enters a number out of range
				if (TrainingNumber != 1 | 2 | 3 | 4 | 5 | 6)
				{
					cout << "\n Please enter a valid option number. \n";
				}

				//Trainings

					//Identify what training has been selected
				string TrainingName = TrainingNamesArray[TrainingNumber - 1];


				// Find students with current 3d printing training
				cout << "\t Students with current training in " << TrainingNamesArray[TrainingNumber - 1] << ": \n \n";
				for (int StudentSearchIteration = 0; StudentSearchIteration <= NumberOfStudents; StudentSearchIteration++)
				{
					if (TrainingName[StudentSearchIteration] == DateFinder.CurrentSemester)
					{
						cout << StudentNamesArray[StudentSearchIteration];
						cout << "\n";
					};
				};
				//Find students with expired 3d-printing training
				cout << "\t Students with outdated training in " << TrainingNamesArray[TrainingNumber - 1] << ": \n \n";
				for (int StudentSearchIteration = 0; StudentSearchIteration <= NumberOfStudents; StudentSearchIteration++)
				{
					if (TrainingName[StudentSearchIteration] != DateFinder.CurrentSemester)
					{
						if (TrainingName[StudentSearchIteration] != 0)
						{
							cout << StudentNamesArray[StudentSearchIteration] << ":\t" << TrainingName[StudentSearchIteration];

							cout << "\n";
						}
					};
					StudentSearchIteration++;
				};



			}
			//Dump students and trainings enrolled
			if (option1 == 3)
			{
				double ThreeDPrintOne = 1.0;
				cout << "Students Enrolled: \n";
				listPrinter(StudentNamesArray, NumberOfStudents);
				cout << "Trainings Enrolled: \n";
				listPrinter(TrainingNamesArray, NumberOfTrainings);
				//File output

				ofstream outStream;
				outStream.open(("Milligan Engineering Safety Training List.txt"), ios::out);

				if (outStream.is_open())
				{
					outStream << ThreeDPrintOne;
					cout << "The Write out list has been updated. \n";

				}
				outStream.close();
			}
			// Stop. Please Stop.
			if (option1 == 4)
			{
				GetL00py = false;
			}

			if (option1 != (1 || 2 || 3 || 4))
			{
				cout << "\n Please enter an integer listed in the menu \n.";
			}



		};
		return (0);
	}

	//YearTimeFinder function
	void YearTimeFinder(int(TimePar))
	{
		SecondsToDate DateFinder;
		double SecondsSince1970 = time(NULL);
		double DaysSince1970 = ((SecondsSince1970 / 60) / 60) / 24;//number of days
		double YearsSince1970 = DaysSince1970 / 365.25;//number of years
		double ThisYeardouble = 1970 + YearsSince1970;
		DateFinder.ThisYearInt = static_cast<int>(ThisYeardouble);
		int FebruaryDays = 0;

		//Find number of seconds since new years
		float SecondsSinceNewYears = SecondsSince1970 - (static_cast<float>(DateFinder.ThisYearInt) - 1970) * 60 * 60 * 24 * 365.25;
		int DaysSinceNewYears = static_cast<int>(SecondsSinceNewYears / (60 * 60 * 24)) + 1;

		//Month Name

		//Check for leap year

		int LeapYearCheck = DateFinder.ThisYearInt - 1972; // First leap year since 1970: 1972

		if (LeapYearCheck % 4 == 0)
		{
			DateFinder.LeapYear = 0;
		}
		else
		{
			DateFinder.LeapYear = 29;
		}
		//Identify Month
		string CurrentMonthName[13] = { "SecretLevelMonth", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
		int CurrentMonthDaysSum[13] = { 9, 31, FebruaryDays, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		int MonthDays[13][33] =


		{
			/*SecretLevelMonth*/{ 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0},
			/*January:*/{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 100},
			/*February*/{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,23,24,25,26,27,28,DateFinder.LeapYear,0, 0, 100},
			/*March*/ {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 100},
			/*April*/{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 0, 0, 100 },
			/*May*/ {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 100 },
			/*June*/{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 0, 0, 100 },
			/*July*/{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 100 },
			/*August*/{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 100 },
			/*September*/{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 0, 0, 100 },
			/*October*/ {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 100 },
			/*November*/ {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 0, 0, 100 },
			/*December*/ {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 100 }
		};

		//YearTimeFinder function
		void YearTimeFinder(int(TimePar))
		{
			SecondsToDate DateFinder;
			double SecondsSince1970 = time(NULL) + 14400;//Adjust for timezone- also 
			//double SecondsSince1970 = 454723200; //30 May 1984 //FAIL
			//double SecondsSince1970 = 454723200; //30 May 1984 //FAIL
			//double SecondsSince1970 = 1554076800; //00:00 1 April 2019 //FAIL
			//double SecondsSince1970 = 1554080400; //01:00 1 April 2019 //FAIL
			//double SecondsSince1970 = 1554087600; //03:00 1 April 2019 //FAIL
			//double SecondsSince1970 = 1554087600; //03:00 1 April 2019 //FAIL
			//double SecondsSince1970 = 1554098400; //06:00 1 April 2019 //WORKS



			double DaysSince1970 = ((SecondsSince1970 / 60) / 60) / 24;//number of days
			double YearsSince1970 = DaysSince1970 / 365.25;//number of years
			double ThisYeardouble = 1970 + YearsSince1970;
			DateFinder.ThisYearInt = static_cast<int>(ThisYeardouble);//Add floor to round down
			int FebruaryDays = 0;

			//Find number of seconds since new years
			double SecondsSinceNewYears = SecondsSince1970 - (static_cast<double>(DateFinder.ThisYearInt) - 1970) * 60 * 60 * 24 * 365.25;

			//Identify Day of the Year
			DateFinder.DaysSinceNewYears = static_cast<int>(SecondsSinceNewYears / (60 * 60 * 24)) + 1;


			//Check for leap year

			int LeapYearCheck = DateFinder.ThisYearInt - 1972; // First leap year since 1970: 1972

			if (LeapYearCheck % 4 == 0)
			{
				DateFinder.LeapYear = 29;
			}
			else
			{
				DateFinder.LeapYear = 0;
			}
			//Identify Month
			string CurrentMonthName[13] = { "SecretLevelMonth", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
			int CurrentMonthDaysSum[13] = { 0, 31, FebruaryDays, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			int SumofMonthDays[14] = { 0, 31, 31 + FebruaryDays, 62 + FebruaryDays, 92 + FebruaryDays, 123 + FebruaryDays, 153 + FebruaryDays, 184 + FebruaryDays, 215 + FebruaryDays, 245 + FebruaryDays, 276 + FebruaryDays, 306 + FebruaryDays,337 + FebruaryDays };


			int PriorMonthsDays = 0;
			DateFinder.DayOfMonth = 1;
			int YearMonthCheck = 1;
			while (PriorMonthsDays < DateFinder.DaysSinceNewYears)
			{

				/*if (MonthDays[YearMonthCheck][DayOfMonth] == 0)
				{
					DayOfMonth++;
				}
				*/

				if (MonthDays[YearMonthCheck][DateFinder.DayOfMonth] == 0)

				{
					YearMonthCheck++;
					DateFinder.DayOfMonth = 0;

				}

				DateFinder.DayOfMonth++;
				PriorMonthsDays++;
			}
			DateFinder.DayOfMonth--;

			DateFinder.CurrentMonth = CurrentMonthName[YearMonthCheck];

			int SecondsSinceMidnight = SecondsSinceNewYears - PriorMonthsDays * 24 * 60 * 60;
			int HoursSinceMidnight = SecondsSinceNewYears - PriorMonthsDays * 24 * 60 * 60;

			double Today[3] = { YearMonthCheck, DateFinder.DayOfMonth, DateFinder.ThisYearInt };




			//Identify Semester
			DateFinder.CurrentSemester = static_cast<double>(DateFinder.ThisYearInt);
			return;
		}
	};


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


	//SourceReaderFunction
	void SourceReader(int TimeStampArray[], string EmailAddressArray[], string SignatureArray[], int DateSignedArray[], string NamesArray[], string TraningsCompletedArray[], string FacultyorStudentArray[], string LabNameArray, string ProjectNameArray[]);

	/*Equipment::Equipment()
	{
	}
	*/
//}