#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define endl "\n"

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
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//to check number is prime or not
bool sieve(int n) {
    vector<int> primes(n + 1, true);
    
    primes[0] = primes[1] = false;
    
    //sieve time complexity O(n log log n) or O(n)
    for(int i = 2; i * i <= n; i++) {   
        if( primes[i] ) { // i is prime
            // cout << i << " ";
            for(int j = i * i; j <= n; j += i)   // here j is multiple of i
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

int gcd (int a, int b){
    if(a == 0)
        return b;   
    
    return gcd(b % a, a);
}

void saurabh()
{
    int n;
    cin >> n;

    cout << sieve(n) << endl;

    vector<int> ans = prime_factorization(n);
    debug(ans);

    cout << gcd(12, 16) << endl;
    cout << __gcd(12, 16) << endl;
}

int main()
{
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

    // saurabh();

    return 0;
}