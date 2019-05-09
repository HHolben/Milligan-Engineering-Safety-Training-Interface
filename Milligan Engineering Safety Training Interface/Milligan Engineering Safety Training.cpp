/*
Project Name: Milligan Engineering Safety Training Interface
Author: Henry Holben
Description: A convenient interface that will allow Milligan College Engineering proffessors to check for students' lab equipment safety training
Most recent changes made on: 9 May 2019
*/

//set up
//#include "Interface_Standard_Header_File.h";




//Move set up stuff to Interface_Standard_Header_File.h   . Use the above command to use it in the main CPP file.
//#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <limits>
#include <cstring>
#include <string.h> //you need this to use strcopy_s
#include <stdlib.h> //  _countof
#include <new> // for dynamic arrays
//#pragma once
using namespace std;


//Global Variables




//Global variables for the seconds to date function





//Global Variables for equipment
struct Equipment
{
	double ThreeDPrint;
	double DrillPress;
	double FundToolBox;
	double SawBand;
	double SawCircular;
	double Solder;
};




//Global variables for equipment
//struct Student
//{
	//double Timestamp;
	//string EmailAddress;
string Signature;
string DateSigned;
//string FirstName;
//string LastName;
string NameOfTraining;


string FacultyOrStudent;
string ReasonForTraining;
string CourseName;
string LabName;
string ProjectName;
//}StudentNamesArray[NumberOfStudents];



string studentname;

//class for using csv contract file:
//class CSVContractFileVariables
//{
//public:
	/*
	CSVContractFileVariables();
	~CSVContractFileVariables();
	*/
string ColumnName[13] =
{
	"Secret Level",//0
	"Timestamp",//1
	"EmailAddress",//2
	"Signature",//3
	"DateSigned",//4
	"FirstName",//5
	"LastName",//6
	"Name Of Training",//7
	"Faculty Or Student?",//8
	"Reason For Training",//9
	"CourseName",//10
	"LabName",//11
	"ProjectName"//12
};



//private:
//};

int TimestampCSVColumn = 1;
int EmailAddressCSVColumn = 2;
int SignatureCSVColumn = 3;
int DateSignedColumn = 4;
int FirstNameCSVColumn = 5;
int LastNameCSVColumn = 6;
int NameOfTrainingCSVColumn = 7;
int FacultyOrStudentCSVColumn = 8;
int ReasonForTrainingCSVColumn = 9;
int CourseNameCSVColumn = 10;
int LabNameCSVColumn = 11;
int ProjectNameCSVColumn = 12;











