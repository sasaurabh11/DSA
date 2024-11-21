#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct segmenttree
{
    ll n;
    vector<ll> st, lazy;

    void init(ll _n)
    {
        this->n = _n;
        st.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    ll merge(ll a, ll b)
    {
        return max(a, b); // Change this to suit problem
    }

    void push(ll start, ll ending, ll node)
    {
        if (lazy[node])
        {
            st[node] = merge(lazy[node], st[node]);

            if (start != ending)
            {
                lazy[2 * node + 1] = merge(lazy[2 * node + 1], lazy[node]);
                lazy[2 * node + 2] = merge(lazy[2 * node + 2], lazy[node]);
            }

            lazy[node] = 0;
        }
    }

    ll query(ll start, ll ending, ll l, ll r, ll node)
    {
        push(start, ending, node);

        if (start > r || ending < l)
        {
            return 0; // Neutral value for `max`. Use `ll_MIN` for stricter max logic.
        }

        if (start >= l && ending <= r)
        {
            return st[node];
        }

        ll mid = (start + ending) / 2;

        ll q1 = query(start, mid, l, r, 2 * node + 1);
        ll q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return merge(q1, q2);
    }

    void update(ll start, ll ending, ll node, ll l, ll r, ll value)
    {
        push(start, ending, node);

        if (start > r || ending < l)
        {
            return;
        }

        if (start >= l && ending <= r)
        {
            lazy[node] = value;
            push(start, ending, node);
            return;
        }

        // Partial case
        ll mid = (start + ending) / 2;

        update(start, mid, 2 * node + 1, l, r, value);
        update(mid + 1, ending, 2 * node + 2, l, r, value);

        st[node] = merge(st[node * 2 + 1], st[node * 2 + 2]);

        return;
    }

    ll query(ll l, ll r)
    {
        return query(0, n - 1, l, r, 0);
    }

    void update(ll l, ll r, ll x)
    {
        update(0, n - 1, 0, l, r, x);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll tt; cin >> tt;

    while(tt--) {
        ll n; cin >> n;
        vector<ll>a(n), answer(n);
        for(auto &i : a) cin >> i;

        multiset<ll>ms; ms.insert(0);
        for(auto &i : a) ms.insert(i); 

        segmenttree tree; tree.init(n + 1);

        for(ll i = n - 1; i >= 0; i--) {
            answer[i] = max({tree.query(0, a[i] - 1), *ms.rbegin(), tree.query(0, *ms.rbegin() - 1)});
            tree.update(a[i], n, answer[i]);
            ms.erase(ms.find(a[i]));
        }

        for(ll i = 0; i < n; i++) {
            cout << answer[i] << " \n"[i == n - 1];
        }
    }
}