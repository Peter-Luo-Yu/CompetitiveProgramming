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

        int score = -1, pos = -1;
        for (int i = 1; i < n - 1; i++) {
            int cur = 0;
            if (s[i + 1] == s[i - 1] && s[i] != s[i - 1]) {
                cur = 2;
            }
            else if (s[i + 1] != s[i - 1] && s[i] != s[i + 1] && s[i] != s[i - 1]) {
                cur = 1;
            }


            if (cur > score) {
                score = cur;
                pos = i;
            }
        }

        string s2 = "";
        for (int i = 0; i < n; i++) {
            if (i != pos) {
                s2 += s[i];
            }
        }

        
        //cout << s2 << endl;

        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            if (s2[i] != s2[i + 1]) {
                ans++;
            }
        }

        cout << ans + 1 << endl;

    }


    return 0;
}