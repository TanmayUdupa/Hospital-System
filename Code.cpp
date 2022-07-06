#include <iostream>
using namespace std;

//Function to add patient's name under the specialization passed as argument
void add(string hospital[20][5], int specialisation, string name, int urgency)
{
	int i = specialisation - 1;

	bool b = 1;
	for (int j = 0; j < 5; j++)
	{
		if (hospital[i][j] == "")
		{
			b = 0;
		}
	}

	//Condition to check if all 5 spots in the specialization is filled
	if (b)
	{
		cout << "Sorry we can't add more patients for this specialization\n";
		return;
	}

	//If urgency = 1, patient is added at the beginning of the queue of patients. If urgency = 0, added at the end
	if (urgency)
	{
		for (int j = 4; j > 0; j--)
		{
			if (hospital[i][j] == "" && hospital[i][j - 1] != "")
			{
				string temp = hospital[i][j];
				hospital[i][j] = hospital[i][j - 1];
				hospital[i][j - 1] = temp;
			}
		}

		hospital[i][0] = name + " urgent";
	}
	else
	{
		for (int j = 0; j < 5; j++)
		{
			if (hospital[i][j] == "")
			{
				hospital[i][j] = name + " regular";
				break;
			}
		}
	}
}

//Function to display all the patients in all the specializations
void display(string hospital[20][5])
{
	cout << "****************************\n";

	for (int i = 0; i < 20; i++)
	{
		if (hospital[i][0] != "")
		{
			int count = 0;
			for (int j = 0; j < 5; j++)
			{
				if (hospital[i][j] == "")
				{
					break;
				}

				count++;
			}

			cout << "There are " << count << " patients in specialisation " << i + 1 << endl;
			for (int j = 0; j < count; j++)
			{
				cout << hospital[i][j] << endl;
			}

			cout << endl;
		}
	}
}

//Function to remove a patient from the queue after he is called by the doctor
void get_patient(string hospital[20][5], int specialisation)
{
	int i = specialisation - 1;

	//Checks if there are no patients in the respective specialization
	if (hospital[i][0] == "")
	{
		cout << "No patients at the moment. Have rest, Dr\n\n";
		return;
	}

	string name1 = "";
	int size = hospital[i][0].size();
	for (int j = 0; j < size; j++)
	{
		if (hospital[i][0][j] == ' ')
		{
			break;
		}

		name1 += hospital[i][0][j];
	}
	cout << name1 << " please go with the Dr\n\n";

	hospital[i][0] = "";

	for (int j = 1; j < 5; j++)
	{
		if (hospital[i][j] == "")
		{
			break;
		}

		string temp = hospital[i][j - 1];
		hospital[i][j - 1] = hospital[i][j];
		hospital[i][j] = temp;
	}
}


int main()
{
	int specialisation, urgency, choice;
	string name;
	string hospital[20][5] = {""};

	do
	{
		//Displaying menu to the user
		cout << "Enter your choice:\n1) Add new patient\n";
		cout << "2) Print all patients\n3) Get next patient\n";
		cout << "4) Exit\n";
		cin >> choice;

		switch (choice)
		{
		//User wants to add a patient
		case 1:
			cout << "Enter specialization, name, status: ";
			cin >> specialisation >> name >> urgency;
			add(hospital, specialisation, name, urgency);
			cout << endl;
			break;

		//User wants to display patients in all specializations
		case 2:
			display(hospital);
			cout << endl;
			break;

		//User wants to remove a patient from the queue after he has been called by the doctor
		case 3:
			cout << "Enter specialization: ";
			cin >> specialisation;
			get_patient(hospital, specialisation);
			break;

		//User wants to exit
		case 4:
			return 0;
			break;

		default:
			cout << "Invalid choice!!!\n\n";
		}
	}while(true);

	return 0;
}
