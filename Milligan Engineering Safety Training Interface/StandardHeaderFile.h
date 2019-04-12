#pragma once

//set up

#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
#include <limits>

using namespace std;


//Variables for using csv contract file:

const int NumberOfColumns = 12;

/*

class CSVContractFileVariables
{
public: GetCSVFileData();

*/
const string ColumnName[NumberOfColumns + 1] = { "Secret Level",//0
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
									"ProjectName" };//12



/*};*/
