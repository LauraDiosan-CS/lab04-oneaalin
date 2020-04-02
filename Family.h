#pragma once
#include <iostream>
#include <string>
using namespace std;
//creates Family business object
class Family {
private:
	char* payment;
	int day;
	int money;
public:
	/*Family object constructor
	  Input:-
	  Preconditii:-
	  Output:-
	  Postconditii:-
	*/
	Family();
	/*
		Input: un pointer constant de tip char si doua de tip intreg
		Preconditii: valorile sa respecte tipul de date
		Output:un obiect de tip Family
		Postconditii:-
	*/
	Family(const char*, int,int);
	/*
		Input: un obiect de tip Family
		Preconditii: obiectul trebuie sa fie de tip Family
		Output:un obiect de tip Family
		Postconditii: obiectul o sa fie de tip Family
	*/
	Family(const Family&);
	/* Constructor de conversie
	   Input: un string de caractere
	   Preconditii : string-ul sa fie de caractere
	   Output : token-uri ale clasei Family
	   Postconditii:-
	*/
	Family(string);
	/* Operatorul de atribuire supraincarcat
	   Input: un obiect constant de tip Family
	   Preconditii: obiectul sa fie de tip Family
	   Output : un obiect de tip Family
	   Postconditii: -
	*/
	Family& operator=(const Family&);
	/*	Getter pentru cheltuiala
		Input:-
		Preconditii:-
		Ouput : un string de tip char
		Postcodnti : string-ul va fi sir de caractere
	*/
	char* getPayment();
	/*	Getter pentru zi
		Input: -
		Preconditii:-
		Ouput : o variabila de tip int
		Postconditii: valaorea va fi intreaga
	*/
	int getDay();
	/*	Getter pentru bani
		Input: -
		Preconditii:-
		Ouput : o variabila de tip int
		Postconditii: valaorea va fi intreaga
	*/
	int getMoney();
	/*	Setter pentru cheltuiala
		Input: un pointer constant de tip char
		Preconditii: string-ul va fi sir de caractere
		Output: obiectul de tip Family modificat
		Postconditii: obiectul o sa fie de tip Family
	*/
	void setPayment(const char*);
	/*	Setter pentru zi
		Input: o variabila de tip int
		Preconditii: valoarea va fi intreaga
		Output: obiectul de tip Family modificat
		Postconditii: obiectul o sa fie de tip Family
	*/
	void setDay(int);
	/*	Setter pentru bani
		Input: o variabila de tip int
		Preconditii: valoarea va fi intreaga
		Output: obiectul de tip Family modificat
		Postconditii: obiectul o sa fie de tip Family
	*/
	void setMoney(int);
	/*	Operatul == supraincarcat
		Input: un obiect constant de tip Family
		Preconditii: obiectul o sa fie de tip Family
		Output: valorile true sau false

	*/
	bool operator==(const Family&);
	/*	Deconstructor
		Input:-
		Output:-
	*/
	~Family();
	//operatorul supraincarcat de afisare al unei cheltuieli
	friend ostream& operator<<(ostream& os, Family s);
	//operatorul supraincarcat de citire al unei cheltuieli
	friend istream& operator>>(istream&, Family&);
};
