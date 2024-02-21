#pragma once
#include <iostream>
#include <fstream>
#include "Date.h"
#include <cstring>
class Cake
{
protected:
	Date expiryDate;
	int diameter;
	double height;
	double price;
	int storage;
	bool glutenFree;
public:

	Cake(Date xd, int d, double h, double p, int s, bool g);

	const Cake& operator=(const Cake& c);

	Cake(const Cake& c);

	~Cake();

	virtual bool operator==(const Cake& c) const;
	void operator+=(const double money);

	friend std::ostream& operator<<(std::ostream& out, const Cake& c);

	virtual std::string showRecipe() = 0;
	virtual void print(std::ostream& out) const = 0;

	const double GetPrice() { return price; }
	const Date& GetDate() const { return expiryDate; }

};