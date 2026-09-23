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
        vector<ll> arr (2 * n);

        map<ll, vector<ll>> mp; // left and right locations of val
        for (ll i = 0; i < 2 * n; i++) {
            cin >> arr[i]; arr[i]--;
            mp[arr[i]].push_back(i);
        }

        print(arr);
        print(mp);


        vector<ll> dp (2 * n);
        dp[0] = 1;

        for (int i = 1; i < 2 * n; i++) {
            ll l = mp[arr[i]][0], r = mp[arr[i]][1];
            ll score = (r - l + 1) * (r - l + 1);

            
            if (i == r) {
                // take the current interval from l to r and add dp[l - 1]
                if (l - 1 < 0) {
                    print("c1");
                    dp[i] = max(score, dp[i]);
                } else {
                    print("c2");
                    dp[i] = max(score + dp[l - 1], dp[i]);
                }


                // or choose not to -> covered in the i == l case
            }
            
            dp[i] = max(dp[i - 1] + 1, dp[i]);
            
        }

        print(dp);
        
        cout << dp[2 * n - 1] << endl;


        space;

    }


    return 0;
}