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

ll calc (ll l, ll r, ll fac) {
    while (l % fac != 0) l++;
    while (r % fac != 0) r--;

    if (r < l) return 0;
    return (r - l) / fac + 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t; cin >> t;
    while (t--) {
        ll l, r; cin >> l >> r;

        ll diff = r - l;

        ll bad = 0;

        bad += calc(l, r, 2);
        bad += calc(l, r, 3);
        bad += calc(l, r, 5);
        bad += calc(l, r, 7);

        bad -= calc(l, r, 6);
        bad -= calc(l, r, 10);
        bad -= calc(l, r, 14);
        bad -= calc(l, r, 15);
        bad -= calc(l, r, 21);
        bad -= calc(l, r, 35);

        bad += calc(l, r, 30);
        bad += calc(l, r, 42);
        bad += calc(l, r, 70);
        bad += calc(l, r, 105);

        bad -= calc(l, r, 210);  

        print(bad);

        ll good = r - l + 1 - bad;

        cout << good << endl;

    }


    return 0;
}