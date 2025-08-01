/*This will be the back - end for a health and fitness app that allowes you to track weightlifting / workouts,
Along with meals. */ 


#include <iostream>
#include <iomanip>
#include <ctime>
#include "log.h"
#include <string>
#include <fstream>

using namespace std;

//Function prototypes
// 
//health page
void healthPage(vector<logs>&);
//Fitness page
void fitnessPage(vector<logs>&);

//log a food that was eaten to store all nutritional information about it for that day.
void logFood(vector<logs>&);

//Log lift into whatever workout you did that day.
void addLift(vector<logs>&);

//View goal for the day, which will be total calories, protein, carbs, and fat.
void viewGoal(vector<logs>& info);

//View progress of workouts over time, such as weight lifted, reps, sets, etc.
void viewProgress(vector<logs>& info); 
//global variable
void createFoods(vector<logs>& info);

	//This function will create a food object and add it to the food vector.
	//This will be used to create a food database for the user to select from.
	//This is not implemented yet, but will be in the future.



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
void healthPage(vector<logs> &info)
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
		system("CLS");
		viewGoal(info);
		break;
	case 6:
		break;
	case 7: //Exits loop
		break;
	}
	} while (input != 7);

}

//fitnessPage function: Opens menu and switch case for fitness page.
void fitnessPage(vector<logs> &info)
{
	int input;
	do
	{
		cout << "************** Fitness Page *************\n\n";
		cout << left << setw(8) << " " << "Make selection:\n";
		cout << left << setw(8) << " " << "1: Create Workout\n";
		cout << left << setw(8) << " " << "2: Add lifts\n";
		cout << left << setw(8) << " " << "3: View workout progress\n";
		cout << left << setw(8) << " " << "4: AI model lift predicitons\n";
		cout << left << setw(8) << " " << "5: Go back\n";
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
			system("CLS");
			addLift(info);
			break;
		case 3: 
			break;
		case 4:
			break;
		case 5:
			break;
		}

	} while (input != 4);
}


//Create a log object for the first time for that date. Prompts user to add food objects to that date.
void logFood(vector<logs>& info)
{
	
	time_t now = time(nullptr); // Get current time
	char buffer[26];            // Buffer for ctime_s
	ctime_s(buffer, sizeof(buffer), &now);
	std::string date(buffer);
	date = date.substr(4, 6) + date.substr(19, 23);
	logs number1(date);
	food item;
	int i;
	bool flag = false;
	std::string name;
	int p;
	int c;
	int f;
	int cb;
	
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



	cout << "Food log options:\n1. Quick Add(Add calories/protein/carbs manually).\n2. Select food to add.\n3. Go back.\n";
	int input;
	cin >> input;
	while (input < 1 || input > 3)
	{
		cout << "Invalid choice. Input must be 1-3. Select again:\n";
		cin.clear();
		cin.ignore(10000000000, '\n');
		cin >> input;
	}
	
	ofstream file("Food.txt");
	switch (input)
	{
	case 1:
		cout << "Please enter food name: ";
		cin.ignore();
		getline(cin, name);
		item.setName(name);
		cout << "\nPlease enter the number of calories: ";
		cin >> c;
		item.setCals(c);
		cout << "\nPlease enter the grams of protein: ";
		cin >> p;
		item.setProtein(p);
		cout << "\nPlease enter the grams of fat: ";
		cin >> f;
		item.setFat(f);
		cout << "\nPlease enter the number of carbs: ";
		cin >> cb;
		item.setCarbs(cb);
		if (flag == true)
		{
			info[i].addFood(item);
			for (int j = 0; j < info[i].getFoodSize(); j++)
			{
				file << "Food number: " << (j + 1);
				file << info[i].getFood(j);
			}

			
		}
		else
		{
			info[info.size() - 1].addFood(item);
			for (int j = 0; j < info[info.size() - 1].getFoodSize(); j++)
			{
				file << "Food number: " << (j + 1);
				file << info[info.size() - 1].getFood(j);
			}
			
		}
			
		
		file.close();
		break;
	case 2:
		break;
	case 3:
		break;
	}


}

