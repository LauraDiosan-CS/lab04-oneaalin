#pragma once
#include <ostream>
class Family {
private:
	char* payment;
	int day;
	int money;
public:
	Family();
	Family(const char*, int,int);
	Family(const Family&);
	Family& operator=(const Family&);
	char* getPayment();
	int getDay();
	int getMoney();
	void setPayment(char*);
	void setDay(int);
	void setMoney(int);
	bool operator==(const Family&);
	~Family();
	friend std::ostream& operator<<(std::ostream& os, const Family& s);
};
