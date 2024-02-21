#pragma once
#include <iostream>
#include <fstream>
#include "Cake.h"
#include "Date.h"
#include <cstring>
using namespace std;
class BirthdayCake :public Cake
{
	string text;

public:
	BirthdayCake(Date xd, int d, double h, double p, int s, bool g, string t);

	BirthdayCake(const BirthdayCake& c);

	const BirthdayCake& operator=(const BirthdayCake& c);

	string GetText() const { return text; }
	void SetText(string t);

	virtual bool operator==(const BirthdayCake& c) const;
	void operator+=(const double money);
	virtual void print(ostream& out)const { out << "text: " << text << endl; }

	std::string showRecipe() override;
	~BirthdayCake();
};