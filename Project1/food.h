//Food object class for the health app.

#pragma once

#include <iostream>

class food
{
public:
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
	std::string getName()
	{
		return name;
	}
	int getProtein()
	{
		return protein;
	}
	int getCals()
	{
		return cals;
	}
	int getFat()
	{
		return fat;
	}
	int getCarbs()
	{
		return carbs;
	}

private:
	std::string name;
	int protein;
	int cals;
	int fat;
	int carbs;

};
