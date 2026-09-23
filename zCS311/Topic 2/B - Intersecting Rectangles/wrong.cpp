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

    int n; cin >> n;
    vector<pair<pair<int, int>, pair<int, int>>> X(n); // x1, x2, y
    vector<pair<int, pair<int, int>>> Y(2 * n); // x, y1, y2
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        X[i] = {{x1, x2}, {y1, y2}};

        Y[2 * i] = {x1, {y1, y2}};
        Y[2 * i + 1] = {x2, {y1, y2}};
    }

    sort (X.begin(), X.end());
    sort (Y.begin(), Y.end());

    print(X);
    print(Y);

    int cutoff = -2e9; // left most point of x interval
    int yidx = 0;

    bool found = false;

    for (int i = 0; i < n; i++) {
        int l = X[i].first.first;
        int r = X[i].first.second;

        int y1 = X[i].second.first;
        int y2 = X[i].second.second;

        cutoff = max (cutoff, l);

        while (yidx < 2 * n && Y[yidx].first < cutoff) {
            yidx++;
        }

        
        while (yidx < 2 * n && Y[yidx].first < r) {
            int lb = Y[yidx].second.first;
            int ub = Y[yidx].second.second;
            
            if (((lb < y1) && (y1 < ub)) || ((lb < y2) && (y2 < ub))) {
                print(lb, ub, y1, y2);
                found = true;
            }

            yidx++;
        }
    }

    if (!found) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
    
    return 0;
}