#include "Family.h"
#include <string.h>
#include <sstream>
using namespace std;
Family::Family() {
	payment = NULL;
	day = 0;
	money = 0;
}

Family::Family(const char* payment, int day , int money) {
	this->payment = new char[strlen(payment) + 1];
	strcpy_s(this->payment, strlen(payment) + 1, payment);
	this->day = day;
	this->money = money;
}

Family::Family(const Family& s) {
	this->payment = new char[strlen(s.payment) + 1];
	strcpy_s(this->payment, strlen(s.payment) + 1, s.payment);
	this->day = s.day;
	this->money = s.money;
}

Family::Family(string linie)
{
	istringstream iss(linie);
	string tok1, tok2, tok3;
	iss >> tok1 >> tok2 >> tok3;
	payment = new char[tok1.length() + 1];
	strcpy_s(payment, tok1.length() + 1, tok1.c_str());
	day = stoi(tok2);
	money = stoi(tok3);
}

int Family::getDay() {
	return day;
}

void Family::setDay(int v) {
	day = v;
}

int Family::getMoney() {
	return money;
}

void Family::setMoney(int v) {
	money = v;
}

char* Family::getPayment() {
	return payment;
}


void Family::setPayment(const char* n) {
	if (payment) delete[]payment;
	payment = new char[strlen(n) + 1];
	strcpy_s(payment, strlen(n) + 1, n);
}

Family::~Family() {
	if (payment) delete[]payment;
	payment = NULL;
	day = -1;
	money = -1;
}

Family& Family::operator=(const Family& s) {
	if (this == &s) return *this;
	if (payment) delete[] payment;
	payment = new char[strlen(s.payment) + 1];
	strcpy_s(payment, strlen(s.payment) + 1, s.payment);
	day = s.day;
	money = s.money;
	return *this;
}

bool Family::operator==(const Family& s) {
	return (strcmp(payment, s.payment) == 0) and (day == s.day) and (money == s.money);
}

ostream& operator<<(ostream& os, Family s) {
	os << s.payment << " " << s.day << " " << s.money << endl;
	return os;
}

istream& operator>>(istream& is, Family& s)
{
	cout << "Dati cheltuiala: ";
	char* payment = new char[10];
	is >> payment;
	cout << "Dati ziua: ";
	int v1;
	cin >> v1;
	cout << "Dati suma: ";
	int v2;
	cin >> v2;
	s.setPayment(payment);
	s.setDay(v1);
	s.setMoney(v2);
	delete[] payment;
	return is;
}
