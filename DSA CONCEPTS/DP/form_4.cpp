/*form - 4 -> longest palindromic substring
    LR dp=> 

    [d, b, c, b, d, a, b, a]

step - 2 => dp[l, r] -> is this palindrome 

step - 3 => dp[l -- r] = arr[l] == arr[r] && dp[l + 1, r - 1]
*/

#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int dp[1010][1010];

int rec(int l, int r) { // is s[l -- r] is palindrome?
    if(r - l + 1 <= 1)
        return 1;

    if(dp[l][r] != -1)
        return dp[l][r];

    int ans = (s[l] == s[r]) && dp[l + 1][r - 1];

    return dp[l][r] = ans;    
}

int main () {
    cin >> n;
    cin >> s;

    memset(dp, -1, sizeof(dp));
    
    int ans = 0;
    for(int st = 0; st < n; st++) {
        for(int ed = st; ed < n; ed++) {
            if(rec(st, ed)) {
                ans = max(ans, ed - st + 1);
            }
        }
    }

    cout << ans << endl;
}