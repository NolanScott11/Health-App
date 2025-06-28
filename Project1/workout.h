//workout object which includes a group of lifts.

#pragma once
#include "lift.h"
#include <vector>
#include "Date.h"

class workouts
{
public:
	//constructors

	//default 
	workouts()
	{
		workoutNum = 0;
		date = NULL;
		minutes = 0;
	}

	//multi-argument
	workout(int num, Date d, int m)
	{
		workoutNum = num;
		date = d;
		minutes = m;
	}
	//setters
	void setWorkoutNum(int num)
	{
		workoutNum = num;
	}
	void setDate(Date d)
	{
		date = d;
	}
	void setMinutes(int m)
	{
		minutes = m;
	}
	//getters
	int getWorkoutNum()
	{
		return workoutNum;
	}
	Date getDate()
	{
		return date;
	}
	int getMinutes()
	{
		return minutes;
	}
	void addLift(lift l)
	{
		workout.push_back(l)
	}

private:
	std::vector<lift> workout;
	int workoutNum;
	Date date;
	int minutes;
};