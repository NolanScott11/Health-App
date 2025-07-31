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
		if (l.log.size() != 0)
		{
			for (int i = 0; i < l.log.size(); i++)
			{
				out << "Food number " << (i + 1);
				out << l.log[i];
			}

		}

		if (l.exercise.size() != 0)
		{
			for (int i = 0; i < l.exercise.size(); i++)
			{
				out << "Lift number " << (i + 1);
				out << l.exercise[i];
			}
		}

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
	int getFoodSize() const
	{
		return log.size();
	}

	int getLiftSize() const
	{
		return exercise.size();
	}
	food getFood(int i) const
	{
		return log[i];
	}

	lift getLift(int i) const
	{
		return exercise[i];
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
	void printFood() const
	{
			std::cout << "Food number " << (log.size());
			std::cout << log[log.size() - 1];
	}
	void printLift() const
	{
		std::cout << "Lift number " << (exercise.size());
		std::cout << exercise[exercise.size() - 1];
	}
	
	

private:
	std::vector<food> log;
	std::string date;
	std::vector<lift> exercise;

};