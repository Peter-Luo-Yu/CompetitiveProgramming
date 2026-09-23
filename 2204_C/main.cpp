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
        ll a, b, c, m; cin >> a >> b >> c >> m;

        // first just add however many times they appear
        ll A = (m / a) * 6, B = (m / b) * 6, C = (m / c) * 6;

        ll ab = a * b / gcd (a, b), ac = a * c / gcd (a, c), bc = b * c / gcd (b, c);
        ll abc = ab * c / gcd (ab, c);

        // every time a pair appears, you added 6, but you were supposed to add 3
        // so we subtract 3
        A -= (m / ab) * 3;
        A -= (m / ac) * 3;

        B -= (m / ab) * 3;
        B -= (m / bc) * 3;

        C -= (m / ac) * 3;
        C -= (m / bc) * 3;

        // now each time a triple appears, you first added 6 and then subtracted 3 twice, net = 0.
        // now we add 2 back.
        A += (m / abc) * 2;
        B += (m / abc) * 2;
        C += (m / abc) * 2;

        print(A, B, C);
        cout << A << " " << B << " " << C << endl;
    }


    
    return 0;
}