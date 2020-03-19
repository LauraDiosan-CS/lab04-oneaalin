#pragma once
#include "Family.h"
#include <vector>

using namespace std;

class RepositorySTL
{
private:
	vector<Family> elem;

public:
	RepositorySTL();
	void addElem(Family);
	bool findElem(Family);
	void delElem(Family);
	void updateElem(Family, char*, int, int);
	Family getItemFromPos(int);
	vector<Family> getAll();
	int dim();
	~RepositorySTL();
};



