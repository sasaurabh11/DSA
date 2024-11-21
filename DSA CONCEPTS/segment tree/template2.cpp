#include <vector>
using namespace std;

using ll = long long;

struct node {
    ll sum; // Modify or add other properties as needed
    node() : sum(0) {} // Initialize properties as required
};

// Modify merge logic to suit specific operation
node merge(const node &a, const node &b) {
    node ans;
    ans.sum = a.sum + b.sum; // Example: sum operation
    return ans;
}

class SegmentTree {
public:
    SegmentTree(ll n) : N(n) {
        segmentarr.resize(4 * N + 1);
        build(1, 0, N - 1); // Build the tree for the range [0, N-1]
    }

    // Update value at position `pos` with `val`
    void update(ll pos, ll val) {
        update(1, 0, N - 1, pos, val);
    }

    // Query for the range [lq, rq]
    node query(ll lq, ll rq) {
        return query(1, 0, N - 1, lq, rq);
    }

private:
    ll N;
    vector<node> segmentarr;

    // Build segment tree in the range [l, r]
    void build(ll id, ll l, ll r) {
        if (l == r) {
            segmentarr[id].sum = 0; // Initialize leaf nodes
            return;
        }

        ll mid = l + (r - l) / 2;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
        segmentarr[id] = merge(segmentarr[2 * id], segmentarr[2 * id + 1]);
    }

    // Update the value at position `pos` in the range [l, r]
    void update(ll id, ll l, ll r, ll pos, ll val) {
        if (pos < l || pos > r) return; // Out of bounds
        
        if (l == r) {
            segmentarr[id].sum += val; // Update leaf node
            return;
        }

        ll mid = l + (r - l) / 2;
        update(2 * id, l, mid, pos, val);
        update(2 * id + 1, mid + 1, r, pos, val);
        segmentarr[id] = merge(segmentarr[2 * id], segmentarr[2 * id + 1]);
    }

    // Query in the range [lq, rq] within [l, r]
    node query(ll id, ll l, ll r, ll lq, ll rq) {
        if (lq > r || rq < l) {
            return node(); // Return default node for out-of-range queries
        }

        if (lq <= l && r <= rq) {
            return segmentarr[id]; // Complete overlap
        }

        ll mid = l + (r - l) / 2;
        return merge(query(2 * id, l, mid, lq, rq), query(2 * id + 1, mid + 1, r, lq, rq));
    }
};

int main() {
    ll n = 200000; // Segment tree size
    SegmentTree segTree(n);
    
    // Example updates and queries
    segTree.update(5, 10);          // Update position 5 with value 10
    node result = segTree.query(3, 8); // Query the range [3, 8]
    // Access result properties, e.g., result.sum for sum queries

    return 0;
}
