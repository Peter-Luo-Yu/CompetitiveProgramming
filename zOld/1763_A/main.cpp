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


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> arr (n);
        for (ll i = 0; i < n; i++) cin >> arr[i];

        ll ans = -1;

        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                for (ll k = 0; k < 12; k++) {
                    vector<ll> temp = arr;

                    ll a = arr[i], b = arr[j];

                    bool bitA = false, bitB = false;
                    if ((a & (1LL << k)) > 0) {
                        bitA = true;
                    }
                    if ((b & (1LL << k)) > 0) {
                        bitB = true;
                    }

                    if (bitA && bitB) {

                    }
                    else if (bitA && !bitB) {
                        a -= (1 << k);
                        b += (1 << k);
                    } 
                    else if (!bitA && bitB) {
                        a += (1 << k);
                        b -= (1 << k);
                    }
                    else {

                    }

                    temp[i] = a;
                    temp[j] = b;


                    ll Max = (ll) *max_element(temp.begin(), temp.end());
                    ll Min = (ll) *min_element(temp.begin(), temp.end());

                    print(temp, Max - Min);

                    ans = max(ans, (ll) (Max - Min)); 
                }
            }
        }

        cout << ans << endl;

    }


    
    return 0;
}