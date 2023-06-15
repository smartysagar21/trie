#include <bits/stdc++.h>



using namespace std;



struct Node {
	Node *links[26];
	int cntEndWith = 0;
	int cntPrefix = 0;

	//check if reference trie is present or not
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}

	//creating reference trie
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}

	//to get the next node for traversal
	Node *get(char ch) {
		return links[ch - 'a'];
	}

	//increasing the value of words that endwith
	void increaseEnd() {
		cntEndWith++;
	}

	//increasing the value of prefix that endwith
	void increasePrefix() {
		cntPrefix++;
	}
    
    //decreasing the value of words
	void deleteEnd() {
		cntEndWith--;
	}
    
    //decreasing the value of prefix 
	void reducePrefix() {
		cntPrefix--;
	}

	int getEnd() {
		return cntEndWith;
	}

	int getPrefix() {
		return cntPrefix;
	}

};

class rie {
private:
	Node* root;

public:
	Trie() {

		//creating new object
		root = new Node();
	}

	void insert(string word) {

		//initializing dummy node pointing to root
		Node *node = root;
		for (int i = 0; i < word.size(); ++i) {
			if (!node -> containKey(word[i])) {
				node -> put (word[i], new Node());
			}

			//moves to reference trie
			node = node -> get(word[i]);
			node -> increasePrefix();
		}

		node -> increaseEnd();

	}

	int countWordsEqualTo (string &word) {
		Node *node = root;
		for (int i = 0; i < word.size(); ++i) {
			if (!node -> containKey(word[i])) {
				return 0;
			}
			else node = node -> get(word[i]);
		}

		return node -> getEnd();
	}

	int countWordsStartingWith(string &prefix) {
		Node *node = root;
		for (int i = 0; i < prefix.size(); ++i) {
			if (!node -> containKey(prefix[i])) {
				return 0;
			}
			else node = node -> get(prefix[i]);
		}

		return node -> getPrefix();
	}

	void erase(string &word) {
		Node *node = root;
		for (int i = 0; i < word.size(); ++i) {
			if (node -> containKey(word[i])) {
				node = node -> get(word[i]);
				node -> reducePrefix();
			}
			else return;
		}

		node -> deleteEnd();
	}
};



int main() {


	return 0;
}
