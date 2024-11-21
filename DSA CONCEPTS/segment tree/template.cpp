#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define endl "\n"
#define MOD 1000000007

struct node {
    ll sum;
    node() {
        // change the logic
        sum = 0;
    }
};

node merge(node a, node b) {
    node ans;
    // change merge logic
    ans.sum = a.sum + b.sum;
    return ans;
}

ll N = 2e5; // carefully : update segment array size
vector<node> segmentarr(4 * N + 1);

void build(ll id, ll l, ll r) {
    if(l == r) {
        segmentarr[id].sum = 0;
        return;
    }

    ll mid = l + (r - l) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    segmentarr[id] = merge(segmentarr[2 * id], segmentarr[2 * id + 1]);
}

void update(ll id, ll l, ll r, ll pos, ll val) {
    if(pos < l || pos > r)
        return;
    
    if(l == r) {
        segmentarr[id].sum += val;
        return;
    }

    ll mid = l + (r - l) / 2;
    update(2 * id, l, mid, pos, val);
    update(2 * id + 1, mid + 1, r, pos, val);
    segmentarr[id] = merge(segmentarr[2 * id], segmentarr[2 * id + 1]);
}

node query(ll id, ll l, ll r, ll lq, ll rq) {
    if(lq > r || l > rq) {
        return node();
    }

    if(lq <= l && r <= rq) {
        return segmentarr[id];
    }

    ll mid = l + (r - l) / 2;
    return merge(query(2 * id, l, mid, lq, rq), query(2 * id + 1, mid + 1, r, lq, rq));
}

void saurabh()
{
    ll n, q;
    cin >> n >> q;

    vector<ll> arr(n);
    for(auto &val : arr)
        cin >> val;

    build(1, 0, n - 1);

    while(q--) {
        ll ch; cin >> ch;

        if(ch == 1) {
            ll a, b, u;
            cin >> a >> b >> u;

            // carefull of 0 indexed
            a--; b--;
            update(1, 0, n - 1, a, u);
            if(b + 1 < n)
                update(1, 0, n - 1, b + 1, -u);
        }
        else {
            ll k;
            cin >> k;

            k--;
            node ans = query(1, 0, n - 1, 0, k);
            cout << ans.sum + arr[k] << endl;
        }
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        saurabh();
    }

    // saurabh();

    return 0;
}