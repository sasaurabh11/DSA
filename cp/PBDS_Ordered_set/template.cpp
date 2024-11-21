// OrderedMultiset
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;// find_by_order -> iterator of kth value, order_of_key -> number of elements less than k

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

template <typename T>
struct OrderedMultiset
{
    ordered_set<pair<T, int>> s;
    map<T, int> m;
    void insert(long long element)
    {
        int count = m[element];
        pair<long long, int> p = {element, count};
        m[element]++;
        s.insert(p);
    }

    void erase(long long element)
    {
        if (m.find(element) == m.end())
            return;
        int count = m[element];
        if (count == 1)
            m.erase(element);
        else
            m[element] = count - 1;
        pair<long long, int> eraseP = {element, count - 1};
        s.erase(eraseP);
    }

    int upper_bound(long long element) { return s.order_of_key({element, INT_MAX}); }
    int lower_bound(long long element) { return s.order_of_key({element, -1}); }
    
    long long atIndex(int index) { return (*s.find_by_order(index)).first; }
    bool exists(long long element) { return m.find(element) != m.end(); }
    int occurences(long long element)
    {
        if (m.find(element) == m.end())
        {
            return 0;
        }
        return m[element];
    }
};