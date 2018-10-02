#include <cstdio>
#include <cstdlib>
#include <vector>

#define ALPHABETS 26
#define CASE 'a'
#define MAX_WORD_SIZE 25

using namespace std;

struct node {
	struct node *parent;
	struct node *children[ALPHABETS];
	vector<int> occurrences;
};

void insertWord(struct node *trieTree, char *word, int index) {
	struct node *traverse = trieTree;
	while(*word != '\0') {
		if(traverse->children[*word - CASE] == NULL) {
			traverse->children[*word - CASE] = (struct node*) malloc(sizeof(struct node));
			traverse->children[*word - CASE]->parent = traverse;
		}
		traverse = traverse->children[*word - CASE];
		word++;
	}
	traverse->occurrences.push_back(index); //mark the occurence of the word at the last index
	return;
}

struct node *searchWord(struct node *treeNode, char *word) {
	while(*word != '\0') {
		if(treeNode->children[*word - CASE] != NULL) {
			treeNode = treeNode->children[*word - CASE];
			word++;
		} else {
			break;
		}
	}
	if(*word == '\0' && treeNode->occurrences.size() != 0) {
		return treeNode;
	} else {
		return NULL;
	}
}

void removeWord(struct node *trieTree, char *word) {
	struct node *trieNode = searchWord(trieTree, word);

	if(trieNode == NULL) {
		return;
	}

	trieNode->occurrences.pop_back();
	bool noChild = true;
	int childCount = 0;
	for(int i = 0; i < ALPHABETS; i++) {
		if(trieNode->children[i] != NULL) {
			noChild = false;
			childCount++;
		}
	}

	if(!noChild) {
		return;
	}

	struct node *parentNode;

	while(trieNode->occurrences.size() == 0 && trieNode->parent != NULL && childCount == 0) {
		childCount = 0;
		parentNode = trieNode->parent;

		for(int i = 0; i < ALPHABETS; i++) {
			if(parentNode->children[i] != NULL) {
				if(trieNode == parentNode->children[i]) {
					parentNode->children[i] = NULL;
					free(trieNode);
					trieNode = parentNode;
				} else {
					childCount++;
				}
			}
		}
	}
	return;
}

void lexicographicalPrint(struct node *trieTree, vector<char> word) {
	int i; 
	bool noChild;
	if(trieTree->occurrences.size() != 0) {
		vector<char>::iterator charItr = word.begin();
		while(charItr != word.end()) {
			cout<<charItr;
			charItr++;
		}

		cout<<"\n";

		vector<int>::iterator counter = trieTree->occurrences.begin();
		while(counter != trieTree->occurrences.end()) {
			cout<<counter;
			counter++;
		}
		cout<<"\n";
	}

	for(int i = 0; i < ALPHABETS; i++) {
		if(trieTree->children[i] != NULL) {
			noChild = false;
			word.push_back(CASE + i);

			lexicographicalPrint(trieTree->children[i], word);
			word.pop_back();
		}
	}
	return;
}

int main() {
	int n, i;
	vector<char>printUtil;
	struct node *trieTree = (struct node*)malloc(sizeof(struct node));
	char word[MAX_WORD_SIZE];
	cout<<"Enter the number of words: "<<endl;
	cin>>n;

	for(int i = 0; i < n; i++) {
		cin>>word;
		insertWord(trieTree, word, i);
	}

	cout<<"\n"; bb 
	lexicographicalPrint(trieTree, printUtil);

	cout<<"Enter the word to be removed: "<<endl;
	cin>>word;
	removeWord(trieTree, word);


	cout<<"\n";
	lexicographicalPrint(trieTree, printUtil);
}



