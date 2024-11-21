// https://codeforces.com/problemset/problem/1036/C

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define endl "\n"
#define MOD 1000000007

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" -> "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) { cerr << "("; _print(i.first); cerr << " : "; _print(i.second); cerr << ") "; } cerr << "]"; }
template <class T, class V> void _print(unordered_map <T, V> v) { cerr << "{ "; for (auto i : v) { cerr << "("; _print(i.first); cerr << " : "; _print(i.second); cerr << ") "; } cerr << "}";}

vector<vector<vector<ll>>> dp;

ll solve(ll idx, const string& s, ll non_zero, bool high) {
    if(non_zero > 3)
        return 0;

    if(idx >= s.size())
        return 1;

    if(dp[high][idx][non_zero] != -1)
        return dp[high][idx][non_zero];

    //process for zero
    ll ans = solve(idx + 1, s, non_zero, high && s[idx] == '0');

    //check high still going on or not
    if(high) {
        ll value = s[idx] - '0';
        if(value > 0) {
            ans += (value - 1) * solve(idx + 1, s, non_zero + 1, false);
            ans += solve(idx + 1, s, non_zero + 1, high);
        }
    }
    else {
        ans += 9 * solve(idx + 1, s, non_zero + 1, high);
    }

    return dp[high][idx][non_zero] = ans;
}

void saurabh()
{
    ll l, r;
    cin >> l >> r;

    string r_str = to_string(r);
    dp = vector<vector<vector<ll>>>(2, vector<vector<ll>>(r_str.size() + 1, vector<ll>(4, -1)));
    ll ans_r = solve(0, r_str, 0, true);

    string l_str = to_string(l - 1);
    dp = vector<vector<vector<ll>>>(2, vector<vector<ll>>(l_str.size() + 1, vector<ll>(4, -1)));
    ll ans_l = solve(0, l_str, 0, true);

    cout << ans_r - ans_l << endl; 
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        saurabh();
    }

    return 0;
}