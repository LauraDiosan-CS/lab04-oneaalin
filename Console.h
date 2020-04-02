#pragma once
#include "Service.h"
//shows User Interface 
class UI {
private:
	Service serv;
public:
	UI();
	void addFam(Service& s);
	void findFam(Service& serv);
	void delFam(Service& serv);
	void updateFam(Service& serv);
	void showAll(Service& serv);
	void showPaymentByName(Service& serv);
	void showSumOfPayment(Service& serv);
	void showByPaymentAndMoney(Service& serv);
	void showUI(Service& serv);
	~UI();
};
