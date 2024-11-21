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
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//-----------------------------------------DEBUG END---------------------------------------------------------------------------------

ll power (ll base, ll x) { if(x < 0) return 0;
    ll ans = 1; while(x) { if(x % 2 == 0) { base = (base * base) % MOD; x = x / 2; } else { ans = (ans * base) % MOD; x--; } }
    return ans;
}
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
/*--------------------------------------------------------------------------------------------------------------------------*/

//================================Template end=================================//

void DFS(vector<int> adjList[], int node, int par, vector<vector<int>>& parent_dp) {
    parent_dp[node][0] = par;
    for(int i = 1; i <= 16; i++) {
        parent_dp[node][i] = parent_dp[parent_dp[node][i - 1]][i - 1];
    }

    for(auto it : adjList[node]) {
        if(it == par) continue;

        DFS(adjList, it, node, parent_dp);
    }
}

void saurabh()
{
    int n; cin >> n;
    vector<int> adjList[n + 1];

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<vector<int>> parent_dp(n + 1, vector<int>(17, 0));
    DFS(adjList, 1, 0, parent_dp);

    debug(parent_dp);

    int q;
    cin >> q;
    while(q--) {
        int node, k;
        cin >> node >> k;
        //print kth parent of node
        for(int i = 16; i >= 0; i--) {
            if((k >> i) & 1) {
                node = parent_dp[node][i];
            }

        }
        cout << node << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int t = 1;
    // cin >> t;
    while (t--)
    {
        saurabh();
    }

    // saurabh();

    return 0;
}