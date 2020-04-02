#include "TestRepositoryFile.h"
#include <assert.h> 



TestRepositoryFile::TestRepositoryFile()
{

	assert(repo.size() == 0);
}

void TestRepositoryFile::testLoadFromFile()
{
	repo.loadFromFile("TestCheltuieli.txt");
	assert(repo.size() == 4);
}

void TestRepositoryFile::testAddElem()
{
	repo.loadFromFile("TestCheltuieli.txt");
	repo.addElem(Family("caldura", 4, 150));
	assert(repo.size() == 5);
	repo.saveToFile();
}

void TestRepositoryFile::testFindElem()
{
	repo.loadFromFile("TestCheltuieli.txt");
	assert(repo.findElem(Family("haine", 2,300)) == 1);
	assert(repo.findElem(Family("caldura", 1,100)) == -1);
	repo.saveToFile();
}

void TestRepositoryFile::testDelElem()
{
	repo.loadFromFile("TestCheltuieli.txt");
	repo.delElem(Family("caldura", 4, 150));
	assert(repo.size() == 4);
	repo.saveToFile();
}

void TestRepositoryFile::testGetAll()
{
	repo.loadFromFile("TestCheltuieli.txt");
	vector<Family> rez = repo.getAll();
	assert(rez.size() == 4);
	repo.saveToFile();
}

void TestRepositoryFile::testUpdateElem()
{
	repo.loadFromFile("TestCheltuieli.txt");
	repo.updateElem(Family("haine", 2, 300), "caldura", 10,350);
	assert(repo.findElem(Family("caldura", 10,350)) == 1);
	repo.saveToFile();
}

void TestRepositoryFile::testElemAtPos()
{
	repo.loadFromFile("TestCheltuieli.txt");
	assert(repo.elemAtPos(2) == Family("facturi", 3,400));
	repo.saveToFile();
}

void TestRepositoryFile::testSize()
{
	repo.loadFromFile("TestCheltuieli.txt");
	assert(repo.size() == 4);
}

void TestRepositoryFile::testSaveToFile()
{
	repo.loadFromFile("TestCheltuieli.txt");
	int n = repo.size();
	repo.addElem(Family("caldura", 4, 150));
	repo.saveToFile();
	repo.loadFromFile("TestStud.txt");
	assert(repo.getAll().size() == (n + 1));

}


TestRepositoryFile::~TestRepositoryFile()
{
}
