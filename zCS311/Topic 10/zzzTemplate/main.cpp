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



int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif   
    
    // we need to pick out the k smallest valued rooms
    // while satisfying the condition that the visitor
    // can still pass through the entire gallery
    
    int n, K; cin >> n >> K;

    int sum = 0;
    vector<pair<int, int>> arr (n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        sum += arr[i].first + arr[i].second;
    }

    print(arr);
    print(sum);

    // dp[i][j][k] = best value taken out when: i -> up to row i, j -> number of blocked rooms
    // k = 1 if left is blocked, k = 2 if right is blocked, k = 0 both free
    vector<vector<vector<int>>> dp (n + 1, vector<vector<int>> (K + 1, vector<int> (3, 1e18)));

    
    // initialize selecting 0 numbers to get taken out
    for (int i = 0; i <= n; i++) {
        dp[i][0][0] = 0;
        dp[i][0][1] = 0;
        dp[i][0][2] = 0;
    }
    

    for (int i = 1; i <= n; i++) { // rows
        for (int j = 1; j <= K; j++) { // amt of numbers subtracted
            // choose left: increases j
            dp[i][j][1] = min(min(dp[i-1][j-1][0], dp[i-1][j-1][1]) + arr[i - 1].first, dp[i][j][1]);
            
            // choose right: increases j
            dp[i][j][2] = min(min(dp[i-1][j-1][0], dp[i-1][j-1][2]) + arr[i - 1].second, dp[i][j][2]);
       
            // don't choose any number: doesn't increase j
            dp[i][j - 1][0] = min(min(dp[i-1][j-1][0], min(dp[i-1][j-1][1], dp[i-1][j-1][2])), dp[i][j - 1][0]);

        }
    }

    /*
    for (int i = 0; i <= n; i++) {
        cout << "i: " << i << endl;
        for (int j = 0; j <= K; j++) {
            cout << "j: " << j << " | " << dp[i][j][0] << " " << dp[i][j][1] << " " << dp[i][j][2] << endl;
        }
        cout << endl;
    } */

    int best = 1e18;
    for (int i = 0; i <= n; i++) {
        best = min(best, dp[i][K][0]);
        best = min(best, dp[i][K][1]);
        best = min(best, dp[i][K][2]);
    }

    int ans = sum - best;

    cout << ans << endl;

    return 0;
}