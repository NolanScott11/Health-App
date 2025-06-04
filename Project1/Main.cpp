/*This will be the back - end for a health and fitness app that allowes you to track weightlifting / workouts,
Along with meals. */ 


#include <iostream>
#include <iomanip>

using namespace std;

//Function prototypes
// 
//health page
void healthPage();
void fitnessPage();
//Fitness page

int main()
{
	//variables for menu choices
	int input;
	//initial display setup
	do
	{
		cout << "************** Health and Fitness App **************\n\n";
		cout << "Select 1 to go to the nutrition/health page. Select 2 for the fitness page. Type 0 to quit.\nPlease make selection:";
		
		cin >> input;
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
			healthPage();
			break;
		case 2:
			system("CLS");
			fitnessPage();
			break;
		case 0: //Exits loop
			break;
		}
	} while (input != 0);










	system("pause");
	return 0;
}

//function definitions
void healthPage()
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

}


void fitnessPage()
{
	cout << "************** Fitness Page *************\n\n";
	cout << left << setw(8) << " " << "Make selection:\n";
	cout << left << setw(8) << " " << "1: Create Workout\n";
	cout << left << setw(8) << " " << "2: Add lifts\n";
	cout << left << setw(8) << " " << "3: AI model lift predicitons\n";
	cout << left << setw(8) << " " << "4: Go back\n";
}