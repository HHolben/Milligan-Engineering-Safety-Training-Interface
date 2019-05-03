/*
Project Name: Milligan Engineering Safety Training Interface
Author: Henry Holben
Description: A convenient interface that will allow Milligan College Engineering proffessors to check for students' lab equipment safety training
Most recent changes made on: 3 May 2019
*/

//set up




//Move set up stuff to Interface_Standard_Header_File.h   . Use the above command to use it in the main CPP file.

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <limits>
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
	cout << "Hello World! \n \n \n";

	//Create dynamic arrays to handle data

	/*
	//
	(value type) *ArrayName;

	ArrayName = new (value type)[Number of items in array]

		ArrayName[number] = value;

	delete[] ArrayName;
	*/




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
			cout << "\n" << " (" << ColumnNumber << ", " << RowNumber << ") " << "\n \n";

			string row;
			getline(safetycontract, row, '\n');

			cout << row;
			//Now we need to break the row up into comma seperated items


			std::string delimiter = ",";
			std::string item = row.substr(0, row.find(delimiter));



			cout << "\n \n" << item << "\n \n";
			DataArray[ColumnNumber][RowNumber] = item;

			RowNumber++;
		}



		int x;
		cin >> x;

		int y;
		cin >> y;

		cout << DataArray[x][y] << "/n";



		//delete all dynamic arrays















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





/*
Student::CSVContractFileVariables::CSVContractFileVariables()
{

}

Student::CSVContractFileVariables::~CSVContractFileVariables()
{

}

*/



