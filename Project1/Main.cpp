/*  Health and Fitness App - Backend
    Tracks weightlifting/workouts and meals with persistent save/load. */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits>
#include "log.h"

using namespace std;

//helpers
string todayDate()
{
    time_t now = time(nullptr);
    char buffer[26];
#ifdef _WIN32
    ctime_s(buffer, sizeof(buffer), &now);   // MSVC / Windows
#else
    ctime_r(&now, buffer);                   // GCC / Linux
#endif
    string d(buffer);
    return d.substr(4, 6) + d.substr(19, 5); // e.g. "Apr  2 2026"
}

void clearScreen() { system("CLS"); }

//function prototypes
void healthPage(vector<logs>&);
void fitnessPage(vector<logs>&);

void logFood(vector<logs>&);
void createFood();
void removeFood(vector<logs>&);
void viewGoal(vector<logs>&);
void createGoal();

void addLift(vector<logs>&);
void createWorkout(vector<logs>&);
void viewProgress(vector<logs>&);

bool findFoodInDatabase(const string& searchName, food& foundFood);

// save / load
void saveData(const vector<logs>& info);
void loadData(vector<logs>& info);

// goals file helpers
void saveGoals(int calGoal, int proGoal, int fatGoal, int carbGoal);
bool loadGoals(int& calGoal, int& proGoal, int& fatGoal, int& carbGoal);

//main
int main()
{
    vector<logs> info;
    loadData(info);          // restore previous sessions

    int input;
    do
    {
        cout << todayDate();
        cout << "\n************** Health and Fitness App **************\n\n";
        cout << "1: Nutrition / Health page\n";
        cout << "2: Fitness page\n";
        cout << "0: Quit\n";
        cout << "\nPlease make selection: ";
        cin >> input;

        while (input != 0 && input != 1 && input != 2)
        {
            cout << "Invalid choice. Enter 0, 1, or 2: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> input;
        }

        switch (input)
        {
        case 1: clearScreen(); healthPage(info);  break;
        case 2: clearScreen(); fitnessPage(info); break;
        case 0: break;
        }
    } while (input != 0);

    saveData(info);           // persist before exit
    cout << "Data saved. Goodbye!\n";
    system("pause");
    return 0;
}

//health page
void healthPage(vector<logs>& info)
{
    int input;
    do
    {
        cout << "************** Health Page **************\n\n";
        cout << left << setw(8) << " " << "1: Log Food\n";
        cout << left << setw(8) << " " << "2: Create Food (add to database)\n";
        cout << left << setw(8) << " " << "3: Remove Food from today\n";
        cout << left << setw(8) << " " << "4: View goal for day\n";
        cout << left << setw(8) << " " << "5: Create / Change goals\n";
        cout << left << setw(8) << " " << "6: Go back\n";
        cout << "\nPlease make selection: ";

        cin >> input;
        while (input < 1 || input > 6)
        {
            cout << "Invalid choice. Enter 1-6: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> input;
        }

        switch (input)
        {
        case 1: clearScreen(); logFood(info);    break;
        case 2: clearScreen(); createFood();     break;
        case 3: clearScreen(); removeFood(info); break;
        case 4: clearScreen(); viewGoal(info);   break;
        case 5: clearScreen(); createGoal();     break;
        case 6: break;
        }
    } while (input != 6);
}

//fitness page
void fitnessPage(vector<logs>& info)
{
    int input;
    do
    {
        cout << "************** Fitness Page **************\n\n";
        cout << left << setw(8) << " " << "1: Create Workout\n";
        cout << left << setw(8) << " " << "2: Add lifts (quick add)\n";
        cout << left << setw(8) << " " << "3: View workout progress\n";
        cout << left << setw(8) << " " << "4: Go back\n";
        cout << "\nPlease make selection: ";

        cin >> input;
        while (input < 1 || input > 4)
        {
            cout << "Invalid choice. Enter 1-4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> input;
        }

        switch (input)
        {
        case 1: clearScreen(); createWorkout(info);  break;
        case 2: clearScreen(); addLift(info);        break;
        case 3: clearScreen(); viewProgress(info);   break;
        case 4: break;
        }
    } while (input != 4);
}

//get or create today's log, return its index
int getTodayIndex(vector<logs>& info)
{
    string today = todayDate();
    for (int i = 0; i < (int)info.size(); i++)
        if (info[i].getDate() == today)
            return i;
    info.push_back(logs(today));
    return (int)info.size() - 1;
}

