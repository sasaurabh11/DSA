#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define endl "\n"
#define MOD 1000000007

struct node {
    ll lazy;
    ll sum;
    node() {
        lazy = 0;
        sum = 0;
    }
};

node merge(node a, node b) {
    node ans;
    ans.sum = a.sum + b.sum;
    return ans;
}

ll N = 2e5; // carefully : update segment array size
vector<node> segmentarr(4 * N + 1);

void push(ll id, ll l, ll r) {
    if(segmentarr[id].lazy != 0) {
        // if there is lazy present, apply to this node
        segmentarr[id].sum += (r - l + 1) * segmentarr[id].lazy;

        // push down to childs
        if(l != r) {
            segmentarr[2 * id].lazy += segmentarr[id].lazy;
            segmentarr[2 * id + 1].lazy += segmentarr[id].lazy;
        }

        //clear
        segmentarr[id].lazy = 0;
    }
}

void build(ll id, ll l, ll r) {
    if(l == r) {
        segmentarr[id].sum = 0;
        segmentarr[id].lazy = 0;
        return;
    }

    ll mid = l + (r - l) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    segmentarr[id] = merge(segmentarr[2 * id], segmentarr[2 * id + 1]);
}

void update(ll id, ll l, ll r, ll lq, ll rq, ll val) {
    push(id, l, r);

    if(lq > r || l < rq)
        return;
    
    if(lq <= l && r <= rq) {
        segmentarr[id].lazy += val;
        push(id, l, r);
        return;
    }

    ll mid = l + (r - l) / 2;
    update(2 * id, l, mid, lq, rq, val);
    update(2 * id + 1, mid + 1, r, lq, rq, val);
    segmentarr[id] = merge(segmentarr[2 * id], segmentarr[2 * id + 1]);
}

node query(ll id, ll l, ll r, ll lq, ll rq) {
    push(id, l, r);
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
    
}

int main()
{
    int t = 1;
    while (t--)
    {
        saurabh();
    }
    return 0;
}