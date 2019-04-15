#pragma once
#include "StandardHeaderFile.h"


class TraineesClass
{
	//Add inheritence: Create new classes for Students and Instructors


public:
	TraineesClass();
	void TrainingSearch();
	~TraineesClass();

private:
	string Signature[100] = { "Brutus Buffalo", "Bob", "Sue", "Joe" };
	string DateSigned[100];
	string NameOfTraining[100];
	string studentname;

	


};