//log food
void logFood(vector<logs>& info)
{
    int idx = getTodayIndex(info);

    cout << "Food log options:\n";
    cout << "1: Quick Add (enter nutrition manually)\n";
    cout << "2: Search food database\n";
    cout << "3: Go back\n";
    cout << "\nSelection: ";

    int input;
    cin >> input;
    while (input < 1 || input > 3)
    {
        cout << "Invalid. Enter 1-3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
    }

    if (input == 3) return;

    food item;

    if (input == 1)
    {
        string name;
        int c, p, f, cb;
        cout << "Food name: ";
        cin.ignore();
        getline(cin, name);
        item.setName(name);
        cout << "Calories: ";  cin >> c;  item.setCals(c);
        cout << "Protein (g): "; cin >> p; item.setProtein(p);
        cout << "Fat (g): ";    cin >> f;  item.setFat(f);
        cout << "Carbs (g): ";  cin >> cb; item.setCarbs(cb);
        info[idx].addFood(item);
        cout << "\nFood logged!\n";
    }
    else // input == 2
    {
        string searchName;
        cout << "Enter food name to search: ";
        cin.ignore();
        getline(cin, searchName);
        food found;
        if (findFoodInDatabase(searchName, found))
        {
            cout << "\nFound: " << found.getName()
                << "  Cal:" << found.getCals()
                << "  Pro:" << found.getProtein()
                << "  Fat:" << found.getFat()
                << "  Carbs:" << found.getCarbs() << "\n";
            cout << "Add this food? (1=Yes / 2=No): ";
            int confirm; cin >> confirm;
            if (confirm == 1)
            {
                info[idx].addFood(found);
                cout << "Food logged!\n";
            }
        }
        else
        {
            cout << "Food not found in database.\n";
        }
    }
    system("pause");
}

//create food (add to database)
void createFood()
{
    string name;
    int c, p, f, cb;
    cout << "*** Add Food to Database ***\n";
    cout << "Food name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Calories: ";   cin >> c;
    cout << "Protein (g): "; cin >> p;
    cout << "Fat (g): ";    cin >> f;
    cout << "Carbs (g): ";  cin >> cb;

    // Check for duplicate
    food dummy;
    if (findFoodInDatabase(name, dummy))
    {
        cout << "That food already exists in the database.\n";
        system("pause");
        return;
    }

    ofstream file("foodDatabase.txt", ios::app);
    if (!file.is_open())
    {
        cout << "Error opening foodDatabase.txt\n";
        system("pause");
        return;
    }
    file << name << "\t" << c << "\t" << p << "\t" << f << "\t" << cb << "\n";
    file.close();
    cout << name << " added to database.\n";
    system("pause");
}

//remove food from today
void removeFood(vector<logs>& info)
{
    int idx = getTodayIndex(info);

    if (info[idx].getFoodSize() == 0)
    {
        cout << "No food logged today.\n";
        system("pause");
        return;
    }

    cout << "*** Today's food log ***\n";
    for (int i = 0; i < info[idx].getFoodSize(); i++)
    {
        cout << (i + 1) << ": " << info[idx].getFood(i).getName()
            << "  (" << info[idx].getFood(i).getCals() << " cal)\n";
    }
    cout << "\nEnter the number of the food to remove (0 to cancel): ";
    int choice;
    cin >> choice;
    if (choice < 1 || choice > info[idx].getFoodSize())
    {
        cout << "Cancelled.\n";
    }
    else
    {
        cout << info[idx].getFood(choice - 1).getName() << " removed.\n";
        info[idx].removeFood(choice - 1);
    }
    system("pause");
}

//view goal
void viewGoal(vector<logs>& info)
{
    int calGoal = 0, proGoal = 0, fatGoal = 0, carbGoal = 0;
    bool hasGoal = loadGoals(calGoal, proGoal, fatGoal, carbGoal);

    int idx = getTodayIndex(info);
    int cals = 0, fat = 0, pro = 0, carbs = 0;

    for (int i = 0; i < info[idx].getFoodSize(); i++)
    {
        cals += info[idx].getFood(i).getCals();
        fat += info[idx].getFood(i).getFat();
        pro += info[idx].getFood(i).getProtein();
        carbs += info[idx].getFood(i).getCarbs();
    }

    cout << "*** Today's Progress: " << todayDate() << " ***\n\n";

    if (info[idx].getFoodSize() == 0)
        cout << "No food logged yet today.\n\n";

    if (hasGoal)
    {
        cout << left << setw(12) << "Nutrient"
            << setw(10) << "Eaten"
            << setw(10) << "Goal"
            << "Remaining\n";
        cout << string(42, '-') << "\n";
        cout << left << setw(12) << "Calories"
            << setw(10) << cals
            << setw(10) << calGoal
            << (calGoal - cals) << "\n";
        cout << left << setw(12) << "Protein(g)"
            << setw(10) << pro
            << setw(10) << proGoal
            << (proGoal - pro) << "\n";
        cout << left << setw(12) << "Fat(g)"
            << setw(10) << fat
            << setw(10) << fatGoal
            << (fatGoal - fat) << "\n";
        cout << left << setw(12) << "Carbs(g)"
            << setw(10) << carbs
            << setw(10) << carbGoal
            << (carbGoal - carbs) << "\n";
    }
    else
    {
        cout << "Calories: " << cals << "\n";
        cout << "Protein:  " << pro << " g\n";
        cout << "Fat:      " << fat << " g\n";
        cout << "Carbs:    " << carbs << " g\n";
        cout << "\n(No goals set. Use 'Create / Change goals' to set them.)\n";
    }
    cout << "\n";
    system("pause");
}

