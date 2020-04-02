#include "TestService.h"
#include <assert.h>

void TestService::testGetPaymentByName()
{
	RepositoryFile repo;
	repo.loadFromFile("TestCheltuieli.txt");
	Service serv;
	serv.setRepo(repo);
	vector<Family> rez = serv.getPaymentByName("mancare");
	assert(rez[0] == Family("mancare", 1, 200));
}

void TestService::testSumOfPayment()
{
	RepositoryFile repo;
	repo.loadFromFile("TestCheltuieli.txt");
	Service serv;
	serv.setRepo(repo);
	int rez;
	rez = serv.sumOfPayment("mancare");
	assert(rez == 200);
}


void TestService::testFilterByPaymentAndMoney()
{
	RepositoryFile repo;
	repo.loadFromFile("TestCheltuieli.txt");
	Service serv;
	serv.setRepo(repo);
	vector<Family> rez = serv.filterByPaymentAndMoney("mancare", 201);
	assert(rez[0] == Family("mancare", 1,200));
}

TestService::TestService()
{
}

void TestService::runTests()
{
	testGetPaymentByName();
	testSumOfPayment();
	testFilterByPaymentAndMoney();
}

TestService::~TestService()
{
}
