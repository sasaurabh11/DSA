#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char value;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;

    TrieNode(char val) {
        this->value = val;
        this->isTerminal = false;
    }
};

void printTrie(TrieNode* root, string prefix) {
    if (!root) return;

    // Print current node's details
    cout << "Node Value: " << root->value << ", Is Terminal: " << root->isTerminal << endl;
    if (root->isTerminal) {
        cout << "Word ends at: " << prefix << endl;
    }
    
    // Recursively print each child
    for (auto child : root->children) {
        printTrie(child.second, prefix + child.first);
    }
}

void insertWord(TrieNode* root, const string& word) {
    if (word.length() == 0) {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    TrieNode* child;

    if (root->children.find(ch) != root->children.end()) {
        child = root->children[ch];
    } 
    else {
        child = new TrieNode(ch);
        root->children[ch] = child;
    }

    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, const string& word) {
    if(word.length() == 0) {
        return root->isTerminal;
    }

    char ch = word[0];
    TrieNode* child;

    if(root->children.find(ch) != root->children.end()) {
        child = root->children[ch];
    }
    else    
        return false;

    bool recans = searchWord(child, word.substr(1));
    return recans;
}

void deleteWord(TrieNode* root, const string& word) {
    if(word.length() == 0) {
        root->isTerminal = false;
        return;
    }

    char ch = word[0];
    TrieNode* child;

    if(root->children.find(ch) != root->children.end()) {
        child = root->children[ch];
    }
    else    
        return;

    deleteWord(child, word.substr(1));
}

int main() {
    TrieNode* root = new TrieNode('-');
    insertWord(root, "Saurabh55 Kumar");
    insertWord(root, "Saurabh");

    if(searchWord(root, "Saurabh")) 
        cout << "FOUND" << endl;
    else    
        cout << "NOT FOUND" << endl;

    deleteWord(root, "Saurabh");

    if(searchWord(root, "Saurabh")) 
        cout << "FOUND" << endl;
    else    
        cout << "NOT FOUND" << endl;

    return 0;
}