//create / change goals
void createGoal()
{
    int c, p, f, cb;
    cout << "*** Set Daily Goals ***\n";
    cout << "Calorie goal: ";   cin >> c;
    cout << "Protein goal (g): "; cin >> p;
    cout << "Fat goal (g): ";   cin >> f;
    cout << "Carbs goal (g): "; cin >> cb;
    saveGoals(c, p, f, cb);
    cout << "Goals saved!\n";
    system("pause");
}

//add lift (quick add) 
void addLift(vector<logs>& info)
{
    int idx = getTodayIndex(info);

    cout << "Add lift options:\n";
    cout << "1: Quick Add (enter manually)\n";
    cout << "2: Go back\n";
    cout << "\nSelection: ";
    int input;
    cin >> input;
    while (input < 1 || input > 2)
    {
        cout << "Invalid. Enter 1 or 2: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> input;
    }
    if (input == 2) return;

    string name;
    int w, r, s;
    cout << "Lift name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Weight (lbs): "; cin >> w;
    cout << "Reps: ";         cin >> r;
    cout << "Sets: ";         cin >> s;

    lift item(name, w, r, s);
    info[idx].addLift(item);
    cout << "\nLift logged!\n";
    system("pause");
}

//create workout (named group of lifts)  
void createWorkout(vector<logs>& info)
{
    int idx = getTodayIndex(info);

    string workoutName;
    cout << "*** Create Workout ***\n";
    cout << "Enter workout name (e.g. 'Chest Day', 'Pull Day'): ";
    cin.ignore();
    getline(cin, workoutName);

    int numLifts;
    cout << "How many lifts do you want to add? ";
    cin >> numLifts;
    while (numLifts < 1)
    {
        cout << "Must add at least 1 lift: ";
        cin >> numLifts;
    }

    cout << "\nEnter each lift:\n";
    for (int i = 0; i < numLifts; i++)
    {
        string name;
        int w, r, s;
        cout << "\nLift " << (i + 1) << " name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Weight (lbs): "; cin >> w;
        cout << "Reps: ";         cin >> r;
        cout << "Sets: ";         cin >> s;

        lift item(name, w, r, s);
        info[idx].addLift(item);
    }

    cout << "\nWorkout \"" << workoutName << "\" with " << numLifts << " lift(s) logged!\n";
    system("pause");
}

// ── view workout progress ─────────────────────────────────────────────────────
void viewProgress(vector<logs>& info)
{
    cout << "*** Workout Progress ***\n\n";

    if (info.empty())
    {
        cout << "No logs found.\n";
        system("pause");
        return;
    }

    // List all dates that have lifts
    vector<int> datesWithLifts;
    for (int i = 0; i < (int)info.size(); i++)
        if (info[i].getLiftSize() > 0)
            datesWithLifts.push_back(i);

    if (datesWithLifts.empty())
    {
        cout << "No lifts logged yet.\n";
        system("pause");
        return;
    }

    cout << "Select a date to view:\n";
    for (int i = 0; i < (int)datesWithLifts.size(); i++)
        cout << (i + 1) << ": " << info[datesWithLifts[i]].getDate() << "\n";
    cout << "0: View today only\n\nSelection: ";

    int choice;
    cin >> choice;

    int idx;
    if (choice == 0)
    {
        idx = getTodayIndex(info);
    }
    else if (choice >= 1 && choice <= (int)datesWithLifts.size())
    {
        idx = datesWithLifts[choice - 1];
    }
    else
    {
        cout << "Invalid selection.\n";
        system("pause");
        return;
    }

    cout << "\n--- " << info[idx].getDate() << " ---\n";
    if (info[idx].getLiftSize() == 0)
    {
        cout << "No lifts logged for this date.\n";
    }
    else
    {
        for (int i = 0; i < info[idx].getLiftSize(); i++)
        {
            lift l = info[idx].getLift(i);
            cout << "\nLift " << (i + 1) << ": " << l.getName() << "\n";
            cout << "  Weight: " << l.getPounds() << " lbs\n";
            cout << "  Reps:   " << l.getReps() << "\n";
            cout << "  Sets:   " << l.getSets() << "\n";
        }
    }
    cout << "\n";
    system("pause");
}

