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
    
    ll t; cin >> t;
    while (t--) {
        ll n, x, y; cin >> n >> x >> y;

        vector<ll> arr (n);
        for (ll i = 0; i < n; i++) cin >> arr[i];

        vector<ll> remain(n);
        for (ll i = 0; i < n; i++) {
            remain[i] = arr[i] % x;
        }

        print(remain);

        ll idx1 = -1, idx2 = -1, most = -1;
        for (ll i = 0; i < n; i++) {
            if (remain[i] > most) {
                most = remain[i];
                idx1 = i;
                idx2 = i;
            }
            else if (remain[i] == most) {
                if (arr[i] < arr[idx1]) {
                    idx1 = i;
                }
                if (arr[i] > arr[idx2]) {
                    idx2 = i;
                }
            }
        }

        ll ansMin = 0, ansMax = 0;
        for (ll i = 0; i < n; i++) {
            if (i == idx1) {
                ansMin += arr[i];
            }
            else {
                ansMin += (arr[i] / x) * y;
            }
            if (i == idx2) {
                ansMax += arr[i];
            }
            else {
                ansMax += (arr[i] / x) * y;
            }
        }



        ll ans2 = 0;
        ll idx = -1; most = -1;
        for (ll i = 0; i < n; i++) {
            if (arr[i] > most) {
                most = arr[i];
                idx = i;
            }
        }

        for (ll i = 0; i < n; i++) {
            if (i == idx) {
                ans2 += arr[i];
            }
            else {
                ans2 += (arr[i] / x) * y;
            }
        }

        print(ansMin, ansMax, ans2);

        ans2 = max (ans2, max(ansMin, ansMax));
        cout << ans2 << endl;

    }


    return 0;
}