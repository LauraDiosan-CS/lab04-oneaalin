#include <iostream>
#include "Family.h"
#include "RepositoryArray.h"
#include "Tests.h"
using namespace std;
int main()
{

	int op, day, money;
	char* payment;
	payment = new char[101];
	RepositoryArray rep;
	Family f;
	while (true)
	{
		cout << "1.Citirea unei cheltuieli"<<'\n';
		cout << "2.Afisarea cheltuielilor" << '\n';
		cout << "3.Exit"<<'\n';

		cout << "Alegeti o optiune : ";
		cin >> op;
		if (op == 1)
		{
			cout << "Introduceti cheltuiala[tip zi suma] : ";
			cin >> payment >> day >> money;
			f = Family(payment, day, money);
			rep.addElem(f);
		}
		else if (op == 2)
		{
			cout << "Cheltuielile sunt : "<<f;
		}
		else if (op == 3)
		{
			break;
		}
	}
	delete[] payment;
}