// ── food database search ──────────────────────────────────────────────────────
bool findFoodInDatabase(const string& searchName, food& foundFood)
{
    ifstream file("foodDatabase.txt");
    if (!file.is_open()) return false;

    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        string name, calsStr, proteinStr, fatStr, carbsStr;
        if (getline(iss, name, '\t') &&
            getline(iss, calsStr, '\t') &&
            getline(iss, proteinStr, '\t') &&
            getline(iss, fatStr, '\t') &&
            getline(iss, carbsStr, '\t'))
        {
            string lowerName = name, lowerSearch = searchName;
            transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
            transform(lowerSearch.begin(), lowerSearch.end(), lowerSearch.begin(), ::tolower);

            if (lowerName == lowerSearch)
            {
                foundFood = food(name, stoi(proteinStr), stoi(calsStr), stoi(fatStr), stoi(carbsStr));
                return true;
            }
        }
    }
    return false;
}

// ── save all logs to savedata.txt ─────────────────────────────────────────────
// Format per log:
//   LOG <date>
//   FOOD <name>|<cals>|<protein>|<fat>|<carbs>
//   LIFT <name>|<pounds>|<reps>|<sets>
//   ENDLOG
void saveData(const vector<logs>& info)
{
    ofstream file("data.txt");
    if (!file.is_open())
    {
        cerr << "Could not open data.txt for writing.\n";
        return;
    }
    for (int i = 0; i < (int)info.size(); i++)
    {
        file << "LOG " << info[i].getDate() << "\n";
        for (int j = 0; j < info[i].getFoodSize(); j++)
        {
            food f = info[i].getFood(j);
            file << "FOOD " << f.getName() << "|"
                << f.getCals() << "|"
                << f.getProtein() << "|"
                << f.getFat() << "|"
                << f.getCarbs() << "\n";
        }
        for (int j = 0; j < info[i].getLiftSize(); j++)
        {
            lift l = info[i].getLift(j);
            file << "LIFT " << l.getName() << "|"
                << l.getPounds() << "|"
                << l.getReps() << "|"
                << l.getSets() << "\n";
        }
        file << "ENDLOG\n";
    }
    file.close();
}

// ── load all logs from savedata.txt ──────────────────────────────────────────
void loadData(vector<logs>& info)
{
    ifstream file("data.txt");
    if (!file.is_open()) return; // first run, no file yet

    string line;
    while (getline(file, line))
    {
        if (line.substr(0, 4) == "LOG ")
        {
            string date = line.substr(4);
            logs entry(date);

            while (getline(file, line) && line != "ENDLOG")
            {
                if (line.substr(0, 5) == "FOOD ")
                {
                    istringstream iss(line.substr(5));
                    string name, cStr, pStr, fStr, cbStr;
                    if (getline(iss, name, '|') &&
                        getline(iss, cStr, '|') &&
                        getline(iss, pStr, '|') &&
                        getline(iss, fStr, '|') &&
                        getline(iss, cbStr))
                    {
                        entry.addFood(food(name, stoi(pStr), stoi(cStr), stoi(fStr), stoi(cbStr)));
                    }
                }
                else if (line.substr(0, 5) == "LIFT ")
                {
                    istringstream iss(line.substr(5));
                    string name, pStr, rStr, sStr;
                    if (getline(iss, name, '|') &&
                        getline(iss, pStr, '|') &&
                        getline(iss, rStr, '|') &&
                        getline(iss, sStr))
                    {
                        entry.addLift(lift(name, stoi(pStr), stoi(rStr), stoi(sStr)));
                    }
                }
            }
            info.push_back(entry);
        }
    }
    file.close();
}

// ── goals file helpers ────────────────────────────────────────────────────────
void saveGoals(int calGoal, int proGoal, int fatGoal, int carbGoal)
{
    ofstream file("goals.txt");
    if (!file.is_open()) return;
    file << calGoal << "\n" << proGoal << "\n" << fatGoal << "\n" << carbGoal << "\n";
    file.close();
}

bool loadGoals(int& calGoal, int& proGoal, int& fatGoal, int& carbGoal)
{
    ifstream file("goals.txt");
    if (!file.is_open()) return false;
    file >> calGoal >> proGoal >> fatGoal >> carbGoal;
    return !file.fail();
}