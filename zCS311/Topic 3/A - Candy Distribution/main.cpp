"""Author: Peter Yu
   It is ok to share my code anonymously for educational purposes"""

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

// from cp algo

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // need k * x + 1, only buy in batches of c
    // so k * x + 1 = c * y
    // take mod k
    // cy = 1 (mod k)
    // the answer to the problem is to find y = c^-1

    int t; cin >> t;
    while (t--) {
        ll k, c; cin >> k >> c;

        ll x, y;
        ll g = gcd (c, k, x, y);
        
        if (g != 1) {
            cout << "IMPOSSIBLE" << endl;
        }
        else {
            x = (x % k + k) % k; 

            // edge case if x = 0, then you can't buy nothing
            if (x == 0) {
                x += k;
            }

            // then c = 1 is a fat edge case, because mod 1 always = 0
            if (c == 1) {
                if (k + 1 > 1e9) {
                    cout << "IMPOSSIBLE" << endl;
                }
                else {
                    cout << k + 1 << endl;
                }
            }
            else {
                if (x > 1e9) {
                    cout << "IMPOSSIBLE" << endl;
                }
                else {
                    cout << x << endl;
                }
            }
        }
        



    }
    
    return 0;
}