//Food object class for the health app.

#pragma once

#include <iostream>

class food
{
public:
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
