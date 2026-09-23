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
        string s; cin >> s;


        // a is start on 1, b is start on 0
        bool alt1a = false, alt1b = false, onlyq1 = true; 
        bool alt2a = false, alt2b = false, onlyq2 = true;

        int prev1 = 0, prev2 = 1;
        for (int i = 0; i < n; i += 2) {
            if (s[i] == '?') {
                
            }
            else if (s[i] == '0') {
                if (prev1 == 0) {
                    alt1a = true;
                }
                if (prev2 == 0) {
                    alt1b = true;
                }
            }
            else {
                if (prev1 == 1) {
                    alt1a = true;
                }
                if (prev2 == 1) {
                    alt1b = true;
                }
            }

            if (prev1 == 0) {
                prev1 = 1;
            } else {
                prev1 = 0;
            }

            if (prev2 == 0) {
                prev2 = 1;
            } else {
                prev2 = 0;
            }

            if (s[i] != '?') {
                onlyq1 = false;
            }
        }

        prev1 = 0; prev2 = 1;
        for (int i = 1; i < n; i += 2) {
            if (s[i] == '?') {
                
            }
            else if (s[i] == '0') {
                if (prev1 == 0) {
                    alt2a = true;
                }
                if (prev2 == 0) {
                    alt2b = true;
                }
            }
            else {
                if (prev1 == 1) {
                    alt2a = true;
                }
                if (prev2 == 1) {
                    alt2b = true;
                }
            }

            if (prev1 == 0) {
                prev1 = 1;
            } else {
                prev1 = 0;
            }

            if (prev2 == 0) {
                prev2 = 1;
            } else {
                prev2 = 0;
            }

            if (s[i] != '?') {
                onlyq2 = false;
            }
        }

        print(alt1a, alt1b, alt2a, alt2b);

        if ((alt1a && alt1b) || (alt2a && alt2b)) {
            cout << 0 << endl;
            //cout << "---------" << endl;
            continue;
        }
        
        int ans = 1;
        if (onlyq1) ans *= 2;
        if (onlyq2) ans *= 2;
        cout << ans << endl;



        //cout << "---------" << endl;
    }


    return 0;
}