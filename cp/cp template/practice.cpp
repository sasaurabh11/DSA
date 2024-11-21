#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define endl "\n"
#define MOD 1000000007

/*policy based data structure*/
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order -> iterator of kth value, order_of_key -> number of elements less than k

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
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) { cerr << "("; _print(i.first); cerr << " : "; _print(i.second); cerr << ") "; } cerr << "]"; }
template <class T, class V> void _print(unordered_map <T, V> v) { cerr << "{ "; for (auto i : v) { cerr << "("; _print(i.first); cerr << " : "; _print(i.second); cerr << ") "; } cerr << "}";}

//-----------------------------------------DEBUG END---------------------------------------------------------------------------------
//math operations
//to check number is prime or not
bool sieve(int n) {
    vector<bool> primes(n + 1, true);
    
    primes[0] = primes[1] = false;
    
    //sieve time complexity O(n log log n) or O(n)
    for(int i = 2; i * i <= n; i++) {   
        if( primes[i] ) { // i is prime
            // cout << i << " ";
            for(int j = 2 * i; j <= n; j += i)   // here j is multiple of i
                primes[j] = false;
        }
    }

    return primes[n];
}

//to calculate all prime factorization of a number
vector<int> prime_factorization(int n) {
    vector<int> spf (n + 5, -1);

    for(int i = 2; i < n + 5; i++){

        if(spf[i] == -1)
            for(int j = i; j < n + 5; j += i)  
                if(spf[j] == -1) spf[j] = i;
    }

    vector<int> ans;

    int m = n;
    while(m > 1){
        ans.push_back(spf[m]);
        m /= spf[m];
    }

    return ans;
}

#define MAXN 1000100
ll is_Prime[MAXN];
ll primeFactors[MAXN];
vector<ll> primeFactorsAll[MAXN];

void calculate_how_many_prime_factors_a_number_have () {
    for(ll i = 2; i < MAXN; i++) {
        is_Prime[i] = 1;
        primeFactors[i] = 0;
    }

    for(ll i = 2; i < MAXN; i++) {
        if(is_Prime[i]) {
            primeFactors[i] = 1;
            primeFactorsAll[i].push_back(i);
            for(ll j = 2 * i; j < MAXN; j += i) {
                is_Prime[j] = 0;
                primeFactors[j]++;
                primeFactorsAll[j].push_back(i);
            }
        }
    }
}

ll power (ll base, ll x) { if(x < 0) return 0;
    ll ans = 1; while(x) { if(x % 2 == 0) { base = (base * base) % MOD; x = x / 2; } else { ans = (ans * base) % MOD; x--; } }
    return ans;
}

/*-------------------------------COMBINATORICS OPERATIONS-------------------------------*/
/*
ll fact[1000004];
void precomp() {
    fact[0] = 1;
    for(ll i = 1; i <= 1000000; i++) {
        fact[i] = (i * fact[i - 1]) % MOD;
    }
}

ll nCr (ll n, ll r) {
    if(n < 0 || r < 0 || r > n) return 0;

    precomp(); // calling for factorial 

    ll numo = fact[n];
    ll deno = (fact[r] * fact[n - r]) % MOD;

    debug(deno);
    ll ans = (numo * power(deno, MOD - 2)) % MOD;
    return ans;
}
*/

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
/*--------------------------------------------------------------------------------------------------------------------------*/


//=========================================================================================
//algorithms

void kadane(int n, vector<int> arr) {
    int current_sum = 0;
    int max_sum = arr[0];

    for(int i = 0; i < n; i++) {
        //here basically current_sum represent window, jisme ek subaray ki value dekh rahe hai        
        current_sum = current_sum + arr[i];
        
        //max_sum total answer batayega
        max_sum = max(max_sum, current_sum);


        if(current_sum < 0)
            current_sum = 0;

        debug(max_sum);
    }

    cout << max_sum << endl;
}

//ceil of two number => a/b = (a + b - 1) / b;

//================================Template end=================================//

void saurabh()
{
    int n;
    cin >> n;

    int r;
    cin >> r;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int t = 1;
    // cin >> t;
    while (t--)
    {
        saurabh();
    }

    // saurabh();

    return 0;
}