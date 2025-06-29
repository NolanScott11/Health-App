#pragma once
//log object which includes a vector of foods.

#pragma once
#include "food.h"
#include <vector>
#include "Date.h"

class logs
{
public:
	//constructors

	//default 
	logs()
	{
		date = NULL;
	}

	//multi-argument
	logs(Date d)
	{
		date = d;
	}
	//setters
	void setDate(Date d)
	{
		date = d;
	}

	//getters
	Date getDate()
	{
		return date;
	}
	void addFood(food f)
	{
		log.push_back(f);
	}

private:
	std::vector<food> log;
	Date date;

};