#pragma once
//log object which includes a vector of foods.

#pragma once
#include "food.h"
#include <vector>
#include "Date.h"
#include "workout.h"

class logs
{
public:
	//constructors

	//default 
	logs()
	{
		date = "";
	}

	//multi-argument
	logs(std::string d)
	{
		date = d;
	}
	//setters
	void setDate(std::string d)
	{
		date = d;
	}

	//getters
	std::string getDate()
	{
		return date;
	}
	void addFood(food f)
	{
		log.push_back(f);
	}

private:
	std::vector<food> log;
	std::string date;
	std::vector<workouts> exercise;

};