#pragma once
#include "Date.h"
#include "Cake.h"
#include <cstring>
class Bakery
{
	char* Name;
	Date startDate;
	int MaxCakes;
	Cake** cakes;

public:
	Bakery(const char* name, Date start, int max);
	Bakery(const Bakery& b);
	const Bakery& operator=(const Bakery& b);
	~Bakery();
	void chooseCake(int maxPrice);
	void deleteCake(int location);
	void addCake(Cake* c);
	void deleteExpired(const Date& d);

	friend std::ostream& operator<<(std::ostream& out, const Bakery& b);
};