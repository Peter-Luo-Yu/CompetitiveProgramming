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


#define ll long long
#define ld long double
#define endl "\n"

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    vector<int> fib(11);
    fib[1] = 1;
    fib[2] = 2;
    for (int i = 3; i <= 10; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    print(fib);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;

        vector<int> ans (m);
        for (int i = 0; i < m; i++) {
            int x, y, z; cin >> x >> y >> z;

            int minWidth = fib[n];
            int minHeight = fib[n] + fib[n - 1];

            if (x >= minWidth && y >= minWidth && z >= minHeight) {
                ans[i] = 1;
            }

            // edge case you place two boxes directly on the floor

            minHeight = fib[n];

            int maxWidth = fib[n] + fib[n - 1]; // only for one side
            if (x >= minWidth && y >= minWidth && z >= minHeight && max(x, y) >= maxWidth) {
                ans[i] = 1;
            }
        }

        for (auto a : ans) {
            cout << a;
        }
        cout << endl;
    }


    return 0;
}