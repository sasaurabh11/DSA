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

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
/*--------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------SEGMENT TREE-------------------------*/
class SegmentTree {
    vector<ll> arr; //type change ll or int
    vector<ll> tree;

    //operation in segment tree
    //     node 
    //   /     \
    //child   child
    //INT_MAX return in case required ans min of range, 0 -> sum of range 
    //INT_MIN -> max in range

    void buildTree(int index, int low, int high) {
        if (low == high) {
            tree[index] = arr[low];
            return;
        }

        int mid = low + ((high - low) / 2);
        buildTree(2 * index + 1, low, mid);
        buildTree(2 * index + 2, mid + 1, high);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2]; // may change according to requirement + or max() or min()
    }

    int query(int index, int low, int high, int l, int r) {
        //no overlap
        //l r low high || low high l r
        if (l > high || r < low) {
            return 0; // Out of range, yaha operation perform kar sakte hai
        }

        //complete overlap
        // [l low high r]
        if (l <= low && r >= high) {
            return tree[index]; // Current segment is fully within the query range
        }
        int mid = low + ((high - low) / 2);
        int left = query(2 * index + 1, low, mid, l, r);
        int right = query(2 * index + 2, mid + 1, high, l, r);
        return left + right;  //operaton perfom
    }

    void Update(int node, int L, int R, int pos, int val)
    {
        if (L == R) {
            tree[node] = val;
            return;
        }

        int M = L + ((R - L) / 2);

        if (pos <= M)
            Update(node * 2 + 1, L, M, pos, val);
        else
            Update(node * 2 + 2, M + 1, R, pos, val);

        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2]; //operation will be perform here
    }

public:
    SegmentTree(const vector<ll>& inputArray) {
        this->arr = inputArray;
        int n = inputArray.size();

        int treeSize = 4 * n + 1;
        tree.resize(treeSize, 0);
        buildTree(0, 0, n - 1);
    }

    int query(int l, int r) {
        return query(0, 0, arr.size() - 1, l, r);
    }

    void update(int index, int value) {
        // arr[index] = value;
        int n = arr.size() - 1;
        Update(0, 0, n, index, value);
    }
};

//================================Template end=================================//

void solve()
{
    
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
        solve();
    }

    // solve();

    return 0;
}