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

vector<ll> fact, invfact;

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll C (ll n, ll k) {
    return ((fact[n] * invfact[k] % MOD) * invfact[n - k]) % MOD;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // so the observation was to break the cases down based on the number of steps
    // if we have k steps
    // you have dx1 + dx2 + ... + dxk = n
    // this is the stars and bars shit with n candies and k - 1 bars, k buckets
    // but dx1 >= x, since all steps are at least x
    // which means each bucket must contain at least x candies
    // so we have n - kx candies and k - 1 bars, k buckets
    // answer is (n - kx - k - 1) choose (k - 1)

    // since the y's are independent, you multiply the 2 chooses up


    int N = 1e6 + 5;
    fact = vector<ll> (N); invfact = vector<ll> (N);

    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (i * fact[i - 1]) % MOD;
    }
    for (int i = 0; i < N; i++) {
        invfact[i] = power(fact[i], MOD - 2);
    }


    ll n, x, y; cin >> n >> x >> y;

    ll ans = 0;
    for (int k = 1; k <= n / max(x, y); k++) {
        ll X = C(n - k * x + k - 1, k - 1);
        ll Y = C(n - k * y + k - 1, k - 1);

        print(X, Y);

        ans += (X * Y) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
   

    return 0;
}