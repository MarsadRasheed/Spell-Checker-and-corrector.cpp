#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class tnode {
public:
	string word;
	tnode* left;
	tnode* right;
	tnode() {
		left = NULL;
		right = NULL;
	}
};

class BST {
private:
	tnode* root;

public:
	BST() {
		root = NULL;
	}

	tnode* getRoot() {
		return (this->root);
	}

	void inorder(tnode* rot);
	void insert(string word);
	bool search(string w);
};

void BST::insert(string word) {

	tnode* temp = new tnode;
	temp->left = NULL;
	temp->right = NULL;
	temp->word = word;

	if (root == NULL) {
		root = temp;
	}
	else {
		tnode* next = root;
		tnode* current = root;
		while (next != NULL) {
			current = next;
			if ( word.compare(next->word) > 0 ) {
				next = next->right;
			}
			else if(word.compare(next->word) < 0){
				next = next->left;
			}
		}

		if (word.compare(current->word) > 0) {
			current->right = temp;
		}
		else if(word.compare(current->word) < 0){
			current->left = temp;
		}
	}
}

void BST :: inorder(tnode* rot) {

	if (rot == NULL) {
		return;
	}
	else {
		inorder(rot->left);
		cout << rot->word << "  ";
		inorder(rot->right);
	}
}

bool BST::search(string word) {
	tnode* temp;
	temp = root;
	if (temp == NULL) {
		return 0;
	}
	else {
		while (temp!= NULL) {
			if (word.compare(temp->word) > 0) {
				temp = temp->right;
			}
			else if (word.compare(temp->word) == 0 ) {
				//cout << word << " is found" << endl;
				return true;
			}
			else if (word.compare(temp->word) < 0 ) {
				temp = temp->left;
			}
		}
		//cout << word << " is not found" << endl;
	}
	return false;
}
