"""Author: Peter Yu
   It is ok to share my code anonymously for educational purposes"""
   
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

ll MOD = 1e9 + 7;

ll power (ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    // the number of inversions is simply the number of zeros to the right of each one
    string s; cin >> s;

    vector<char> arr;
    for (auto c : s) {
        arr.push_back(c);
    }

    // Ignore the ?'s - compute number of inversions, they contribute 2 ^ q times, because there are 2 ^ q sequences
    ll q = 0;
    vector<char> fixed;
    for (auto c : s) {
        if (c != '?') {
            fixed.push_back(c);
        }
        else {
            q++;
        }
    }

    print(q);
    
    // use prefix sum to get O(n)

    vector<int> fixpref (fixed.size() + 1);
    for (int i = 0; i < fixed.size(); i++) {
        if (fixed[i] == '0') {
            fixpref[i + 1] = fixpref[i] + 1;
        }
        else {
            fixpref[i + 1] = fixpref[i];
        }
    }

    print(fixed); print(fixpref);
    
    ll fixedInv = 0;
    for (int i = 0; i < fixed.size(); i++) {
        if (fixed[i] == '1') {
            fixedInv += (fixpref[fixed.size()] - fixpref[i]);
            fixedInv %= MOD;
        }
    }

    fixedInv = (power(2, q) * fixedInv) % MOD;

    print(fixedInv);


    // Now compute the number of inversions with ? to a fixed val
    // find the number of 0's on right and 1's on left, each contributes 2 ^ q - 1,
    // because we are fixing the current question mark

    vector<int> pref0 (arr.size() + 1), pref1 (arr.size() + 1);
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == '0') {
            pref0[i + 1] = pref0[i] + 1;
        } else {
            pref0[i + 1] = pref0[i];
        }
        if (arr[i] == '1') {
            pref1[i + 1] = pref1[i] + 1;
        } else {
            pref1[i + 1] = pref1[i];
        }
    }

    print(arr); print(pref0); print(pref1);

    ll single = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == '?') {
            ll r0 = pref0[arr.size()] - pref0[i];
            ll l1 = pref1[i] - pref1[0];

            single += (power(2, q - 1) * r0) % MOD;
            single %= MOD;
            
            single += (power(2, q - 1) * l1) % MOD;
            single %= MOD;

            print(r0, l1);
        }
    }

    print(single);


    // finally, we just find the # of inv only involving ?
    // the trick was to list out a few terms for q = 1, 2, 3, 4
    // to realize that a 1 in the second place contributes 1 * 2 ^ q - 2
    // then a 1 in the thrid place contributes 2 * 2 ^ q - 2...

    ll question = 0;
    for (int i = 1; i < q; i++) {
        question += (i * power(2, q - 2)) % MOD;
    }
    
    print(question);

    ll ans = (fixedInv + single + question) % MOD;

    cout << ans << endl;
    
    return 0;
}