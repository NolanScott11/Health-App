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
	//operator overloads
	 friend std::ostream& operator<<(std::ostream& out, const logs& l)
	{
			 out << "Food number " << (l.log.size());
			 out << l.log[l.log.size() - 1];

			 //out << "Lift number " << (l.exercise.size());
			 //out << l.exercise[l.exercise.size() - 1];
		 
		return out;
	}

	
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
	std::string getDate() const
	{
		return date;
	}
	int getSize() const
	{
		return log.size();
	}

	//other functions
	void addFood(food f) 
	{
		log.push_back(f);
	}

	void addLift(lift l)
	{
		exercise.push_back(l);
	}
	
	

private:
	std::vector<food> log;
	std::string date;
	std::vector<lift> exercise;

};