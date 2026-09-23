//#define LOCAL

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#ifdef LOCAL
#define print(...) debug(#__VA_ARGS__, __VA_ARGS__)
#define space cerr << "----------" << endl;
#else
#define print(...) 6
#define space 7
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p);
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr> ostream& operator << (ostream &os, const C &c);

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T, typename enable_if<!is_same<C, string>::value>::type*> ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}

template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}


#define ll long long
#define ld long double
#define endl "\n"

ll MOD = 1e9 + 7;

ll power (ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // the whole point of setting N = 1e7 is to kill the 
    // strategy of precomputing the answer for all N up to 1e7
    // however, we only have up to 25 test cases,
    // which means we just need to quickly compute the answer to those tests 
    // Tatha told me to use legendre theorem

    ll N = 1e7 + 5;
    vector<bool> isPrime(N, true); // smallest prime factor
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j < N; j += i) {
                isPrime[j] = false;     
            }
        }
    }

    vector<ll> primes;
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    
    //print(primes, primes.size());

    string s;
    while (s != "0") { 
        getline(cin, s);

        if (s == "0") break;
        //cout << s << endl;

        ll n = stoi(s);

        ll ans = 1;

        for (auto p : primes) {
            ll exp = 0;
            ll cur = p;
            while (cur <= n) {
                exp += n / cur;
                cur *= p;
            }

            if (exp > 0) {
                if (exp % 2 == 1) {
                    exp--;
                }

                if (exp > 0) {
                    ans *= power(p, exp);
                    ans %= MOD;
                }
            }
        }
        
        cout << ans << endl;
    }
        
        
        
        

    return 0;
}