//lift object for specific gym movement.

#pragma once
#include <iostream>

class lift
{
public:
	//constructors

	//default constructor
	lift() 
	{
		liftName = "";
		pounds = 0;
		reps = 0;
		sets = 0;
	}

	//multi-argument constructor
	lift(std::string n, int p, int r, int s)
	{
		liftName = n;
		pounds = p;
		reps = r;
		sets = s;
	}

	//setters
	void setName(std::string n)
	{
		liftName = n;
	}
	void setPounds(int p)
	{
		pounds = p;
	}
	void setReps(int r)
	{
		reps = r;
	}
	void setSets(int s)
	{
		sets = s;
	}

	//getters
	std::string getName() const
	{
		return liftName;
	}
	int getPounds() const
	{
		return pounds;
	}
	int getReps() const
	{
		return reps;
	}
	int getSets() const
	{
		return sets;
	}


private:
	//private variables
	std::string liftName;
	int pounds;
	int reps;
	int sets;

};
