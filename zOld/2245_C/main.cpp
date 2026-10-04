#define LOCAL

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define print(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define print(...) 6
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
#define space cout << "--------" << endl;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        if (k == n) {
            cout << "YES" << endl;
            for (int i = 1; i <= n - 1; i++) {
                cout << i << " ";
            }
            cout << 0 << endl;
        }
        else if ((1 <= (n ^ k)) && ((n ^ k) <= n - 1)) {
            int x = n ^ k;
            cout << "YES" << endl;
            for (int i = 1; i <= n - 1; i++) {
                if (i == x) continue;
                cout << i << " ";
            }
            cout << 0 << " " << x << endl;
        }
        else {
            int X = -1, Y = -1;
            // brute forcing x from 1 to n - 1
            for (int x = 1; x <= n - 1; x++) {
                int y = n ^ k ^ x;

                if (1 <= y && y < x) { // found
                    X = x;
                    Y = y;
                    break;
                }
            }

            if (X == -1) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
                for (int i = 1; i <= n - 1; i++) {
                    if (i == X || i == Y) continue;
                    cout << i << " ";
                }
                cout << 0 << " " << Y << " " << X << endl;
            }
        }

        //space;
    }


    
    return 0;
}