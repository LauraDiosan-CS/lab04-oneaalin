#include "RepositoryArray.h"

RepositoryArray::RepositoryArray() { size = 0; }

void RepositoryArray::addElem(Family s) {
	elem[size++] = s;
}

int RepositoryArray::findElem(Family s) {
	int i = 0;

	while (i < size) {
		if (elem[i] == s) return i;
	}
	return -1;
}

void RepositoryArray::delElem(Family s) {
	int i = findElem(s);
	if (i != -1)
		elem[i] = elem[size - 1];
	size--;
}

void RepositoryArray::updateElem(Family s, char* n, int v1,int v2) {
	int i = findElem(s);
	elem[i].setPayment(n);
	elem[i].setDay(v1);
	elem[i].setMoney(v2);

}

Family* RepositoryArray::getAll() {
	return elem;
}
int RepositoryArray::dim() {
	return size;
}
RepositoryArray::~RepositoryArray() {
}

Family RepositoryArray::getItemFromPos(int i) {
	return elem[i];
}
