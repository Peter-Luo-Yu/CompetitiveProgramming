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

    ll N, R, P; cin >> N >> R >> P;

    // dp[i] = answer for block size i
    vector<ll> dp (N + 1, 1e18);
    dp[1] = 0;

    // i is block size
    for (int i = 1; i <= N; i++) {
        print(i);

        // try to find all blocksize and print statement pairs
        // dp[i] = min(dp[i], j * p + r + dp[blockSize]);

        vector<pair<ll, ll>> pairs; // {blocksize, prints}
        
        // case 1: blocksize x <= sqrt(n)
        for (int x = 1; x <= sqrt(i); x++) {
            ll p = ((i + x - 1) / x) - 1;
            pairs.push_back({x, p});
        }

        // case2: blocksize x > sqrt(n) -> min(p) <= sqrt(n);
        for (int p = 1; p <= sqrt(i); p++) {
            ll x = (i + p) / (p + 1);
            pairs.push_back({x, p});
        }

        //print(pairs);

        for (auto p : pairs) {
            dp[i] = min(dp[i], p.second * P + R + dp[p.first]);
        }



    }

    print(dp);

    cout << dp[N] << endl;

    return 0;
}