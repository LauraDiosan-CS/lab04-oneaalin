#pragma once
#include "RepositoryFileSTL.h"
#include "Family.h"
#include <vector>
using namespace std;
//creates Service object
class Service
{
private:
	RepositoryFile repo;
	vector <RepositoryFile> undoList;
public:
	/*	Service constructor
		Input:-
		Preconditii:-
		Output:-
		Postconditii:-
	*/
	Service();
	/*
		Input: un obiect constant de tip RepositoryFile
		Preconditii: obiectul trebuie sa fie de tip RepositoryFile
		Ouput: -
		Postconditii: -
	*/
	Service(const RepositoryFile&);
	/*	Setter pentru repository
		Input: un obiect constant de tip RepositoryFile
		Preconditii: obiectul trebuie sa fie de tip RepositoryFile
		Ouput: -
		Postconditii: -
	*/
	void setRepo(const RepositoryFile&);
	/*	Adauga o cheltuiala
		Input:-
		Preconditii:-
		Output: un obiect de tip Family adaugat in repository
		Postconditii: obiectul va fi de tip Family
	*/
	void addFamily(Family&);
	/*	Sterge o cheltuiala
		Input:-
		Preconditii:-
		Output: un obiect de tip Family sters din repository
		Postconditii: obiectul va fi de tip Family
	*/
	int delFamily(Family&);
	/*	Primeste toate cheltuielile
		Input:-
		Preconditii:-
		Output: un vector de tip Family din repository
		Postconditii: vectorul va fi de tip Family
	*/
	vector<Family> getAll();
	/*	Actualizeaza o cheltuiala
		Input: un pointer de tip char si doua variabile de tip int
		Preconditii: pointerul trebuie sa fie sir de caractere iar cele doau variabile numere intregi
		Output: un obiect de tip Family modificat in repository
		Postconditii: obiectul va fi de tip Family
	*/
	Family update(Family, char*, int, int);
	/*	Gaseste o cheltuiala
		Input: un obiect de tip Family
		Preconditii: obiectul va fi de tip Family
		Output: valoarea true sau false
		Postconditii: true daca obiectul a fost gasit si false in caz contrar
	*/
	bool findOne(Family);
	/*	Service deconstructor
		Input:-
		Preconditii:-
		Output:-
		Postconditii:-
	*/
	vector<Family> getPaymentByName(const char* payment);
	int sumOfPayment(const char* payment);
	vector<Family> filterByPaymentAndMoney(const char* payment, int money);
	void undo();
	~Service();
};

