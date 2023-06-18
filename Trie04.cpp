#include <bits/stdc++.h>



using namespace std;



struct Node {
	Node* links[26];

	bool containsKey(char ch) {
		return links[ch - 'a'];
	}

	void put(char ch, Node* node) {
		links[ch - 'a'] = node;

	}

	Node* get(char ch) {
		return links[ch - 'a'];
	}
};



int countDistinctSubstrings(string &s)
{
	int cnt = 1;
	Node* root = new Node();

	for (int i = 0; i < s.size(); ++i) {
		Node* node = root;
		for (int j = i; j < s.size(); ++j) {

			if (!node -> containsKey(s[j])) {
				cnt++;
				node -> put(s[j], new Node());
			}
			node = node -> get(s[j]);
		}
	}

	return cnt;
}


int main() {


	return 0;
}
