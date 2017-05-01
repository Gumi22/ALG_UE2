#pragma once
#include <iostream>
#include <ctime> //Benötigt für Testfunktionen

struct node
{
	int key_value;
	node *left;
	node *right;
};

class tree
{
public:
	tree();
	virtual ~tree();
	void add(int);
	void showstats(bool);

private:
	node *root;
	void insert(node*, int);
	void destroy_tree(node*);
	bool avl(node*, bool);
	int height(node*);
	int min(node*);
	int max(node*);
	double avg();
	int sum(node*);
	int count(node*);
};

