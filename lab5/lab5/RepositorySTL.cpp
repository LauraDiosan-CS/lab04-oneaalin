#include "RepositorySTL.h"



RepositorySTL::RepositorySTL()
{
}

void RepositorySTL::addElem(Family s) {
	elem.push_back(s);
}

void RepositorySTL::delElem(Family s) {
	vector<Family>::iterator it;
	it = find(elem.begin(), elem.end(), s);
	if (it != elem.end()) elem.erase(it);

}

bool RepositorySTL::findElem(Family s) {
	vector<Family>::iterator it;
	it = find(elem.begin(), elem.end(), s);
	if (it != elem.end()) return true;
	return false;

}

int RepositorySTL::dim() {
	return elem.size();
}

Family RepositorySTL::getItemFromPos(int i) {
	return elem[i];
}

RepositorySTL::~RepositorySTL()
{}

vector<Family> RepositorySTL::getAll() {
	return elem;
}

void RepositorySTL::updateElem(Family s, char* payment, int v1,int v2) {
	for (int i = 0; i < elem.size(); i++)
		if (elem[i] == s) { elem[i].setPayment(payment); elem[i].setDay(v1); elem[i].setMoney(v2); return; }

}

