//log object which includes a vector of foods and a vector of lifts.
#pragma once
#include "food.h"
#include "lift.h"
#include <vector>
#include <string>

class logs
{
public:
	//operator overloads
	friend std::ostream& operator<<(std::ostream& out, const logs& l)
	{
		if (!l.log.empty())
		{
			for (int i = 0; i < (int)l.log.size(); i++)
			{
				out << "Food number " << (i + 1);
				out << l.log[i];
			}
		}
		if (!l.exercise.empty())
		{
			for (int i = 0; i < (int)l.exercise.size(); i++)
			{
				out << "Lift number " << (i + 1);
				out << l.exercise[i];
			}
		}
		return out;
	}

	//constructors
	logs() { date = ""; }
	logs(std::string d) { date = d; }

	//setters
	void setDate(std::string d) { date = d; }

	//getters
	std::string getDate() const { return date; }
	int getFoodSize() const { return (int)log.size(); }
	int getLiftSize() const { return (int)exercise.size(); }
	food getFood(int i) const { return log[i]; }
	lift getLift(int i) const { return exercise[i]; }

	//other functions
	void addFood(food f) { log.push_back(f); }
	void addLift(lift l) { exercise.push_back(l); }

	void removeFood(int i)
	{
		if (i >= 0 && i < (int)log.size())
			log.erase(log.begin() + i);
	}

	void printFood() const
	{
		std::cout << "Food number " << log.size();
		std::cout << log[log.size() - 1];
	}
	void printLift() const
	{
		std::cout << "Lift number " << exercise.size();
		std::cout << exercise[exercise.size() - 1];
	}

private:
	std::vector<food> log;
	std::string date;
	std::vector<lift> exercise;
};