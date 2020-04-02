#pragma once
#include "Service.h"

class TestService {
private:
	Service s;
	void testGetPaymentByName();
	void testSumOfPayment();
	void testFilterByPaymentAndMoney();
public:
	TestService();
	void runTests();
	~TestService();
};