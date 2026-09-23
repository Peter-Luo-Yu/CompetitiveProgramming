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


ll power (ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = res * a;
        }
        a = a * a;
        b /= 2;
    }
    return res;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll N = 2 * 1e5 + 5;
    vector<ll> factor (N);
    for (ll i = 2; i < N; i++) {
        if (factor[i] == 0) {
            for (ll j = i; j < N; j+=i) {
                factor[j] = i;
            }
        }
    }

    //print(factor);

    ll t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        vector<ll> arr (n);
        for (ll i = 0; i < n; i++) cin >> arr[i];

        print(arr);

        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            if (arr[i] <= k) continue;
            ll val = arr[i];

            /*
            if (factor[arr[i]] == arr[i]) {
                ans += 1;
                continue;
            } */
 
            map<ll, ll> pf;
            while (val > 1) {
                ll fac = factor[val];
                ll exp = 0;
                while (val % fac == 0) {
                    val /= fac;
                    exp++;
                }
                pf[fac] = exp;
            }

            map<ll, ll> orig = pf;

            print(pf);

            // greedily take off exponents

           

            ll cur = 1;

            while (true) {
                auto it = pf.begin();

                if (it == pf.end()) {
                    break;
                }

                cur *= it -> first;
                if (cur > k) {
                    break;
                }

                print(it -> first);
                
                pf[it -> first]--;
                if (pf[it ->first] == 0) {
                    pf.erase(it -> first);
                }
            }

            print(pf);

            for (auto p : pf) {
                if (p.second == 1 && factor[p.first] == p.first) {
                    ans += 1;
                }
                else {
                    ans += power(p.first, p.second) - 1;
                    print(power(p.first, p.second) - 1);
                }
            }


        }

        print(ans);
        cout << ans << endl;
        space;

    }

    
    return 0;
}