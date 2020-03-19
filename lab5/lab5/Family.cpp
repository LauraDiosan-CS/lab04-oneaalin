#include "Family.h"
#include <string.h>
#include <ostream>
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


void Family::setPayment(char* n) {
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

std::ostream& operator<<(std::ostream& os, const Family& c)
{
	os << " Tipul cheltuielii: " << c.payment << ". Ziua: " << c.day << ". Suma:" << c.money<<'\n';
	return os;
}