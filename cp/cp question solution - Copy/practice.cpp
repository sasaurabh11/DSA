#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll n, string& a, string& b, vector<char>& templ) {
    ll m = templ.size();
    ll ans = 0;
    
    // Precompute character indices
    vector<vector<ll>> charIndices(m);
    for(ll i = 0; i < m; i++) {
        for(ll j = 0; j < n; j++) {
            if(templ[i] == a[j]) {
                charIndices[i].push_back(j);
            }
        }
    }
    
    // Iterate through all possible bitmasks efficiently
    for(ll mask = 0; mask < (1LL << m); mask++) {
        vector<bool> fixed(n, false);
        
        // Mark characters that can be fixed
        for(ll i = 0; i < m; i++) {
            if(mask & (1LL << i)) {
                for(ll idx : charIndices[i]) {
                    fixed[idx] = true;
                }
            }
        }
        
        // Count bad pairs
        ll tempans = 0, cnt = 0;
        for(ll j = 0; j < n; j++) {
            if(a[j] == b[j] || fixed[j]) {
                cnt++;
            } else {
                tempans += (cnt * (cnt + 1)) / 2;
                cnt = 0;
            }
        }
        
        // Handle last sequence
        tempans += (cnt * (cnt + 1)) / 2;
        
        ans = max(ans, tempans);
    }
    
    return ans;
}

void saurabh() {
    ll n, k;
    string a, b;
    
    cin >> n >> k;
    cin >> a >> b;
    
    // Get unique characters
    set<char> st(a.begin(), a.end());
    vector<char> templ(st.begin(), st.end());
    
    cout << solve(n, a, b, templ) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--) {
        saurabh();
    }
    
    return 0;
}