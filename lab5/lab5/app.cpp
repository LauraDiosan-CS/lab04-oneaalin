#include "Console.h"
#include "Service.h"
#include "RepositoryFileSTL.h"
#include <iostream>
#include "TestRepositoryFile.h"

using namespace std;

void initService(Service& s) {
	RepositoryFile r;
	r.loadFromFile("Cheltuieli.txt");
	s.setRepo(r);
}

int main() {
	cout << "start..." << endl;

	/******TEST REPO FILE****/
	/*TestRepositoryFile test;
	test.testAddElem();
	test.testDelElem();
	test.testElemAtPos();
	test.testFindElem();
	test.testGetAll();
	test.testSize();
	test.testUpdateElem();*/

	/******** TEST SERVICE ******/
/*	TestService ts;
	ts.runTests();
	*/

	UI console;
	Service serv;
	initService(serv);
	console.showUI(serv);
	cout << "succes";
	return 0;
}