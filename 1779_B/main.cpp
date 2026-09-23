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
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        // n = 5
        // -1 2 -1 2 -1, sum = 1

        // try n = 7: -1 2 -1 2 -1 2 -1 = 6 - 4 = 2 BAD

        // n = 7
        // -2 3 -2 3 -2 3 -2 = 9 - 8 = 1

        // n = 9
        // -3 4 -3 4 -3 4 -3 4 -3 = 4 * 4 - 3 * 5 = 9

        if (n == 3) {
            cout << "NO" << endl;
            continue;
        }

        if (n % 2 == 1) {
            int m = 5;
            int val = 1;

            while (m < n) {
                m += 2;
                val++;
            }

            //cout << "val: " << val << endl;
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    cout << -val << " ";
                } else {
                    cout << val + 1 << " ";
                }
            }
            cout << endl;
        }
        
        else {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    cout << 1 << " ";
                }
                else {
                    cout << -1 << " ";
                }
            }
            cout << endl;
        }
        
        //cout << "----------" << endl;
    }


    return 0;
}