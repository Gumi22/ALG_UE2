// treecheck.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
// checks if a tree is an AVL tree and gives various other information.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "tree.h"


int main(int argc, char* argv[]) //Poject properties -> debugging argument -> testtree.txt is the testfile
{
	using namespace std;

	if (argc == 2) { //everythings alright, arguments were listed correct :D
		tree* mytree = new tree;
		string file = argv[1];
		ifstream infile(file); //Open filestream
		string line = "";
		int next = 0;
		while (getline(infile, line)) { //while next line can be read :D
			next = stoi(line, nullptr, 10);
			mytree->add(next);
		}
		mytree->showstats();
		delete mytree;
	}
	else {
		cout << "invalid arguments :C" << endl << "expecting: treecheck <filename>" << endl;
	}


	//expect input to halt program:
	char stahp;
	cin >> stahp;
    return 0;
}

