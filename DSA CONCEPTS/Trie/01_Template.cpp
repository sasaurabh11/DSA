#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    public : 
        char value;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char val) {
            this->value = val;
            for(int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            this->isTerminal = false;
        }
};

//insertion
void insertWord(TrieNode* root, string word) {
    //base case -> when word length = 0
    if(word.length() == 0) {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';

    TrieNode* child;
    if(root->children[index] != NULL) {
        //present
        child = root->children[index];
    }
    else {
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word) {
    if(word.length() == 0) {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    
    if(root->children[index] != NULL) {
        //present
        child = root->children[index];
    }
    else 
        return false;

    bool recans = searchWord(child, word.substr(1));
    return recans;
}

void deleteWord(TrieNode* root, string word) {
    if(word.length() == 0) {
        root->isTerminal = false;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL) {
        child = root->children[index];
    }
    else    
        return;

    deleteWord(child, word.substr(1));
}

int main() {
    TrieNode* root = new TrieNode('-');

    insertWord(root, "saurabh");
    insertWord(root, "saur");

    if(searchWord(root, "saur")) 
        cout << "FOUND" << endl;
    else    
        cout << "NOTFOUND" << endl;

    deleteWord(root, "saur");

    if(searchWord(root, "saur")) 
        cout << "FOUND" << endl;
    else    
        cout << "NOTFOUND" << endl;

    return 0;
}