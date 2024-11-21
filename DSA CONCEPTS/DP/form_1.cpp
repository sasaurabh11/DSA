/*
qn -> given -> n
            A => a1, a2, a3, a4, ....
            given => x
            find if x can be made from any subset sum of A array 
*/

/*LCCM => level -> index
        choice -> take/ not take
        check -> <= x
        move -> aage badho
*/

/* step -> 2 : 
 state design : 
 dp[index, sum_taken] = if x can be made from any subset of A[1.....N] given we have already taken sum_taken

step -> 3 : 
    dp[i, sum_taken] = taken dp[i + 1, sum_taken + a[i]]
                        not taken -> dp[i + 1, sum_taken]
*/

// code :-

#include <bits/stdc++.h>
using namespace std;

int n, x;
int arr[1001];
int dp[1010][1010];

int rec(int i, int sum_taken) {
    if(sum_taken > x)
        return 0;

    if(i == n) {
        if(sum_taken == x)
            return 1;
        else 
            return 0;
    }

    if(dp[i][sum_taken] != -1)
        return dp[i][sum_taken];


    int take = rec(i + 1, sum_taken + arr[i]);
    int nottake = rec(i + 1, sum_taken);

    return dp[i][sum_taken] = take | nottake;
}

int main () {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> x;

    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
}