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

    int N = 55;
    vector<vector<ll>> pascal(N);
    pascal[0] = {1};
    pascal[1] = {1, 1};

    for (int i = 2; i < N; i++) {
        vector<ll> row (i + 1); 
        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || j == i) {
                row[j] = 1;
            }
            else {
                row[j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
        pascal[i] = row;
    }

    //print(pascal);

    int t; cin >> t;
    while (t--) {
        ll n, v1, v2; ld w; cin >> n >> v1 >> v2 >> w;

        ll left = n - v1 - v2;

        ll winamt = n / 2 + 1;
        ll need = winamt - v1; 
        
        print(left, winamt, need);

        if (need > left) { // already lost 
            cout << "RECOUNT!" << endl;
            space;
            continue;
        }

        ld num = 0;
        ld denom = (1LL << left);

        for (int i = need; i <= left; i++) {
            // want left choose need, need + 1, need + 2...

            print(pascal[left][i]);
            num += pascal[left][i];
        }

        print(num, denom);

        ld prob = (ld) 100 * (num / denom);

        print(prob);

        if (prob > w) {
            cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
        }
        else {
            cout << "PATIENCE, EVERYONE!" << endl;
        }

        space;


    }


    return 0;
}