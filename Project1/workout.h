//workout object which includes a group of lifts.
#pragma once
#include "lift.h"
#include <vector>
#include <string>
class workouts
{
public:
	//constructors
	workouts()
	{
		workoutName = "";
		minutes = 0;
	}
	workouts(std::string name, int m)
	{
		workoutName = name;
		minutes = m;
	}
	//setters
	void setWorkoutName(std::string name) { workoutName = name; }
	void setMinutes(int m) { minutes = m; }
	//getters
	std::string getWorkoutName() const { return workoutName; }
	int getMinutes() const { return minutes; }
	int getLiftCount() const { return (int)workout.size(); }
	lift getLift(int i) const { return workout[i]; }
	void addLift(lift l) { workout.push_back(l); }

private:
	std::vector<lift> workout;
	std::string workoutName;
	int minutes;
};