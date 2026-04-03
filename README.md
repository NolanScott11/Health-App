# Health & Fitness Tracker

A C++ console application for tracking daily nutrition and weightlifting workouts. Logs food intake with full macro breakdowns, tracks lifts over time, and persists all data between sessions.

---

## Features

### Nutrition Tracking
- **Log Food** — Quick-add any food by entering calories, protein, fat, and carbs manually
- **Food Database Search** — Search a local database of saved foods by name (case-insensitive)
- **Create Food** — Add new foods to the local database for reuse
- **Remove Food** — Delete a food entry from today's log
- **Daily Goals** — Set calorie and macro targets; view a progress table showing eaten vs. remaining

### Workout Tracking
- **Quick Add Lift** — Log any lift with weight, reps, and sets
- **Create Workout** — Build a named workout session (e.g. "Push Day") with multiple lifts at once
- **View Progress** — Browse lift history by date across all logged sessions

### Persistence
- All data is automatically saved to `data.txt` on exit and reloaded on startup — no data is lost between sessions
- Daily nutrition goals are saved separately in `goals.txt`
- The food database is stored in `foodDatabase.txt` and grows as you add foods

---

## Project Structure

```
├── main.cpp           # All application logic and menus
├── food.h             # Food class (name, calories, protein, fat, carbs)
├── lift.h             # Lift class (name, weight, reps, sets)
├── log.h              # Logs class (daily container for foods and lifts)
├── workout.h          # Workouts class (named group of lifts)
├── data.txt           # Auto-generated save file (created on first run)
├── goals.txt          # Auto-generated goals file (created when goals are set)
└── foodDatabase.txt   # Food database (created when first food is added)
```

---

## Getting Started

### Requirements
- Windows (uses `system("CLS")` and `ctime_s`)
- Visual Studio 2019 or later (C++17)

### Build & Run
1. Clone or download the repository
2. Open the folder in Visual Studio as an existing project, or create a new **Console App** project and add all `.h` and `.cpp` files
3. Set the C++ standard to **C++17** — in project properties: `Configuration Properties → General → C++ Language Standard → ISO C++17`
4. Build and run with **Ctrl+F5**

### First Run
On first launch `data.txt`, `goals.txt`, and `foodDatabase.txt` will not exist yet — this is fine. They are created automatically as you use the app.

---

## Usage

### Main Menu
```
Apr  3 2026
************** Health and Fitness App **************

1: Nutrition / Health page
2: Fitness page
0: Quit
```

### Logging a Food (Quick Add)
```
Food log options:
1: Quick Add (enter nutrition manually)
2: Search food database
3: Go back

Food name: Chicken Breast
Calories: 165
Protein (g): 31
Fat (g): 4
Carbs (g): 0

Food logged!
```

### Viewing Daily Goal Progress
```
*** Today's Progress: Apr  3 2026 ***

Nutrient    Eaten     Goal      Remaining
------------------------------------------
Calories    820       2200      1380
Protein(g)  65        180       115
Fat(g)      28        60        32
Carbs(g)    90        250       160
```

### Logging a Workout
```
Enter workout name: Push Day
How many lifts do you want to add? 2

Lift 1 name: Bench Press
Weight (lbs): 185
Reps: 8
Sets: 4

Lift 2 name: Overhead Press
Weight (lbs): 115
Reps: 10
Sets: 3

Workout "Push Day" with 2 lift(s) logged!
```

---

## Data File Format

`data.txt` uses a simple structured format:

```
LOG Apr  3 2026
FOOD Chicken Breast|165|31|4|0
FOOD Brown Rice|215|5|2|45
LIFT Bench Press|185|8|4
LIFT Squat|225|5|3
ENDLOG
```

`foodDatabase.txt` uses tab-separated values:
```
Chicken Breast	165	31	4	0
Brown Rice	215	5	2	45
Eggs	70	6	5	0
```

---

## License

This project is for personal/educational use.
