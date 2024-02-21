#include "Bakery.h"
using namespace std;
#include <iostream>
#include <cstring>  // Include for strcpy_s

Bakery::Bakery(const char* name, Date start, int max) : startDate(start), MaxCakes(max) {
	Name = new char[strlen(name) + 1];
	strcpy_s(Name, strlen(name) + 1, name);
	cakes = new Cake * [MaxCakes];
	for (int i = 0; i < MaxCakes; i++) {
		cakes[i] = nullptr;
	}
	std::cout << "In Bakery(name,startDate,maxCakes)" << std::endl;
}

Bakery::Bakery(const Bakery& b) {
	cout << "Bakery(const Bakery& other)" << endl;
	Name = new char[strlen(b.Name) + 1];
	strcpy_s(Name, strlen(b.Name) + 1, b.Name);
	startDate = b.startDate;
	MaxCakes = b.MaxCakes;
	cakes = new Cake * [MaxCakes];
	for (int i = 0; i < MaxCakes; ++i) {
		cakes[i] = b.cakes[i];
	}
}

const Bakery& Bakery::operator=(const Bakery& b) {
	cout << "In Bakery operator=" << endl;
	Name = new char[strlen(b.Name) + 1];
	strcpy_s(Name, strlen(b.Name) + 1, b.Name);
	startDate = b.startDate;
	MaxCakes = b.MaxCakes;
	cakes = new Cake * [MaxCakes];
	for (int i = 0; i < MaxCakes; ++i) {
		cakes[i] = b.cakes[i];
	}
	return *this;
}

void Bakery::chooseCake(int maxPrice) {
	cout << "Mached cakes:" << endl;
	bool found = false;
	for (int i = 0; i < MaxCakes; i++) {
		if (cakes[i] != nullptr) {
			if (cakes[i]->GetPrice() <= maxPrice) {
				cout << *cakes[i] << endl;
				found = true;
			}
		}
	}
	if (!found)cout << "There is no matched cakes" << endl;
}
void Bakery::deleteCake(int location) {
	if (location >= MaxCakes)cout << "Invalid cake number" << endl;
	else {
		cakes[location] = nullptr;
		cout << "Cake deleted!" << endl;
	}
}
void Bakery::addCake(Cake* c) {
	bool space = false;
	for (int i = 0; i < MaxCakes; i++) {
		if (cakes[i] == nullptr && !space) {
			space = true;
			cakes[i] = c;
			cout << "The added cake: " << endl;
			cout << *cakes[i] << endl;
		}
	}
	if (!space)cout << "not space to add cake" << endl;
}
void Bakery::deleteExpired(const Date& d) {
	for (int i = 0; i < MaxCakes; ++i) {
		if (cakes[i] != nullptr && cakes[i]->GetDate() < d) {
			deleteCake(i);
		}
	}
}

std::ostream& operator<<(std::ostream& out, const Bakery& b) {
	out << "Bakery:" << endl;
	out << "Name: " << b.Name << endl;
	out << "Start date: " << b.startDate;
	out << "max cakes: " << b.MaxCakes << endl;
	for (int i = 0; i < b.MaxCakes; i++) {
		if (b.cakes[i] != nullptr)out << *b.cakes[i] << endl;;
	}
	return out;
}
Bakery::~Bakery() {
	cout << "In ~Bakery()" << endl;
	delete[] Name;
	delete[] cakes;
}