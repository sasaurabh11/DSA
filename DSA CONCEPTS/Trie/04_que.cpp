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

vector<string> ans;

void matchwords(TrieNode* root, string templatestr) {
    if(root->isTerminal == true) {
        ans.push_back(templatestr);
    }

    for(auto val : root->children) {
        matchwords(val.second, templatestr + val.first);
    }
}

void searchMatching(TrieNode* root, const string& temp) {
    if(temp.length() == 0) {
        matchwords(root, temp);
        return;
    }

    char ch = temp[0];
    TrieNode* child;

    if(root->children.find(ch) != root->children.end()) {
        child = root->children[ch];
    }
    else {
        cout << "NOT FOUND MATCH TEMPLATE" << endl;
        return;
    }

    searchMatching(child, temp.substr(1));
}

int main() {
    TrieNode* root = new TrieNode('-');
    insertWord(root, "Saurabh Kumar");
    insertWord(root, "Saurabh");
    insertWord(root, "check");
    insertWord(root, "Saur");
    insertWord(root, "Saurabh55 Kumar");

    string temp = "d";
    searchMatching(root, temp);

    for(auto val : ans) 
        cout << temp <<  val << endl;

    return 0;
}
