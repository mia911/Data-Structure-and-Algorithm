#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
	struct TrieNode *children[26];
	bool isEndOfWord;	
};

struct TrieNode *getNode() {
	struct TrieNode *pNode = new TrieNode;
	pNode->isEndOfWord = false;
	for(int i = 0; i < 26; i++) {
		pNode->children[i] = NULL;
	}
	return pNode;
}

void insert(struct  TrieNode *root, string key) {
	struct TrieNode *pCrawl = root;
	for(int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if(!pCrawl->children[index])
			pCrawl->children[index] = getNode();
		pCrawl = pCrawl->children[index];
	}
	pCrawl->isEndOfWord = true;
	return;
}

bool search(struct TrieNode *root, string key) {
	struct TrieNode *pCrawl = root;
	for(int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if(!pCrawl->children[index])
			return false;
		pCrawl = pCrawl->children[index];
	}
	return (pCrawl != NULL && pCrawl->isEndOfWord);
}

int main () {
	
}