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
		 out << "\n\nInfo for Log on " << l.getDate() << "\n";
		 for (int i = 0; i < l.log.size(); i++)
		 {
			 out << "Food number " << (i + 1); 
			 out << "\nName: " << l.log[i].getName();
			 out << "\nCalories:" << l.log[i].getCals();
			 out << "\nProtein:" << l.log[i].getProtein();
			 out << "\nFat:" << l.log[i].getFat();
			 out << "\nCarbs:" << l.log[i].getCarbs();
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

	//other functions
	void addFood(food f) 
	{
		log.push_back(f);
	}
	void printFood(food f) const
	{
		std::cout << "\nName: " << f.getName();
		std::cout << "\nCalories:" << f.getCals();
		std::cout << "\nProtein:" << f.getProtein();
		std::cout << "\nFat:" << f.getFat();
		std::cout << "\nCarbs:" << f.getCarbs();
		
	}

private:
	std::vector<food> log;
	std::string date;
	std::vector<workouts> exercise;

};