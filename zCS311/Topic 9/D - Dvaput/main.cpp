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
#define lll  __int128_t
#define ld long double
#define endl "\n"

#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    ll n; cin >> n;
    string s; cin >> s;

    // hashing can be used to compare strings in O(1) -- with chance of failure

    lll A = 999999999999999989, B = 1e18 + 3;

    vector<lll> h(n);    // hash of each prefix
    h[0] = s[0] - 'a';
    for (int i = 1; i < n; i++) {
        h[i] = (h[i - 1] * A + (s[i] - 'a')) % B;
    }
    
    //print(h);

    vector<lll> p(n); // power
    p[0] = 1;
    for (int i = 1; i < n; i++) {
        p[i] = (p[i - 1] * A) % B;
    }

    //print(p);

    //print(A, B);


    // Binary Search the Answer
    ll l = 1, r = n;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        print(l, r, mid);

        unordered_map<ll, ll> freq; // freq of each hash value

        for (int i = 0; i <= n - mid; i++) {
            ll a = i, b = i + mid - 1;
            print(a, b);

            ll hash = -1e18;
            if (i == 0) {
                hash = h[b];
            }
            else {
                lll val = ((h[b] - (h[a - 1] * p[b - a + 1] % B)) + B) % B;
                hash = val;
            }

            print(hash);

            freq[hash]++;
        }

        print(freq);

        bool found = false;
        for (auto f : freq) {
            if (f.second >= 2) {
                found = true;
            }
        }

        print(found);

        if (found) {
            ans = max (ans, mid);
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }

    }

    cout << ans << endl;
    
    

    return 0;
}