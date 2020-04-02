#pragma once
#include "Family.h"
#include <vector>
using namespace std;
//Creates repository
class RepositoryFile
{
private:
	vector<Family> elem;
	const char* fis;
public:
	//Repository constructor
	RepositoryFile();
	RepositoryFile(const char* fileName);
	//loads data from file
	void loadFromFile(const char* fileName);
	//adauga un obiect de tip family
	void addElem(Family);
	//actualizeaza un obiect de tip family
	void updateElem(Family,const char*, int, int);
	//gaseste un obiect de tip family
	int findElem(Family);
	//sterge un obiect de tip family 
	int delElem(Family);
	//returneaza un element de tip family de la o anumita pozitie
	Family elemAtPos(int);
	//returneaza un vector cu toate obiectele de tip family
	vector<Family> getAll();
	//returneaza dimensiunea 
	int size();
	//saves data to file
	void saveToFile();
	//Repository deconstructor
	~RepositoryFile();
};