void addLift(vector<logs>& info)
{

	time_t now = time(nullptr); // Get current time
	char buffer[26];            // Buffer for ctime_s
	ctime_s(buffer, sizeof(buffer), &now);
	std::string date(buffer);
	date = date.substr(4, 6) + date.substr(19, 23);
	cout << date;
	logs number1(date);
	lift item;
	int i;
	bool flag = false;
	std::string name;
	int w;
	int r;
	int s;
	

	for (i = 0; i < info.size(); i++)
	{
		if (number1.getDate() == info[i].getDate())
		{
			cout << info[i].getDate() << "\n";
			flag = true;
			break;
		}
	}
	if (flag == false)
	{
		info.push_back(number1);
	}

	cout << "Add lift options:\n1. Quick Add(input weight/reps/sets manually).\n2. Select lift to add.\n3. Go back.\n";
	int input;
	cin >> input;
	while (input < 1 || input > 3)
	{
		cout << "Invalid choice. Input must be 1-3. Select again:\n";
		cin.clear();
		cin.ignore(10000000000, '\n');
		cin >> input;
	}
	ofstream file("data.txt");
	
	switch (input)
	{
	case 1:
		cout << "Please enter lift name: ";
		cin.ignore();
		getline(cin, name);
		item.setName(name);
		cout << "\nPlease enter the weight: ";
		cin >> w;
		item.setPounds(w);
		cout << "\nPlease enter the number of reps: ";
		cin >> r;
		item.setReps(r);
		cout << "\nPlease enter the number of sets: ";
		cin >> s;
		item.setSets(s);
		
		if (flag == true)
		{
			info[i].addLift(item);
			for (int j = 0; j < info[i].getLiftSize(); j++)
			{
				file << "Lift number: " << (j + 1);
				file << info[i].getLift(j);
			}
		}
		else
		{
			info[info.size() - 1].addLift(item);
			for (int j = 0; j < info[info.size() - 1].getLiftSize(); j++)
			{
				file << "Lift number: " << (j + 1);
				file << info[info.size() - 1].getLift(j);
			}
		}
		


		file.close();
		break;
	case 2:
		break;
	case 3:
		break;
	}

}

void viewGoal(vector<logs>& info)
{
	cout << "Today's progress:\n";
	int cals = 0;;
	int fat = 0;
	int pro = 0;
	int carbs = 0;
	if (info.size() == 0)
	{
		cout << "No logs for today.\n";
		return;
	}
	if (info[info.size() - 1].getFoodSize() == 0)
	{
		cout << "No food logged for today.\n";
	}
	else
	{
		for (int i = 0; i < info[info.size() - 1].getFoodSize(); i++)
		{
			cals += info[info.size() - 1].getFood(i).getCals();
			fat += info[info.size() - 1].getFood(i).getFat();
			pro += info[info.size() - 1].getFood(i).getProtein();
			carbs += info[info.size() - 1].getFood(i).getCarbs();
		}
		cout << "Total Calories: " << cals << "\n\n";
		cout << "Fat: " << fat << "\n";
		cout << "Protein: " << pro << "\n";
		cout << "Carbs: " << carbs << "\n";
	}
}



void viewProgress(vector<logs>& info)
{
	cout << "Today's workout progress:\n";
	if (info.size() == 0)
	{
		cout << "No logs for today.\n";
		return;
	}
	if (info[info.size() - 1].getLiftSize() == 0)
	{
		cout << "No lifts logged for today.\n";
	}
	else
	{
		for (int i = 0; i < info[info.size() - 1].getLiftSize(); i++)
		{
			cout << "Lift: " << info[info.size() - 1].getLift(i).getName() << "\n";
			cout << "Weight: " << info[info.size() - 1].getLift(i).getPounds() << "\n";
			cout << "Reps: " << info[info.size() - 1].getLift(i).getReps() << "\n";
			cout << "Sets: " << info[info.size() - 1].getLift(i).getSets() << "\n\n";
		}
	}

}

void createFoods(vector<logs>& info)
{

}