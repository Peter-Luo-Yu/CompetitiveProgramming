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
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        map<int, int> trap;
        for (int i = 0; i < n; i++) {
            int r, d; cin >> r >> d;

            if (trap.count(r) == 0) {
                trap[r] = d;
            }
            else {
                trap[r] = min(trap[r], d);
            }
        }

        print(trap);


        int ans = 0;
        for (int k = 1; k < 1000; k++) {

            // arrival time is r - 1
            // depart time is r - 1 + 2 (k - r) = 2k - r - 1

            bool failed = false;

            for (auto t : trap) {
                int r = t.first;
                int d = t.second;

                int lock = r - 1 + d;

                int arrive = r - 1;
                int depart = 2 * k - r - 1;

                if (depart >= lock) {
                    failed = true;
                }
            }

            if (!failed) {
                ans = max (ans, k);
            }
        }

        cout << ans << endl;

        space;
    }


    return 0;
}