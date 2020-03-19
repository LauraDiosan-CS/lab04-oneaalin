#pragma once
#include "Family.h"

class RepositoryArray
{
private:
	Family elem[10];
	int size;

public:
	RepositoryArray();
	void addElem(Family);
	int findElem(Family);
	Family getItemFromPos(int);
	void delElem(Family);
	void updateElem(Family, char*, int,int);
	Family* getAll();
	int dim();
	~RepositoryArray();
};
