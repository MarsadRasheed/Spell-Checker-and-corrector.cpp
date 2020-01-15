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


class spellCorrector {
public:
	string refinedForm(string word);
	string missingCase(BST tree,string word);
	string extraCase(BST tree,string word);
	string misplacedCase(BST tree, string word);
};

string spellCorrector :: refinedForm(string word) {

	int length = word.length();

	int k = length;
	int l = length;
	int m = length;
	int g = length;
	int h = length;

	if (word[--k] == 's' && word[--k] == 'e' && word[--k] == 'i') {
		word.erase(k, length);
		word.append(1, 'y');
		return word;
	}
	else if (word[--l] == 'g' && word[--l] == 'n' && word[--l] == 'i') {
		word.erase(l, length);
		word.append(1, 'e');
		return word;
	}
	else if ((word[--m] == 's' || word[m] == 'y' || word[m] == 'd') && (word[--m] == 'e' || word[m] == 'l' || word[m] == 'd')) {
		word.erase(m, length);
		return word;
	}
	else if ((word[--g] == 's' || word[g] == 'd') && (word[--g] == 'e')) {
		word.erase(length);
		return word;
	}
	else if (word[--h] == 's') {
		word.erase(h);
		return word;
	}
	return word;
}

string spellCorrector :: missingCase(BST tree, string word) {

	int len = word.length() + 1;
	char alpha[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

	for (int i = 0; i < len; i++) {
		word.insert(i, 1, 'a');
		for (int j = 0; j < 26; j++) {
			word[i] = alpha[j];
			if (tree.search(word)) {
				cout << word << " is found missing case" << endl;
				return word;
			}
			else {
				continue;
			}
		}
		word.erase(i, 1);
	}
	return "";
}
