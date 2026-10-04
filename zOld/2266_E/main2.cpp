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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll N = 2 * 1e5 + 5;
    vector<vector<ll>> factors (N);
    vector<bool> isPrime(N, true);
    for (ll i = 2; i < N; i++) {
        if (isPrime[i]) {
            factors[i].push_back(i);
            for (ll j = 2 * i; j < N; j+=i) {
                factors[j].push_back(i);
                isPrime[j] = false;
            }
        }
    }

    //print(isPrime);
    //print(factors);

    // the problem was really not knowing which prime factors to take
    // but there are overlapping subproblems

    // dp[i] = min - s.t. p|i: (1 + p * dp[i/p])

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        vector<ll> dp (n + 1, 1e18);
        for (int i = 1; i <= n; i++) {
            if (i <= k) {
                dp[i] = 0;
                continue;
            }
            for (auto f : factors[i]) {
                dp[i] = min(dp[i], 1 + f * dp[i / f]);
            }
        }

        ll ans = 0;
        for (auto a : arr) {
            ans += dp[a];
        }

        cout << ans << endl;
    }

    
    
    return 0;
}