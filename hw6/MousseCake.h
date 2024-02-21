#pragma once
#include <iostream>
#include <fstream>
#include "Cake.h"
#include "Date.h"
#include <cstring>
using namespace std;

class MousseCake :public Cake
{
	string taste;

public:
	MousseCake(Date xd, int d, double h, double p, int s, bool g, string t);

	MousseCake(const MousseCake& c);

	~MousseCake();

	const MousseCake& operator=(const MousseCake& c);

	void SetTaste(string t);

	string GetTaste() const { return taste; }

	virtual bool operator==(const MousseCake& c) const;
	void operator+=(const double money);

	virtual void print(ostream& out)const { out << "taste: " << taste << endl; }
	std::string showRecipe() override;

};