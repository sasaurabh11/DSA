/*form - 5 -> game dp

qn -> there are n stones, alice and bob play game, kya alice jeet payega?
dp[i] -> there are i stones can player win 

step 2 :
dp[i] = losing
    if dp[i - 1] || dp[i - 2] || dp[i - 3] losing then dp[i] = winning
    */

#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1010];

int rec(int x) { 
    if(x == 0)
        return 0;

    if(dp[x] != -1)
        return dp[x];

    int ans = 0;
    if(x - 1 >= 0 && rec(x - 1) == 0) ans = 1;
    if(x - 2 >= 0 && rec(x - 2) == 0) ans = 1;
    if(x - 3 >= 0 && rec(x - 3) == 0) ans = 1;

    return dp[x] = ans;
}

int main () {
    cin >> n;
    if(rec(n))
        cout << "ALICE" << endl;
    else    
        cout << "BOB" << endl;
}