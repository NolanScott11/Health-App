//workout object which includes a group of lifts.

#pragma once
#include "lift.h"
#include <vector>


class workouts
{
public:
	//constructors

	//default 
	workouts()
	{
		workoutNum = 0;
		minutes = 0;
	}

	//multi-argument
	workouts(int num, int m)
	{
		workoutNum = num;
		
		minutes = m;
	}
	//setters
	void setWorkoutNum(int num)
	{
		workoutNum = num;
	}
	
	void setMinutes(int m)
	{
		minutes = m;
	}
	//getters
	int getWorkoutNum() const 
	{
		return workoutNum;
	}
	
	int getMinutes() const
	{
		return minutes;
	}
	void addLift(lift l)
	{
		workout.push_back(l);
	}

private:
	std::vector<lift> workout;
	int workoutNum;
	int minutes;
};