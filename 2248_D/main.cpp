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
        int n, q; cin >> n >> q;
        string s1, s2; cin >> s1 >> s2;

        vector<int> pref01 (n + 1), pref10 (n + 1), prefSame (n + 1);
        for (int i = 0; i < n; i++) {
            pref01[i + 1] = pref01[i] + (s1[i] == '0' && s2[i] == '1');
            pref10[i + 1] = pref10[i] + (s1[i] == '1' && s2[i] == '0');
            prefSame[i + 1] = prefSame[i] + (s1[i] == s2[i]);
        }

        while (q--) {
            int l, r; cin >> l >> r;

            int num01 = pref01[r] - pref01[l - 1];
            int num10 = pref10[r] - pref10[l - 1];

            int same = prefSame[r] - prefSame[l - 1];

            if (abs(num01 - num10) <= same) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }

        //space;

    }
    return 0;
}