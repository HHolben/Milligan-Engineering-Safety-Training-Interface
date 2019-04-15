#include "TraineesClass.h"



TraineesClass::TraineesClass()//constructor
{

}


TraineesClass::~TraineesClass()//destructor
{
}

void TraineesClass::TrainingSearch() {

	cout << "--------------Students-------------- \n";
	cout << "\n \n Who are you looking for? \n";
	cin >> studentname;

	// StudentProfiles

	//read file
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
				if (ColumnNumber = 4)
				{
					if (line == studentname)
					{
						cout << "Huzzah!";
					}


				}


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

	}







/*			// training array: {0: solder trained? 1 or 0, 1: Month solder trained, 2: Day solder trained, 3: Year solder trained, 4: toolbox trained?, 5: Month toolbox trained, 6: Day toolbox trainined, 7: Year toolbox trained}
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
	

	
};*/

