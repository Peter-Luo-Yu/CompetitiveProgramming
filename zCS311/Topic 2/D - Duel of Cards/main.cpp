"""Author: Peter Yu
   It is ok to share my code anonymously for educational purposes"""
   
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

    // first I need to determine each player's hand

    int n; cin >> n;
    vector<int> a(n), b;

    vector<bool> vis (2*n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        vis[a[i]] = true;
    }

    for (int i = 1; i <= 2 * n; i++) {
        if (!vis[i]) {
            b.push_back(i);
        }
    }
    
    sort (a.begin(), a.end());
    sort (b.begin(), b.end());

    print(a);
    print(b);

    // I try to maximize Awins by pairing Alice's card with Bob's smallest cards

    int Awins = 0;
    int bidx = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < b[bidx]) {
            continue;
        }
        else { // a > b
            Awins++;
            bidx++;
        }
    }

    print(Awins);

    // Similarly maximize Bob's wins to minimize Alice's wins

    int Bwins = 0;
    int aidx = 0;

    for (int i = 0; i < n; i++) {
        if (b[i] < a[aidx]) {
            continue;
        }
        else {
            Bwins++;
            aidx++;
        }
    }

    print(Bwins);

    cout << n - Bwins << " " << Awins << endl;


    return 0;
}