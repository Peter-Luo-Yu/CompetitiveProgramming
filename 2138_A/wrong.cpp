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



// state[a][b] = {step, 1 = doubled a to go back, 2 = double b to go back}

int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif    
    
    int t; cin >> t;
    while (t--) {

        int k, x; cin >> k >> x;
        map<pair<int, int>, pair<int, int>> dp;

        queue<pair<int, int>> q;

        dp[{1 << k, 1 << k}] = {0, -1};
        q.push({(1 << k), (1 << k)});

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();

            //print(cur);

            if (cur.first % 2 == 0) {
                if (dp.count({cur.first / 2, cur.second + cur.first / 2}) == 0) {
                    dp[{cur.first / 2, cur.second + cur.first / 2}] = {dp[cur].first + 1, 1};
                    q.push({cur.first / 2, cur.second + cur.first / 2});
                }
               
            }
            if (cur.second % 2 == 0) {
                if (dp.count({cur.first + cur.second / 2, cur.second / 2}) == 0) {
                    dp[{cur.first + cur.second / 2, cur.second / 2}] = {dp[cur].first + 1, 2};
                    q.push({cur.first + cur.second / 2, cur.second / 2});
                }
            }

        }

        print(dp.size());
        print(dp);

        
        
        cout << dp[{x, (1 << (k + 1)) - x}].first << endl;
        pair<int, int> cur = {x, (1 << (k + 1)) - x};
        
        vector<int> ans;
        while (dp[cur].second != -1) {
            print(cur, dp[cur]);

            ans.push_back(dp[cur].second);

            if (dp[cur].second == 1) {
                pair<int, int> next = {cur.first * 2, cur.second - cur.first};
                cur = next;
            }
            else {
                pair<int, int> next = {cur.first - cur.second, cur.second * 2};
                cur = next;
            }
        }

        print(ans);

        reverse(ans.begin(), ans.end());
        for (auto a : ans) {
            cout << a << " ";
        }
        cout << endl;

        space;

    }


    return 0;
}