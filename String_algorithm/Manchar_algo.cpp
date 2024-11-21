#include <iostream>
#include <vector>

//manchar algorithm use kiya jata hai ki har ek paoint se maximum length ki palindrom kya hogi

using namespace std;

string preprocessString(const string& s) {
    string result = "^";
    for (char c : s) {
        result += "#" + c;
    }
    result += "#$";
    return result;
}

string longestPalindrome(const string& s) {
    string processedString = preprocessString(s);
    int n = processedString.length();
    vector<int> palindromeLength(n, 0);

    int center = 0, right = 0;
    for (int i = 1; i < n - 1; ++i) {
        int mirror = 2 * center - i;
        if (i < right) {
            palindromeLength[i] = min(right - i, palindromeLength[mirror]);
        }

        // Attempt to expand palindrome centered at i
        while (processedString[i + 1 + palindromeLength[i]] == processedString[i - 1 - palindromeLength[i]]) {
            ++palindromeLength[i];
        }

        // If palindrome centered at i expands past right, adjust center and right
        if (i + palindromeLength[i] > right) {
            center = i;
            right = i + palindromeLength[i];
        }
    }

    // Find the maximum element in palindromeLength
    int maxLen = 0, centerIndex = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (palindromeLength[i] > maxLen) {
            maxLen = palindromeLength[i];
            centerIndex = i;
        }
    }

    // Extract the palindrome substring from the original string
    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main() {
    string input = "babad";
    string result = longestPalindrome(input);

    cout << "Input: " << input << endl;
    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}
