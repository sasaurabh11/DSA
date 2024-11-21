#include<bits/stdc++.h>
using namespace std;

using ll = long long;

//first form divide in some parts and then minimise something maximum or maximise something minimum
bool check(ll mid, vector<ll>& arr, ll t) {
    int sum_left = 0, numbers_of_division = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(sum_left >= arr[i]) {
            sum_left -= arr[i];
        } else {
            numbers_of_division++;
            if(numbers_of_division > t) return false;

            sum_left = mid;

            if(sum_left < arr[i]) return false;
            else {
                sum_left -= arr[i];
            }
        }
    }

    if(numbers_of_division <= t)   return true;
    else return false;
}

void solve()
{
    ll n, t; cin >> n >> t;
    vector<ll> arr(n);

    for(auto &val : arr) {
        cin >> val;
    }

    ll lo = 0, hi = 1e9, ans = -1;

    while(lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if(check(mid, arr, t)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}