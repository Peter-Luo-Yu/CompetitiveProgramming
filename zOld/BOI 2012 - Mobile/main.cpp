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
    
    int n; ld len; cin >> n >> len;

    vector<pair<ld, ld>> pts (n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].first >> pts[i].second;
    }

    ld l = 0, r = 5e9;
    ld ans = -1;
    while (r - l >= 1e-5) {
        ld mid = (l + r) / (ld) 2; // is the radius

        print(mid);
        
        // WE just have to SIMULATE, but first sort the points by x cordinate (already done)
        // and union them together to find the entire high way is covered 

        ld cur = 0;

        for (int i = 0; i < n; i++) {
            ld x = pts[i].first, y = pts[i].second;

            if (abs(y) > mid) continue;

            ld dx = sqrt(mid * mid - y * y);

            ld l = x - dx, r = x + dx;

            if (l <= cur) {
                cur = max (cur, r);
            }
        }

        if (cur >= len) {
            ans = mid;
            r = mid;
        }
        else {
            l = mid;
        }
    }

    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}