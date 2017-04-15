#include "stdafx.h"
#include "tree.h"


tree::tree()
{
	root = NULL;
}


tree::~tree()
{
	destroy_tree(root);
}

void tree::add(int newint) {
	if (root != NULL)
		insert(root, newint);
	else
	{
		root = new node;
		root->key_value = newint;
		root->left = NULL;
		root->right = NULL;
	}
}

void tree::showstats() {
	avl(root);
	std::cout << "min: " << min(root) << ", max: " << max(root) << ", avg: " << avg() << std::endl;
}

void tree::insert(node* leaf, int key) {
	if (key < leaf->key_value)
	{
		if (leaf->left != NULL)
			insert(leaf->left, key);
		else
		{
			leaf->left = new node;
			leaf->left->key_value = key;
			leaf->left->left = NULL;    //Sets the left child of the child node to null
			leaf->left->right = NULL;   //Sets the right child of the child node to null
		}
	}
	else if (key > leaf->key_value)
	{
		if (leaf->right != NULL)
			insert(leaf->right, key);
		else
		{
			leaf->right = new node;
			leaf->right->key_value = key;
			leaf->right->left = NULL;  //Sets the left child of the child node to null
			leaf->right->right = NULL; //Sets the right child of the child node to null
		}
	}
	//If key == key_value just ignore it and dont add it to the tree
}

void tree::destroy_tree(node *leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void tree::avl(node* leaf) {
	if (leaf != NULL) {
		avl(leaf->right);
		avl(leaf->left);
		int balance = height(leaf->right) - height(leaf->left);
		std::cout << "bal (" << leaf->key_value << ") = " << balance << " " ;
		if (balance > 1 || balance < -1) { std::cout << "(AVL violation!)"; }
		std::cout << std::endl;
	}
	//nothing to do!!!
}

int tree::height(node* leaf) {
	unsigned int h = 0;
	if(leaf != NULL){
		int l = leaf->left ? height(leaf->left) : 0;
		int r = leaf->right ? height(leaf->right) : 0;
		h = (l > r) ? l + 1 : r + 1;
	}
	return h;
}

int tree::min(node* leaf) {
	if (leaf == NULL) {
		return 0;  // Only if the tree contains nothing at all
	}

	if (leaf->left != NULL) {
		return min(leaf->left);
	}

	return leaf->key_value;
}

int tree::max(node* leaf) {
	if (leaf == NULL) {
		return 0;  // Only if the tree contains nothing at all
	}

	if (leaf->right != NULL) {
		return max(leaf->right);
	}

	return leaf->key_value;
}

double tree::avg() {
	if (root != NULL) {
		int s = sum(root);
		int c = count(root);
		return (((double)s) / ((double)c));
	}
	return 0;
}

int tree::sum(node* leaf) {
	unsigned int s = leaf->key_value;
	if (leaf->left != NULL) {
		s += sum(leaf->left);
	}
	if (leaf->right != NULL) {
		s += sum(leaf->right);
	}
	return s;
}

int tree::count(node* leaf) {
	unsigned int c = 1;
	if (leaf->left != NULL) {
		c += count(leaf->left);
	}
	if (leaf->right != NULL) {
		c += count(leaf->right);
	}
	return c;
}