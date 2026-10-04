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

ll MOD = 998244353;

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
    
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        vector<ll> fact (n);
        fact[0] = 1;
        for (int i = 1; i < n; i++) {
            fact[i] = (i * fact[i - 1]) % MOD;
        }

        print(fact);

        vector<ll> fac (n); // factors = (n - 1)! / i
        for (int i = 1; i < n; i++) {
            ll inv = power(i, MOD - 2);

            fac[i] = (fact[n - 1] * inv) % MOD;
        }

        print(fac);

        sort (arr.begin(), arr.end());
        ll ans = 0;
        ll sum = 0;

        int idx = n - 1;
        for (int i = 1; i < n; i++) {
            sum = (sum + fac[idx]) % MOD;
            idx--;

            ans += (sum * arr[i]) % MOD;
            ans %= MOD;
        }

        for (int i = 0; i < n - 1; i++) {
            // forgot when subtracting to be careful
            ans = (ans - ((fac[1] * arr[i]) % MOD) + MOD) % MOD;
            ans %= MOD;
        }

        print(ans);

        cout << ans << endl;

        space;
    }


    return 0;
}