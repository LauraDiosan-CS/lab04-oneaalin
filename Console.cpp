#include "Console.h"
#include <iostream>
using namespace std;

UI::UI() {

}

void UI::addFam(Service& s) {
	Family fam;
	cin >> fam;
	s.addFamily(fam);
	cout << "Cheltuiala a fost adaugata cu succes!" << endl;
}


void UI::findFam(Service& serv) {
	Family fam;
	cin >> fam;
	bool rez = serv.findOne(fam);
	if (rez>=0) cout << "Cheltuiala a fost gasita!"<< endl;
	else cout << "Cheltuiala nu a fost gasita!" << endl;
}

void UI::delFam(Service& serv) {
	Family fam;
	cin >> fam;
	int rez = serv.delFamily(fam);
	if (rez == 0) cout << "Cheltuiala a fost  stearsa cu succes!" << endl;
	else cout << "Cheltuiala NU a fost stearsa!" << endl;
}

void UI::updateFam(Service& serv) {
	Family fam1;
	char* payment;
	int day, money;
	payment = new char[20];
	cout << "Dati cheltuiala de schimbat : " << endl;
	cin >> fam1;
	cout << "Dati schimbarea cheltuielii : " << endl;
	cin >> payment;
	cout << "Dati schimbarea zilei : " << endl;
	cin >> day;
	cout << "Dati schimbarea sumei : " << endl;
	cin >> money;
	serv.update(fam1, payment, day, money);
	cout << "Cheltuiala a fost schimbata !";
	delete[] payment;
}

void UI::showAll(Service& serv) {
	vector<Family> fam = serv.getAll();
	for (Family s : fam)
		cout << s;
}

void UI::showPaymentByName(Service& serv)
{
	char* payment;
	payment = new char[20];
	cout << "Dati cheltuiala : ";
	cin >> payment;
	vector<Family> fam = serv.getPaymentByName(payment);
	for (Family s : fam)
		cout << s;
	delete[] payment;
}

void UI::showSumOfPayment(Service& serv)
{
	char* payment;
	int sum;
	payment = new char[20];
	cout << "Dati cheltuiala : ";
	cin >> payment;
	sum = serv.sumOfPayment(payment);
	cout << sum;
	delete[] payment;
}

void UI::showByPaymentAndMoney(Service& serv)
{
	char* payment;
	int money;
	payment = new char[20];
	cout << "Dati cheltuiala : ";
	cin >> payment;
	cout << "Dati suma de bani : ";
	cin >> money;
	vector<Family> fam = serv.filterByPaymentAndMoney(payment,money);
	for (Family s : fam)
		cout << s;
	delete[] payment;
}

void UI::showUI(Service& serv)
{
	bool gata = false;
	while (!gata) {
		cout << endl;
		cout << "OPTIUNI: " << endl;
		cout << "	1. Adauga cheltuiala " << endl;
		cout << "	2. Cauta cheltuiala " << endl;
		cout << "	3. Sterge cheltuiala " << endl;
		cout << "	4. Afiseaza toate cheltuielile " << endl;
		cout << "	5. Actualizeaza o cheltuiala " << endl;
		cout << "	6. Afiseaza cheltuieli dupa numele dat " << endl;
		cout << "	7. Suma unei cheltuieli dupa numele dat " << endl;
		cout << "	8. Filtrarea dupa nume si suma mai mica decat o suma data " << endl;
		cout << "	9. Undo " << endl;
		cout << "	0. EXIT!" << endl;
		cout << "Introduceti optiunea (prin numarul ei): " << endl;
		int opt;
		cin >> opt;
		switch (opt) {
		case 1: {addFam(serv); break; }
		case 2: {findFam(serv); break; }
		case 3: {delFam(serv); break; }
		case 4: {showAll(serv); break; }
		case 5: {updateFam(serv); break; }
		case 6: {showPaymentByName(serv); break; }
		case 7: {showSumOfPayment(serv); break; }
		case 8: {showByPaymentAndMoney(serv); break; }
		case 9: {serv.undo(); break; }
		case 0: {gata = true; cout << "LA REVEDERE!" << endl; }
		}
	}
}

UI::~UI() {

}
