#include "MousseCake.h"
#include "Cake.h"
#include "Date.h"
#include <iostream>
#include <fstream>
#include <cstring>

MousseCake::MousseCake(Date xd, int d, double h, double p, int s, bool g, string t) :Cake(xd, d, h, p, s, g), taste(t) {
	cout << "In MousseCake(expiryDate,diameter,height,price,storage,glutenFree,taste)" << endl;
}

MousseCake::MousseCake(const MousseCake& c) :Cake(c) {
	cout << "In MousseCake(expiryDate,diameter,height,price,storage,glutenFree,taste)" << endl;
	taste = c.taste;
}

void MousseCake::SetTaste(string t) {
	taste = t;
}

bool MousseCake::operator==(const MousseCake& c)const {
	Cake::operator==(c);
	if (taste != c.taste) { return false; }
	return c.operator==(*this);
}

void MousseCake::operator+=(double m) {
	price += m;
}

const MousseCake& MousseCake::operator=(const MousseCake& c) {
	expiryDate = c.expiryDate;
	height = c.height;
	price = c.price;
	storage = c.storage;
	glutenFree = c.glutenFree;
	taste = c.taste;
	return *this;
}

std::string MousseCake::showRecipe() {
	return "link to a mousse cake recipe";
}
MousseCake::~MousseCake() {
	cout << "In ~MouuseCake()" << endl;
}