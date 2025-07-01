//Food object class for the health app.

#pragma once

#include <iostream>

class food
{
public:
	//overload operators
	friend std::ostream& operator<<(std::ostream& out, const food& f)
	{
		out << "\nName: " << f.getName();
		out << "\nCalories:" << f.getCals();
		out << "\nProtein:" << f.getProtein();
		out << "\nFat:" << f.getFat();
		out << "\nCarbs:" << f.getCarbs() << "\n\n";

		return out;
	}

	//constructors

	//default constructor
	food()
	{
		name = "";
		protein = 0;
		cals = 0;
		fat = 0;
		carbs = 0;
	}

	//multi-argument constructor
	food(std::string n, int p, int c, int f, int cb)
	{
		name = n;
		protein = p;
		cals = c;
		fat = f;
		carbs = cb;
	}

	//setters
	void setName(std::string s)
	{
		name = s;
	}
	void setProtein(int p)
	{
		protein = p;
	}
	void setCals(int c)
	{
		cals = c;
	}
	void setFat(int f)
	{
		fat = f;
	}
	void setCarbs(int cb)
	{
		carbs = cb;
	}

	//getters
	std::string getName() const
	{
		return name;
	}
	int getProtein() const
	{
		return protein;
	}
	int getCals() const
	{
		return cals;
	}
	int getFat() const
	{
		return fat;
	}
	int getCarbs() const
	{
		return carbs;
	}

	//other functions
	void printFood() const
	{
		std::cout << "\nName: " << getName();
		std::cout << "\nCalories:" << getCals();
		std::cout << "\nProtein:" << getProtein();
		std::cout << "\nFat:" << getFat();
		std::cout << "\nCarbs:" << getCarbs();

	}

private:
	std::string name;
	int protein;
	int cals;
	int fat;
	int carbs;

};
