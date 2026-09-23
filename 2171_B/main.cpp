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

ll calc(vector<ll> arr) {
    ll res = 0;
    for (int i = 1; i < arr.size(); i++) {
        res += (arr[i] - arr[i - 1]);
    }
    return abs(res);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<ll> arr (n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        if (arr[0] == -1 && arr[n - 1] == -1) {
            for (auto &a : arr) {
                if (a == -1) {
                    a = 0;
                }
            }

            cout << 0 << endl;
            for (auto a : arr) cout << a << " ";
            cout << endl;
        }
        else if (arr[0] == -1 && arr[n - 1] != -1) {
            arr[0] = arr[n - 1];

            for (auto &a : arr) {
                if (a == -1) {
                    a = 0;
                }
            }
            cout << 0 << endl;
            for (auto a : arr) cout << a << " ";
            cout << endl;
        }
        else if (arr[0] != -1 && arr[n - 1] == -1) {
            arr[n - 1] = arr[0];

            for (auto &a : arr) {
                if (a == -1) {
                    a = 0;
                }
            }
            cout << 0 << endl;
            for (auto a : arr) cout << a << " ";
            cout << endl;
            
        }
        else {
            for (auto &a : arr) {
                if (a == -1) {
                    a = 0;
                }
            }
            cout << abs(arr[n - 1] - arr[0]) << endl;
            for (auto a : arr) cout << a << " ";
            cout << endl;
        }
    }



    return 0;
}