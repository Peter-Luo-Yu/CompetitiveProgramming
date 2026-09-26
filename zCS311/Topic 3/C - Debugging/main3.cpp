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


// a very cooked problem
// because can choose to have multiple 
// print statements per run


ll N, R, P; 
vector<ll> dp;

// x is the cur block size
void recurse(ll blocksize) {
    if (blocksize == 1) {
        dp[blocksize] = 0;
        return;
    }

    // don't forget to memoize
    if (dp[blocksize] != 1e18) {
        return;
    }

    vector<pair<ll, ll>> pairs; // {blocksize, prints}
        
    // case 1: blocksize x <= sqrt(n)
    // relationship is x = ceil(n/(p + 1)), we solve for min prints
    // By def x >= n / (p + 1)
    // x(p + 1) >= n
    // p + 1 >= n / x
    // p >= ceil(n / x) - 1

    for (int x = 1; x <= sqrt(blocksize); x++) {
        ll p = ((blocksize + x - 1) / x) - 1;
        pairs.push_back({x, p});
    }

    // case2: blocksize x > sqrt(n) -> min(p) <= sqrt(n);
    // easy: x = ceil(n / (p + 1))
    for (int p = 1; p <= sqrt(blocksize); p++) {
        ll x = (blocksize + p) / (p + 1);
        pairs.push_back({x, p});
    }

    //print(pairs);
    
    for (auto p : pairs) {
        recurse(p.first);
        dp[blocksize] = min(dp[blocksize], p.second * P + R + dp[p.first]);
    }
}



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> N >> R >> P;

    // dp[i] = answer for block size i
    dp = vector<ll> (N + 1, 1e18);

    recurse(N);

    print(dp);

    cout << dp[N] << endl;

    return 0;
}