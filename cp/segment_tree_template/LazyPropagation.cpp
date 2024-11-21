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
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) { cerr << "("; _print(i.first); cerr << " : "; _print(i.second); cerr << ") "; } cerr << "]"; }
template <class T, class V> void _print(unordered_map <T, V> v) { cerr << "{ "; for (auto i : v) { cerr << "("; _print(i.first); cerr << " : "; _print(i.second); cerr << ") "; } cerr << "}";}


//-----------------------------------------DEBUG END ----------------------------------------------------------------------

ll power (ll base, ll x) { if(x < 0) return 0;
    ll ans = 1; while(x) { if(x % 2 == 0) { base = (base * base) % MOD; x = x / 2; } else { ans = (ans * base) % MOD; x--; } }
    return ans;
}

/*-----------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
/*----------------------------------------------------------------------------*/

//================================Template end=================================//

class LazySegmentTree {
private:
    vector<int> arr;
    vector<int> tree;
    vector<int> lazy;

    void buildTree(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;
        buildTree(2 * node, start, mid);
        buildTree(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void updateRange(int node, int start, int end, int l, int r, int val) {
        if (lazy[node] != 0) {
            // Update node and propagate lazy value
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > end || start > r || end < l) {
            // No overlap
            return;
        }

        if (start >= l && end <= r) {
            // Complete overlap, update node and propagate lazy value
            tree[node] += (end - start + 1) * val;
            if (start != end) {
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }
            return;
        }

        // Partial overlap, recur for children
        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int queryRange(int node, int start, int end, int l, int r) {
        if (lazy[node] != 0) {
            // Update node and propagate lazy value
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > end || start > r || end < l) {
            // No overlap
            return 0;
        }

        if (start >= l && end <= r) {
            // Complete overlap
            return tree[node];
        }

        // Partial overlap, recur for children
        int mid = (start + end) / 2;
        int left = queryRange(2 * node, start, mid, l, r);
        int right = queryRange(2 * node + 1, mid + 1, end, l, r);
        return left + right;
    }

public:
    LazySegmentTree(const vector<int>& input) {
        arr = input;
        int n = arr.size();
        tree.resize(4 * n + 1, 0);
        lazy.resize(4 * n + 1, 0);
        buildTree(1, 0, n - 1);
    }

    void updateRange(int l, int r, int val) {
        updateRange(1, 0, arr.size() - 1, l, r, val);
    }

    int queryRange(int l, int r) {
        return queryRange(1, 0, arr.size() - 1, l, r);
    }
};

void saurabh()
{
    int n; cin >> n;
    cout << "HELLO WORLD" << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        saurabh();
    }

    // saurabh();

    return 0;
}

/*XOR Operation
 * 0 ^ x = x
 * 1 ^ bit = reverse bit
*/

/* int overflow, array bounds
 * special cases (n=1?)
 */