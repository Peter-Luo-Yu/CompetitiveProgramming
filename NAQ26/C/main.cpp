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

ll MOD = 998244353;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll N = 1e5 + 5;
    vector<ll> fact (N);
    fact[0] = 1;
    for (ll i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<pair<ll, ll>> arr (n);
        vector<pair<ll, pair<ll, ll>>> arr2 (n);
        for (ll i = 0; i < n; i++) {
            cin >> arr[i].first >> arr[i].second;
            if (arr[i].first < arr[i].second) {
                swap (arr[i].first, arr[i].second);
            }
            arr2[i] = {arr[i].first * arr[i].second, arr[i]};
        }

        sort (arr2.begin(), arr2.end());
        reverse(arr2.begin(), arr2.end());

        for (ll i = 0; i < n; i++) {
            arr[i] = arr2[i].second;
        }

        vector<pair<ll, ll>> order;
        ll idx = -1;
        for (ll i = 0; i < arr.size(); i++) {
            if (idx == -1) {
                order.push_back(arr[i]); 
                idx++;
                continue;
            }

            if (order[idx] == arr[i]) continue;
            order.push_back(arr[i]);
            idx++;
        }

        print(order);

        map<pair<ll, ll>, ll> mp;

        for (ll i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }

        print(mp);

        bool failed = false;

        ll ans = 1;
        ll x = -1, y = -1;

        for (ll i = 0; i < order.size(); i++) {
            ll cx = order[i].first, cy = order[i].second;

            print(x, y, cx, cy);

            if (x == -1) {
                x = cx; y = cy;

                if (mp[order[i]] > 1) {
                    ll dx = x - cx, dy = y - cy;
                    print(dx, dy);
                    ans *= (((dx + 1) * (dy + 1) % MOD) * fact[mp[order[i]]]) % MOD;
                    ans %= MOD;

                    print("x = -1", ans);
                }

                continue;
            }

            if (cx > x || cy > y) {
                failed = true;
                break;
            }      
            
            ll dx = x - cx, dy = y - cy;

            print(dx, dy);

            ll dans = 0;

            dans += (((dx + 1) * (dy + 1) % MOD) * fact[mp[order[i]]]) % MOD;
            dans %= MOD;
            

            ll remx = cx, remy = cy;

            // i try swapping

            if (cx != cy) {
                swap(cx, cy);

                if (cx <= x && cy <= y) {

                    dx = x - cx, dy = y - cy;

                    print(dx, dy);

                    dans += (((dx + 1) * (dy + 1) % MOD) * fact[mp[order[i]]]) % MOD;
                    dans %= MOD;
                }
            }

            print(dans);

            ans *= dans;
            ans %= MOD;

            x = remx; y = remy;

            print("end", x, y, ans);

        }

        if (failed) {
            cout << 0 << endl;
            space;
            continue;
        }

        if (order[0].first != order[0].second) {
            ans *= 2;
            ans %= MOD;
        }

        cout << ans << endl;
        
        print(ans);

        space;

    }


    return 0;
}