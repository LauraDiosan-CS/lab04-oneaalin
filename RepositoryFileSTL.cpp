#include "RepositoryFileSTL.h"
#include <fstream>
#include <string>
using namespace std;


RepositoryFile::RepositoryFile()
{

}

RepositoryFile::RepositoryFile(const char* fileName)
{
	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* payment = new char[10];
	int day, money;
	while (!f.eof()) {
		f >> payment >> day >> money;
		if (payment != "") {
			Family s(payment, day, money);
			elem.push_back(s);
		}
	}
	delete[] payment;
	f.close();
}

void RepositoryFile::loadFromFile(const char* fileName)
{
	elem.clear();
	fis = fileName;
	ifstream f(fileName);
	char* payment = new char[10];
	int day, money;
	while (!f.eof()) {
		f >> payment >> day >> money;
		if (strcmp(payment, "") != 0) {
			Family s(payment, day , money);
			elem.push_back(s);
		}
	}
	delete[] payment;
	f.close();
}

void RepositoryFile::addElem(Family s)
{
	elem.push_back(s);
}

void RepositoryFile::updateElem(Family s,const char* newPayment, int newDay , int newMoney)
{
	vector<Family>::iterator it;
	it = find(elem.begin(), elem.end(), s);
	if (it != elem.end()) {
		(*it).setPayment(newPayment);
		(*it).setDay(newDay);
		(*it).setMoney(newMoney);
	}

}

//returneaza pozitia la care se gaseste studentul s, sau -1, daca acesta nu apare
int RepositoryFile::findElem(Family s)
{
	vector<Family>::iterator it;
	it = find(elem.begin(), elem.end(), s);
	if (it != elem.end()) {
		return distance(elem.begin(), it);
	}
	return -1;
}

//sterge elementul s din repository, returneaza 0 la succes, -1 altfel
int RepositoryFile::delElem(Family s)
{
	vector<Family>::iterator it;
	it = find(elem.begin(), elem.end(), s);
	if (it != elem.end()) {
		elem.erase(it);
		return 0;
	}
	return -1;

}

Family RepositoryFile::elemAtPos(int i)
{
	if (i < 0 or i >= elem.size()) return Family("", -1 , -1);
	return elem[i];
}

vector<Family> RepositoryFile::getAll()
{
	return elem;
}

int RepositoryFile::size()
{
	return elem.size();
}

void RepositoryFile::saveToFile()
{
	ofstream f(fis);
	for (size_t i = 0; i < elem.size(); i++) {
		f << elem[i];
	}
	f.close();
}


RepositoryFile::~RepositoryFile()
{

}