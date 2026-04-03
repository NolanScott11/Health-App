A C++ console application for tracking daily nutrition and weightlifting workouts. Logs food intake with full macro breakdowns, tracks lifts over time, and persists all data between sessions.







## Project Structure

├── main.cpp           # All application logic and menus
├── food.h             # Food class (name, calories, protein, fat, carbs)
├── lift.h             # Lift class (name, weight, reps, sets)
├── log.h              # Logs class (daily container for foods and lifts)
├── workout.h          # Workouts class (named group of lifts)
├── data.txt           # Auto-generated save file (created on first run)
├── goals.txt          # Auto-generated goals file (created when goals are set)
└── foodDatabase.txt   # Food database (created when first food is added)
```






Apr  3 2026
************** Health and Fitness App **************

1: Nutrition / Health page
2: Fitness page
0: Quit
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

*** Today's Progress: Apr  3 2026 ***

Nutrient    Eaten     Goal      Remaining
------------------------------------------
Calories    820       2200      1380
Protein(g)  65        180       115
Fat(g)      28        60        32
Carbs(g)    90        250       160
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

LOG Apr  3 2026
FOOD Chicken Breast|165|31|4|0
FOOD Brown Rice|215|5|2|45
LIFT Bench Press|185|8|4
LIFT Squat|225|5|3
ENDLOG
Chicken Breast	165	31	4	0
Brown Rice	215	5	2	45
Eggs	70	6	5	0
```

---

## License

License
This project is for personal/educational use.
