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
        ll s, q; cin >> s >> q;

        vector<ll> factors;
        for (ll i = 1; i * i <= s; i++) {
            if (s % i == 0) {
                factors.push_back(i);

                ll other = s / i;
                if (other != i) {
                    factors.push_back(other);
                }
            }            
        }

        sort (factors.begin(), factors.end());
        print(factors);

        vector<ll> pref (factors.size() + 1);
        ll sumX = 0;
        int idx = factors.size() - 1;
        for (int i = 0; i < factors.size(); i++) {
            ll x = factors[i] - sumX;
            ll y = factors[idx];

            idx--;
            sumX += x;

            //print(x, y);

            pref[i + 1] = pref[i] + (x * y);
        }
        
        print(pref);

        vector<ll> rev = factors;
        reverse(rev.begin(), rev.end());
    
        while (q--) {
            ll X, Y; cin >> X >> Y;

            int idx1 = lower_bound(factors.begin(), factors.end(), X) - factors.begin();
            int idx2 = lower_bound(factors.begin(), factors.end(), Y) - factors.begin();

            ll right = 0;
            if (X != factors[idx1]) {
                idx1--;
                right = (X - factors[idx1]) * rev[idx1 + 1];
            }

            ll left = 0;
            print(idx2);
            if (Y != factors[idx2]) {
                idx2--;
            }
            idx2 = factors.size() - 1 - idx2 - 1;
            if (idx2 >= 0) {
                left = factors[idx2] * Y;
            }
            
            // right is idx1, left is idx2
            ll ans = 0;
            if (idx2 > idx1) {
                ans = X * Y;
            }
            else {
                ans = pref[idx1 + 1] - pref[idx2 + 1] + left + right;
            }

            
            print(idx1, idx2, right, left, ans);

            cout << ans << endl;
        }


    }


    return 0;
}