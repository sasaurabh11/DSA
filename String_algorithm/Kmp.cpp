#include <bits/stdc++.h>
using namespace std;

#define ll long long
//use to check if how many times a is present in b
//The Knuth-Morris-Pratt (KMP) algorithm is a string-searching algorithm that efficiently finds occurrences of a pattern within a text.

vector<ll> kmpAlgo(string s) {
    int n = s.length();
    vector<ll> kmp(n + 1);
    int i = 0, j = -1;
    kmp[0] = -1;

    while(i < n) {
        while(j != -1 && s[i] != s[j])
            j = kmp[j];
        i++; j++;
        kmp[i] = j;
    }

    return kmp;
}

int main()
{
    return 0;
}