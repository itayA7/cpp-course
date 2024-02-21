#include "BirthdayCake.h"
#include "Cake.h"
#include "Date.h"
#include <iostream>
#include <fstream>
#include <cstring>

BirthdayCake::BirthdayCake(Date xd, int d, double h, double p, int s, bool g, string t) :Cake(xd, d, h, p, s, g), text(t) {
	cout << "In BirthdayCake(expiryDate,diameter,height,price,storage,glutenFree,text)" << endl;
}

BirthdayCake::BirthdayCake(const BirthdayCake& c) :Cake(c) {
	cout << "In BirthdayCake(expiryDate,diameter,height,price,storage,glutenFree,text)" << endl;
	text = c.text;
}

void BirthdayCake::SetText(string t) {
	text = t;
}

bool BirthdayCake::operator==(const BirthdayCake& c)const {
	Cake::operator==(c);
	if (text != c.text) { return false; }
	return c.operator==(*this);
}

void BirthdayCake::operator+=(double m) {
	price += m;
}


const BirthdayCake& BirthdayCake::operator=(const BirthdayCake& c) {
	expiryDate = c.expiryDate;
	height = c.height;
	price = c.price;
	storage = c.storage;
	glutenFree = c.glutenFree;
	text = c.text;
	return *this;
}

std::string BirthdayCake::showRecipe() {
	return "link to a birthday cake recipe";
}
BirthdayCake::~BirthdayCake() {
	cout << "In ~BirthdayCake()" << endl;
}