int main()
{


	//Say the date

	//class DateClass
	//{
	//public:
		int ThisYearInt;
		double CurrentSemester;
		int Timepar;
		string CurrentMonth;
		int DayOfMonth;
		int DaysSinceNewYears;
		double ThreeDPrintOne;
		int LeapYear;


		double SecondsSince1970 = time(NULL); //Uses time NULL to get the current date. 
		double DaysSince1970 = ((SecondsSince1970 / 60) / 60) / 24;//number of days
		double YearsSince1970 = DaysSince1970 / 365.25;//number of years
		double ThisYeardouble = 1970 + YearsSince1970;
		
		int FebruaryDays = 0;

	




		//Find number of seconds since new years
		ThisYearInt = static_cast<int>(ThisYeardouble);
		double SecondsSinceNewYears = SecondsSince1970 - (static_cast<float>(ThisYearInt) - 1970) * 60 * 60 * 24 * 365.25;
		DaysSinceNewYears = static_cast<int>(SecondsSinceNewYears / (60 * 60 * 24)) + 1;

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

		int MonthDays[13][33] =


		{
			/*SecretLevelMonth*/{ 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0},
			/*January:*/{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0, 100},
			/*February*/{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,23,24,25,26,27,28, LeapYear,0, 0, 100},
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

		int SumofMonthDays[14] = { 0, 31, 31 + FebruaryDays, 62 + FebruaryDays, 92 + FebruaryDays, 123 + FebruaryDays, 153 + FebruaryDays, 184 + FebruaryDays, 215 + FebruaryDays, 245 + FebruaryDays, 276 + FebruaryDays, 306 + FebruaryDays,337 + FebruaryDays };



		int PriorMonthsDays = 0;
		DayOfMonth = 1;
		int YearMonthCheck = 1;
		while (PriorMonthsDays < DaysSinceNewYears)
		{

			/*if (MonthDays[YearMonthCheck][DayOfMonth] == 0)
			{
				DayOfMonth++;
			}
			*/

			if (MonthDays[YearMonthCheck][DayOfMonth] == 0)

			{
				YearMonthCheck++;
				DayOfMonth = 0;

			}

			DayOfMonth++;
			PriorMonthsDays++;
		}
		DayOfMonth--;

		CurrentMonth = CurrentMonthName[YearMonthCheck];

		double Today[3] = { YearMonthCheck, DayOfMonth, ThisYearInt };



		int SecondsSinceMidnight = SecondsSinceNewYears - PriorMonthsDays * 24 * 60 * 60;
		int HoursSinceMidnight = SecondsSinceNewYears - PriorMonthsDays * 24 * 60 * 60;






		//Identify Semester
		CurrentSemester = static_cast<double>(ThisYearInt);

	cout << "Today's Date is "<< YearMonthCheck <<" "<< DayOfMonth << " "<<ThisYearInt;




	//go through the safety contract

	//check if file is good

	int NumberOfColumns;
	ifstream safetycontract;
	safetycontract.open("MilliganSafetyContract.csv");


	if (safetycontract.is_open())
	{


		//next? - look at page 355
		cout << "InStream is working. \n";


		//Assign file input to dynamic array
			//PROBLEM: the file reads the first column incorrectly: to fix this we need to get it to detect a return at the end of the line.
		int NumberOfColumns = 12;
		int NumberOfRows = 50;


		//Lets build an array!
		string DataArray[13][50];




		bool FoundNumberofRows = false;

		int ColumnNumber = 1;
		int RowNumber = 1;


		//First we have to read the entire row
		while (RowNumber <= NumberOfRows)
		{
			//	cout << "\n" << " (" << ColumnNumber << ", " << RowNumber << ") " << "\n \n";

			std::string Row;
			getline(safetycontract, Row, '\n');


			//Now we need to break the row up into comma seperated items

			//Decide how long the arrays should be.
			const int RowLength = 300; // .length finds the lenght of the string row
			const int MaxStringLength = 20; //max length of strings to be stored 


			//set up an array to store all characters from the Row string
			char RowChar[RowLength];
			Row.copy(RowChar, Row.length() + 1);


			int NumberOfCommas = 0;

			for (int RowCharCount = 0;RowCharCount <= RowLength + 1; RowCharCount++)//this for loop is for finding the number of columns
			{
				if (RowChar[RowCharCount] == 44) //checks if the index it is looking at contains an apostrophe or a return
				{

					//if it finds a comma, count it
					NumberOfCommas++;
					//cout <<NumberOfCommas<<"\n \n";

					//We have the number of columns. Now 
				}
			}
			//cout << "\n \n";

			// Now we make a similar For loop and use the now known number of commas to parse through the row and create small char arrays of each item

			char ItemChar[MaxStringLength];//this  array holds a smaller 1d character array to convert into a string. Also note the 40 limits character in



			for (int RowCharCount = 0;RowCharCount <= RowLength + 1; RowCharCount++)
			{
				//Now we to break the character array up into items



				while (RowChar[RowCharCount] != 44) //unless this character is a comma, we want to put it in the little char array
				{
					ItemChar[RowCharCount] = RowChar[RowCharCount];
					RowCharCount++;
				}


				//cout << RowChar[RowCharCount];

			}



			//string constructor, converts the char array into a string.
			std::string Item(ItemChar);
			std::cout << Item << "\n";

			//Now we need to put the string into the data array

			DataArray[ColumnNumber][RowNumber] = Item;


			RowNumber++;


			//-------------------------------------------------------------------------------------------------------------------------------------------------------


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
				cout << "\n \n -----------Home Menu----------- \n \n";
				cout << "Students or Training?";
				cout << "\n Students \t 1";
				cout << "\n Training \t 2";
				cout << "\n Print all \t 3";
				cout << "\n Quit \t \t 4 \n \n";

				cout << "------------------------------- \n";
				cin >> option1;

				//But what if the user enters the wrong value type?
				if (cin.fail()) //if cin fails
				{
					cin.clear(); //clears the bad input
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignores the bad input
				}





				//Let's find some students

				if (option1 == 1)
				{
					//Look through column 3: signature
					for (int StudentSearch = 1; StudentSearch < NumberOfRows; StudentSearch++)
					{



					}




					cout << "\n --------------Students-------------- \n";
					cout << "\n \n Who are you looking for? \n";
					cin >> studentname;


					// Relate input name to a number
					int NameSearchIteration;
					for (NameSearchIteration = 0;NameSearchIteration <= NumberOfRows + 1;NameSearchIteration++)
					{
						if (DataArray[3][NameSearchIteration] == studentname)//Remember column 3 is the signature
						{
							studentnumber = NameSearchIteration; //We found them!
							cout << "\n" << studentname << " is student number " << studentnumber;

							cout << studentname << "\t has completed \t \n \n \n";
						}
						if (NameSearchIteration > NumberOfRows)
						{
							"\n \n No student was found by that name.";
						}
					};

					
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




				}
				//Dump students and trainings enrolled
				if (option1 == 3)
				{

					//File output

					ofstream outStream;
					outStream.open(("Milligan Engineering Safety Training List.txt"), ios::out);

					if (outStream.is_open())
					{
		
						for (int RowSearchIteration=1; RowSearchIteration <= NumberOfRows; RowSearchIteration++)
						{


							for (int ColumnSearchIteration=1; ColumnSearchIteration <= NumberOfColumns; ColumnSearchIteration++)
							{
								outStream << DataArray[ColumnSearchIteration][RowSearchIteration];
								cout << "The Write out list has been updated. \n";

							}

							
						}
						outStream.close();


					}

				
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




		}




		return(0);
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


