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

    // goal: find the earliest index of appearance of any triple

    int n, k; cin >> n >> k;
    vector<pair<int, int>> cards (n);

    for (int i = 0; i < n; i++) {
        cin >> cards[i].first >> cards[i].second;
    }

    map<pair<int, int>, bool> vis;
    for (int i = 0; i < k; i++) {
        vis[{cards[i].first, cards[i].second}] = true;
    }

    bool nomoves = false;
    for (int a = 1; a <= 4; a++) {
        for (int b = 1; b <= 11; b++) {
            if (vis[{a, b}] && vis[{a, b + 1}] && vis[{a, b + 2}]) {
                nomoves = true;
            }
        }
    }

    if (nomoves) {
        cout << 1 << endl;
        return 0;
    }
    

    print(vis);

    int ans = 1e9;
    for (int i = k; i < n; i++) {
        vis[{cards[i].first, cards[i].second}] = true;

        bool done = false;
        for (int a = 1; a <= 4; a++) {
            for (int b = 1; b <= 11; b++) {
                if (vis[{a, b}] && vis[{a, b + 1}] && vis[{a, b + 2}]) {
                    done = true;
                    break;
                }
            }
            if (done) {
                break;
            }
        }

        if (done) {
            ans = min (ans, i);
        }

        

        print(vis);
    }

    ans -= (k - 1);

    if (ans > 1e7) {
        cout << "Neibb" << endl;
    }
    else {
        cout << ans << endl;
    }

    
    return 0;
}