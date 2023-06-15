#include <bits/stdc++.h>



using namespace std;



struct Node {
	Node *links[26];
	bool flag = false;

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

	//setting flag to ture at the end of the word
	void setEnd() {
		flag = true;
	}

	//checking if the word is conpleted or not
	bool isEnd() {
		return flag;
	}

};

class Trie {
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
		}

		node -> setEnd();
	}

	bool search (string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); ++i) {
			if (!node -> containKey(word[i])) {
				return false;
			}
			node = node -> get(word[i]);
		}

		return node -> isEnd();
	}

	bool startsWith(string prefix) {
		Node *node = root;
		for (int i = 0; i < prefix.size(); ++i) {
			if (!node -> containKey(prefix[i])) {
				return false;
			}
			node = node -> get(prefix[i]);
		}

		return true;
	}
};



int main() {


	return 0;
}
