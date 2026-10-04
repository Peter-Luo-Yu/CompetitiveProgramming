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
        int a, b; cin >> a >> b;

        int xk, yk; cin >> xk >> yk;
        int xq, yq; cin >> xq >> yq;

        vector<int> dx = {-1, 1, 1, -1};
        vector<int> dy = {1, -1, 1, -1};

        set<pair<int, int>> ans;

        int x = -1, y = -1;
        for (int i = 0; i < 4; i++) {
            x = xk;
            y = yk;

            x += dx[i] * a;
            y += dy[i] * b;

            print(x, y);

            for (int j = 0; j < 4; j++) {
                int x2 = x + dx[j] * a;
                int y2 = y + dy[j] * b;
                if (x2 == xq && y2 == yq) {
                    ans.insert({x, y});
                }
                print(x2, y2);
            }
            for (int j = 0; j < 4; j++) {
                int x2 = x + dx[j] * b;
                int y2 = y + dy[j] * a;
                if (x2 == xq && y2 == yq) {
                    ans.insert({x, y});
                }
                print(x2, y2);
            }
        }

        for (int i = 0; i < 4; i++) {
            x = xk;
            y = yk;

            x += dx[i] * b;
            y += dy[i] * a;

            for (int j = 0; j < 4; j++) {
                int x2 = x + dx[j] * a;
                int y2 = y + dy[j] * b;
                if (x2 == xq && y2 == yq) {
                    ans.insert({x, y});
                }
            }
            for (int j = 0; j < 4; j++) {
                int x2 = x + dx[j] * b;
                int y2 = y + dy[j] * a;
                if (x2 == xq && y2 == yq) {
                    ans.insert({x, y});
                }
            }
        }

        cout << ans.size() << endl;

        space;
    }


    return 0;
}