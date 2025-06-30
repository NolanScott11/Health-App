/*This will be the back - end for a health and fitness app that allowes you to track weightlifting / workouts,
Along with meals. */ 


#include <iostream>
#include <iomanip>
#include <ctime>
#include "log.h"
#include <string>

using namespace std;

//Function prototypes
// 
//health page
void healthPage(vector<logs>);
//Fitness page
void fitnessPage(vector<logs>);

void logFood(vector<logs>);

//global variable
vector<logs> data;

int main()
{
	//variables for menu choices
	vector<logs> info;
	int input;
	//initial display setup
	do
	{
		time_t now = time(nullptr); // Get current time
		char buffer[26];            // Buffer for ctime_s
		ctime_s(buffer, sizeof(buffer), &now);
		std::string date(buffer);
		date = date.substr(4, 6) + date.substr(19, 23);
		cout << date;
		cout << "\n************** Health and Fitness App **************\n\n";
		cout << "Select 1 to go to the nutrition/health page. Select 2 for the fitness page. Type 0 to quit.\nPlease make selection:";
		
		cin >> input;
		//Checks input for valid selection
		while (input != 1 && input != 2 && input != 0)
		{
			cout << "Invalid choice. Input must be either 1 or 2. Select again:\n";
			cin.clear();
			cin.ignore(10000000000, '\n');
			cin >> input;
		}

		switch (input)
		{
		case 1:
			system("CLS");
			healthPage(info);
			break;
		case 2:
			system("CLS");
			fitnessPage(info);
			break;
		case 0: //Exits loop
			break;
		}
	} while (input != 0);










	system("pause");
	return 0;
}

//function definitions
//HealthPage function: Opens menu and switch case for Health page.
void healthPage(vector<logs> info)
{
	int input;
	do
	{
	cout << "************** Health Page **************\n\n";
	cout << left << setw(8) << " " << "Make selection:\n";
	cout << left << setw(8) << " " << "1: Log Food\n";
	cout << left << setw(8) << " " << "2: Create Food\n";
	cout << left << setw(8) << " " << "3: Create Meal\n";
	cout << left << setw(8) << " " << "4: Remove Food\n";
	cout << left << setw(8) << " " << "5: View goal for day\n";
	cout << left << setw(8) << " " << "6: Create/change goals\n";
	cout << left << setw(8) << " " << "7: Go back\n";
	cout << "\nPlease make selection:";

	cin >> input;
	//Checks input for valid selection
	while (input < 1 || input > 7)
	{
		cout << "Invalid choice. Input must be 1-7. Select again:\n";
		cin.clear();
		cin.ignore(10000000000, '\n');
		cin >> input;
	}
	switch (input)
	{
	case 1:
		system("CLS");
		logFood(info);
		break;
	case 2:
		break;
	case 3: 
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7: //Exits loop
		break;
	}
	} while (input != 7);

}

//fitnessPage function: Opens menu and switch case for fitness page.
void fitnessPage(vector<logs> info)
{
	int input;
	do
	{
		cout << "************** Fitness Page *************\n\n";
		cout << left << setw(8) << " " << "Make selection:\n";
		cout << left << setw(8) << " " << "1: Create Workout\n";
		cout << left << setw(8) << " " << "2: Add lifts\n";
		cout << left << setw(8) << " " << "3: AI model lift predicitons\n";
		cout << left << setw(8) << " " << "4: Go back\n";
		cout << "\nPlease make selection:";
		cin >> input;
		//Checks input for valid selection
		while (input < 1 || input > 4)
		{
			cout << "Invalid choice. Input must be 1-4. Select again:\n";
			cin.clear();
			cin.ignore(10000000000, '\n');
			cin >> input;
		}
		switch (input)
		{
		case 1:
			break;
		case 2:
			break;
		case 3: 
			break;
		case 4: //Exits loop
			break;
		}

	} while (input != 4);
}


//Create a log object for the first time for that date. Prompts user to add food objects to that date.
void logFood(vector<logs> info)
{
	
	time_t now = time(nullptr); // Get current time
	char buffer[26];            // Buffer for ctime_s
	ctime_s(buffer, sizeof(buffer), &now);
	std::string date(buffer);
	date = date.substr(4, 6) + date.substr(19, 23);
	logs number1(date);
	int i;
	bool flag = false;
	for (i = 0; i < info.size(); i++)
	{
		if (number1.getDate() == info[i].getDate())
		{
			flag = true;
			break;
		}

	}
	if (flag == false)
	{
		info.push_back(number1);
	}
	cout << "Food log options:\n 1. Quick Add(Add calories/protein/carbs manually).\n2. Select food to add.\n3. Go back.\n";
	int input;
	cin >> input;
	while (input < 1 || input > 3)
	{
		cout << "Invalid choice. Input must be 1-3. Select again:\n";
		cin.clear();
		cin.ignore(10000000000, '\n');
		cin >> input;
	}
	switch (input)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	}


}