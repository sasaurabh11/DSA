#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TrieNode {
public:
    T value;
    unordered_map<T, TrieNode<T>*> children;
    bool isTerminal;

    TrieNode(T val) {
        this->value = val;
        this->isTerminal = false;
    }
};

template <typename T>
class Trie {
private:
    TrieNode<T>* root;

    void insertWord(TrieNode<T>* node, const basic_string<T>& word) {
        if (word.length() == 0) {
            node->isTerminal = true;
            return;
        }

        T ch = word[0];
        TrieNode<T>* child;

        if (node->children.find(ch) != node->children.end()) {
            child = node->children[ch];
        } else {
            child = new TrieNode<T>(ch);
            node->children[ch] = child;
        }

        insertWord(child, word.substr(1));
    }

    bool searchWord(TrieNode<T>* node, const basic_string<T>& word) {
        if (word.length() == 0) {
            return node->isTerminal;
        }

        T ch = word[0];
        TrieNode<T>* child;

        if (node->children.find(ch) != node->children.end()) {
            child = node->children[ch];
        } else {
            return false;
        }

        return searchWord(child, word.substr(1));
    }

    void deleteWord(TrieNode<T>* node, const basic_string<T>& word) {
        if (word.length() == 0) {
            node->isTerminal = false;
            return;
        }

        T ch = word[0];
        TrieNode<T>* child;

        if (node->children.find(ch) != node->children.end()) {
            child = node->children[ch];
        } else {
            return;
        }

        deleteWord(child, word.substr(1));
    }

public:
    Trie() {
        root = new TrieNode<T>('-');
    }

    void insert(const basic_string<T>& word) {
        insertWord(root, word);
    }

    bool search(const basic_string<T>& word) {
        return searchWord(root, word);
    }

    void remove(const basic_string<T>& word) {
        deleteWord(root, word);
    }
};

int main() {
    Trie<char> trie;
    trie.insert("example");
    trie.insert("exams");

    if (trie.search("example"))
        cout << "FOUND" << endl;
    else
        cout << "NOT FOUND" << endl;

    trie.remove("example");

    if (trie.search("example"))
        cout << "FOUND" << endl;
    else
        cout << "NOT FOUND" << endl;

    return 0;
}
