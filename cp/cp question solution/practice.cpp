#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define endl "\n"
#define MOD 1000000007

#ifndef ONLINE_JUDGE
#include "../debugger/debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

/*-----------------------------------------------------------------------------*/
ll power (ll base, ll x) { if(x < 0) return 0; ll ans = 1; while(x) { if(x % 2 == 0) { base = (base * base) % MOD; x = x / 2; } else { ans = (ans * base) % MOD; x--; } }return ans;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
/*----------------------------------------------------------------------------*/

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

string a, b;
ll n, k, ans;
unordered_map<char, ll> indexes;

void saurabh()
{
    cin >> n >> k;
    cin >> a >> b;

    debug(n, k, a, b);

    set<char> st(a.begin(), a.end());
    vector<char> templ(st.begin(), st.end());

    indexes.clear();
    for(ll i = 0; i < templ.size(); i++) indexes[templ[i]] = i;

    ans = 0;

    ll cnt = 0, tempans = 0;
    for(ll i = 0; i < n; i++) {
        if(a[i] == b[i]) cnt++;
        else {
            tempans += (cnt * (cnt + 1)) / 2;
            cnt = 0;
        }
    }

    tempans += (cnt * (cnt + 1)) / 2;
    ans = max(ans, tempans);

    for(ll mask = 0; mask < (1LL << 10); mask++) {
        if(__builtin_popcount(mask) > k) continue;
        ll cnt = 0, tempans = 0;

        for(ll j = 0; j < n; j++) {
            ll idx = indexes[a[j]];

            if(a[j] == b[j] || (mask & (1LL << idx))) cnt++;
            else {
                tempans += (cnt * (cnt + 1)) / 2;
                cnt = 0;
            }
        }

        tempans += (cnt * (cnt + 1)) / 2;
        ans = max(ans, tempans);
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
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

    return 0;
}

/* int overflow, array bounds
 * special cases (n=1?)
 */