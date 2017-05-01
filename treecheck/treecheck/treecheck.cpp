// treecheck.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
// checks if a tree is an AVL tree and gives various other information.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "tree.h"
#include <ctime> //Benötigt für Testfunktionen


int main(int argc, char* argv[]) //Poject properties -> debugging argument -> testtree.txt is the testfile
{
	using namespace std;

	if (argc == 2) { //everythings alright, arguments were listed correct :D
		tree* mytree = new tree();
		string file = argv[1];
		if (file == "test") {
			std::cout << "Tests werden gestartet:" << endl;
			std::cout << "Test0 wird gestartet" << endl;
			ifstream infile("testtree.txt"); //Open filestream
			string line = "";
			int next = 0;
			std::clock_t start;
			start = std::clock();
			while (getline(infile, line)) { //while next line can be read :D
				next = stoi(line, nullptr, 10);
				mytree->add(next);
			}
			double duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
			std::cout << "Einfuegen: " << duration << " Sekunden \n" << std::endl;
			mytree->showstats(true);
			delete mytree;
			std::cout << "Test1 wird gestartet" << endl;
			mytree = new tree();
			ifstream infile1("test1_1-1000_100-unsorted-unique.txt"); //Open filestream
			line = "";
			next = 0;
			start = std::clock();
			while (getline(infile1, line)) { //while next line can be read :D
				next = stoi(line, nullptr, 10);
				mytree->add(next);
			}
			duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
			std::cout << "Einfuegen: " << duration << " Sekunden \n" << std::endl;
			mytree->showstats(true);
			delete mytree;
			std::cout << "Test2 wird gestartet" << endl;
			mytree = new tree();
			ifstream infile2("test2_1-1000_100-unsorted-not-unique.txt"); //Open filestream
			line = "";
			next = 0;
			start = std::clock();
			while (getline(infile2, line)) { //while next line can be read :D
				next = stoi(line, nullptr, 10);
				mytree->add(next);
			}
			duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
			std::cout << "Einfuegen: " << duration << " Sekunden \n" << std::endl;
			mytree->showstats(true);
			delete mytree;
			std::cout << "Test3 wird gestartet" << endl;
			mytree = new tree();
			ifstream infile3("test3_1-1000_1000-unsorted-unique.txt"); //Open filestream
			line = "";
			next = 0;
			start = std::clock();
			while (getline(infile3, line)) { //while next line can be read :D
				next = stoi(line, nullptr, 10);
				mytree->add(next);
			}
			duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
			std::cout << "Einfuegen: " << duration << " Sekunden \n" << std::endl;
			mytree->showstats(true);
			delete mytree;
			std::cout << "Test4 wird gestartet" << endl;
			mytree = new tree();
			ifstream infile4("test4_1-1000_1000-sorted-unique.txt"); //Open filestream
			line = "";
			next = 0;
			start = std::clock();
			while (getline(infile4, line)) { //while next line can be read :D
				next = stoi(line, nullptr, 10);
				mytree->add(next);
			}
			duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
			std::cout << "Einfuegen: " << duration << " Sekunden \n" << std::endl;
			mytree->showstats(true);
			delete mytree;
			std::cout << "Test5 wird gestartet" << endl;
			mytree = new tree();
			ifstream infile5("test5_1-110000_10000-unsorted-unique-primes.txt"); //Open filestream
			line = "";
			next = 0;
			start = std::clock();
			while (getline(infile5, line)) { //while next line can be read :D
				next = stoi(line, nullptr, 10);
				mytree->add(next);
			}
			duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
			std::cout << "Einfuegen: " << duration << " Sekunden \n" << std::endl;
			mytree->showstats(true);
			delete mytree;
			std::cout << "Test6 wird gestartet" << endl;
			mytree = new tree();
			ifstream infile6("test6_1-40000_1000000-unsorted-not-unique.txt"); //Open filestream
			line = "";
			next = 0;
			start = std::clock();
			while (getline(infile6, line)) { //while next line can be read :D
				next = stoi(line, nullptr, 10);
				mytree->add(next);
			}
			duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
			std::cout << "Einfuegen: " << duration << " Sekunden \n" << std::endl;
			mytree->showstats(true);
			delete mytree;
		}
		else {
			ifstream infile(file); //Open filestream
			string line = "";
			int next = 0;
			while (getline(infile, line)) { //while next line can be read :D
				next = stoi(line, nullptr, 10);
				mytree->add(next);
			}
			mytree->showstats(false);
			delete mytree;
		}
	}
	else {
		std::cout << "invalid arguments :C" << endl << "expecting: treecheck <filename>" << endl;
	}


	//expect input to halt program:
	char stahp;
	std::cin >> stahp;
    return 0;
}

