#include "Service.h"
#include <algorithm> 

Service::Service()
{
	this->repo;
	this->undoList.push_back(this->repo);
}

Service::Service(const RepositoryFile& r)
{
	repo = r;
}

void Service::setRepo(const RepositoryFile& r)
{
	repo = r;
}

void Service::addFamily(Family& s)
{
	this->undoList.push_back(this->repo);
	repo.addElem(s);
}

int Service::delFamily(Family& s)
{
	this->undoList.push_back(this->repo);
	return repo.delElem(s);
}

vector<Family> Service::getAll()
{
	return repo.getAll();
}

Family Service::update(Family s, char* n, int a, int b)
{
	this->undoList.push_back(this->repo);
	repo.updateElem(s, n, a ,b);
	return s;
}

bool Service::findOne(Family s)
{
	return repo.findElem(s);
}

vector<Family> Service::getPaymentByName(const char* payment)
{
	vector<Family> rez;
	for (int i = 0; i < repo.size(); i++)
	{
		Family current_entity = repo.elemAtPos(i);
		if (strstr(current_entity.getPayment(), payment))
			rez.push_back(current_entity);
	}
	return rez;
}

int Service::sumOfPayment(const char* payment)
{
	int sum = 0;
	for (int i = 0; i < repo.size(); i++)
	{
		Family current_entity = repo.elemAtPos(i);
		if (strstr(current_entity.getPayment(), payment))
			sum = sum + current_entity.getMoney();
	}
	return sum;
}

vector<Family> Service::filterByPaymentAndMoney(const char* payment, int money)
{
	vector<Family> rez;
	for (int i = 0; i < repo.size(); i++)
	{
		Family current_entity = repo.elemAtPos(i);
		if (strstr(current_entity.getPayment(), payment) && current_entity.getMoney() < money)
			rez.push_back(current_entity);
	}
	return rez;
}

void Service::undo() {
	auto actual_state = undoList.back();
	undoList.pop_back();
	this->repo = actual_state;
	this->undoList = undoList;
}

Service::~Service()
{
}
