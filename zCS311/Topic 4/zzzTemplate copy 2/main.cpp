"""Author: Peter Yu
   It is ok to share my code anonymously for educational purposes"""

//#define LOCAL

#include <bits/stdc++.h>
using namespace std;

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

    int n, k; cin >> n >> k;
    
    // minimum 2 colorings
    // ways = k * (k - 1) ^ (n - 1); ex. 3 * 2 ^ 3 = 24
    // factor = (k choose k - 1) , (k choose k - 2) ...... (k choose 2)

    // Using inclusion exclusion, we find the number of ways to color with exactly k colors
    // by first finding <= k, subtracting <= k - 1, adding back <= k - 2 .... until 2
    // but the caveat is that you can choose k - 1 or k - 2 colors out of the k colors 
    // to color with, so we also take that into account.

    int N = 2600;
    vector<ll> fact(N);
    vector<ll> invfact(N);

    fact[0] = 1, fact[1] = 1;
    for (int i = 2; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    for (int i = 0; i < N; i++) {
        invfact[i] = power(fact[i], MOD - 2);
    }

    print(fact);
    print(invfact);

    ll ans = 0;
    bool sign = true;
    for (int i = k; i >= 2; i--) {
        ll ways = i * power(i - 1, n - 1) % MOD;

        print(ways);

        ways *= ((fact[k] * invfact[i] % MOD) * invfact[k - i]) % MOD;
        ways %= MOD;

        print(ways);

        if (sign) {
            ans += ways;
            ans %= MOD;
        }
        else {
            ans -= ways;
            ans = (ans + MOD) % MOD; 
        }

        sign = !sign;
    }

    cout << ans << endl;


    return 0;
}