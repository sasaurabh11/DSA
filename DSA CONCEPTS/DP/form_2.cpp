/*form 2 -> 
    'ending at'
    use on 'subsequence/ partition'

qn -> 
    what will be LIC for arr[1, 3, 2, 5, 9, 8, ]

step - 1 -> so I need to calculate Longest increasing subsequence till i 

step - 2 -> dp[i] = longest increasing subsequence ending at i

step - 3 -> transition
    dp[i] -> 1
          \> for all j -> dp[j] + 1
          where arr[i] > arr[j]
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1001];
int dp[1010];

int rec(int i) {
    if(i < 0)
        return 0;

    if(dp[i] != -1)
        return dp[i];

    int len = 1;
    for(int j = i - 1; j >= 0; j--) {
        if(arr[i] > arr[j])
            len = max(len, 1 + dp[j]);
    }

    return dp[i] = len;
}

int main () {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    memset(dp, -1, sizeof(dp));
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, rec(i));
    }
}