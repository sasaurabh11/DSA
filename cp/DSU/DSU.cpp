#include <bits/stdc++.h>
using namespace std;

#define ll long long 

class DSU {
public:
    vector<ll> parent, rank;
    DSU(ll n){
        parent.resize(n, 0);
        rank.resize(n, 0);
        
        for(ll i=0;i<n;i++) parent[i] = i;
    }
    
    ll Find(ll x){
        return parent[x] = parent[x] == x ? x : Find(parent[x]);
    }
    
    bool Union(ll x, ll y){
        ll xset = Find(x), yset = Find(y);
        if(xset != yset){
            rank[xset] < rank[yset] ? parent[xset] = yset : parent[yset] = xset;
            rank[xset] += rank[xset] == rank[yset];
            return true;
        }
        return false;
    }
};