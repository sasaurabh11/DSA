//z-algo is use to check from index i max matching length
#include <bits/stdc++.h>
using namespace std;

vector<int> calculateZArray(const string& str) {
    int n = str.length();
    vector<int> zArray(n, 0);

    int left = 0, right = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= right) {
            zArray[i] = min(right - i + 1, zArray[i - left]);
        }

        while (i + zArray[i] < n && str[i + zArray[i]] == str[zArray[i]]) {
            ++zArray[i];
        }

        if (i + zArray[i] - 1 > right) {
            left = i;
            right = i + zArray[i] - 1;
        }
    }

    return zArray;
}

void searchPattern(const string& text, const string& pattern) {
    string concatenated = pattern + "$" + text;
    int patternLength = pattern.length();
    vector<int> zArray = calculateZArray(concatenated);

    for (int i = patternLength + 1; i < concatenated.length(); ++i) {
        if (zArray[i] == patternLength) {
            cout << "Pattern found at index " << i - patternLength - 1 << endl;
        }
    }
}

int main()
{
    return 0;
}