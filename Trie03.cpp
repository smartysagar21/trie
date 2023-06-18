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

	bool checkIfAllPrefixExists(string word) {
		Node *node = root;
		bool flag = true;
		for (int i = 0; i < word.size(); i++) {
			if (node->containKey(word[i])) {
				node = node->get(word[i]);
				flag = flag & node->isEnd();
			}
			else {
				return false;
			}
		}
		return flag;
	}


	string completeString(int n, vector<string> &a) {
		Trie* obj = new Trie();
		for (auto word : a) obj->insert(word);
		string longest = "";
		for (auto word : a) {
			if (obj->checkIfAllPrefixExists(word)) {
				if (word.size() > longest.size()) {
					longest = word;
				}
				else if (word.size() == longest.size() && word < longest) {
					longest = word;
				}
			}
		}
		if (longest == "") return "None";
		return longest;
	}
};



int main() {


	return 0;
}
