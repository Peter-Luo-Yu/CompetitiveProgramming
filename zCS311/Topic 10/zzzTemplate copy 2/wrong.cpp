#define LOCAL

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


#define int long long
#define lll __int128_t
#define ld long double
#define endl "\n"

int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}


// BEGIN CODE -----

int n;
map<vector<vector<bool>>, int> dp; // state -> # tilings

void solve (vector<vector<bool>> &cur) { // current state
    //print(cur);
    
    int amt = 0;
    for (int i = 0; i < cur.size(); i++) {
        for (int j = 0; j < cur[i].size(); j++) {
            amt += (cur[i][j]);
        }
    }

    //print(amt);

    if (amt == 0) { // base case
        dp[cur] = 1;
        return;
    }


    // memoized case
    if (dp[cur] != 0) {
        return;
    }

    // recurse into substate
    vector<vector<bool>> next;
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (cur[i][j] && cur[i + 1][j]) {
                next = cur;
                next[i][j] = false;
                next[i + 1][j] = false;
                solve(next);
                dp[cur] = dp[next] + 1;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (cur[i][j] && cur[i][j + 1]) {
                next = cur;
                next[i][j] = false;
                next[i][j + 1] = false;
                solve(next);
                dp[cur] = dp[next] + 1;
            }
        }
    }
   
    
}

int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif    
    

    while (true) {
        cin >> n;
        if (n == -1) break;

        if (n == 0 || n % 2 == 1) {
            cout << 0 << endl;
            continue;
        }

        vector<vector<bool>> arr (3, vector<bool> (n, true));

        solve(arr);    
    
        print(dp);




        space;
    }


    return 0;
}