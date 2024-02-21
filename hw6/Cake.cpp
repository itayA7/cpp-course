#include "Cake.h"
#include "Date.h"
#include <iostream>
#include <fstream>
using namespace std;



Cake::Cake(Date xd, int d, double h, double p, int s, bool g)
	: expiryDate(xd), diameter(d), height(h), price(p), storage(s), glutenFree(g) {
	cout << "In Cake(expiryDate,diameter,height,price,storage,glutenFree)" << endl;
}

Cake::Cake(const Cake& c)
	: expiryDate(c.expiryDate), diameter(c.diameter),
	height(c.height), price(c.price),
	storage(c.storage), glutenFree(c.glutenFree) {
	cout << "In Cake(expiryDate,diameter,height,price,storage,glutenFree)" << endl;
}


bool Cake::operator==(const Cake& c)const {
	if (!(expiryDate == c.expiryDate)) { return false; }
	if (diameter != c.diameter) { return false; }
	if (height != c.height) { return false; }
	if (price != c.price) { return false; }
	if (storage != c.storage) { return false; }
	if (glutenFree != c.glutenFree) { return false; }
	return true;
}

void Cake::operator+=(double m) {
	price += m;
}

std::ostream& operator<<(std::ostream& out, const Cake& c) {
	out << "Cake:" << endl;
	out << "diameter: " << c.diameter << endl;
	out << "height: " << c.height << endl;
	out << "price: " << c.price << endl;
	out << "expiry date: " << c.expiryDate;
	if (c.storage == 1) {
		out << "storage: refrigerator" << endl;
	}
	else {
		out << "storage: freezer" << endl;
	}
	c.glutenFree ? out << "Without gluten" << endl : out << "With gluten" << endl;
	c.print(out);
	return out;
}
const Cake& Cake::operator=(const Cake& c) {
	if (this != &c) {  // Check for self-assignment
		expiryDate = c.expiryDate;
		diameter = c.diameter;
		height = c.height;
		price = c.price;
		storage = c.storage;
		glutenFree = c.glutenFree;
	}
	return *this;
}

Cake::~Cake() {
	cout << "In ~Cake()" << endl;
}