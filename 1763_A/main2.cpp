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
        ll n; cin >> n;
        vector<ll> arr (n);
        for (ll i = 0; i < n; i++) cin >> arr[i];

        print(arr);

        vector<bool> on(12);
        ll Max = 0;
        for (ll i = 0; i < n; i++) {
            //cout << arr[i] << endl;

            for (ll k = 0; k < 12; k++) {
                print(k, (1 << k), arr[i] & (1 << k));
                if ((arr[i] & (1 << k)) > 0) {
                    on[k] = true;
                }
            }
        }

        print(on);

        for (int k = 0; k < 12; k++) {
            if (on[k]) {
                Max += (1 << k);
            }
        }

        //cout << "Max: " << Max << endl;


        // try to get off
        vector<bool> off(12, true);
        ll Min = 0;
        for (ll i = 0; i < n; i++) {
            //cout << arr[i] << endl;

            for (ll k = 0; k < 12; k++) {
                //print(k, (1 << k), arr[i] & (1 << k));
                if ((arr[i] & (1 << k)) == 0) {
                    off[k] = false;
                }
            }
        }
        for (int k = 0; k < 12; k++) {
            if (off[k]) {
                Min += (1 << k);
            }
        }

        //cout << "Min: " << Min << endl;

        ll ans = Max - Min;
        cout << ans << endl;
    }


    
    return 0;
}