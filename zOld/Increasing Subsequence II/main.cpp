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

struct SegmentationTree {
    ll n;
    vector<ll> tree, lazy;

    void init(ll x) {
        n = x;
        tree = lazy = vector<ll> (4 * n);
    }

    void apply(ll v, ll len, ll val) { // we are doing point updates anyhow (len = 1)
        tree[v] += val * len; tree[v] %= MOD;
        lazy[v] += val; lazy[v] %= MOD;
    }

    void push(ll v, ll l, ll r) {
        ll mid = (l + r) / 2;
        apply(2 * v, mid - l + 1, lazy[v]);
        apply(2 * v + 1, r - mid, lazy[v]);
        lazy[v] = 0;
    }

    void add(ll v, ll l, ll r, ll ql, ll qr, ll val) {
        if (r < ql || l > qr) return;
        if (ql <= l && r <= qr) {
            apply(v, r - l + 1, val);
        }
        else {
            push(v, l, r);
            ll mid = (l + r) / 2;
            add (2 * v, l, mid, ql, qr, val);
            add (2 * v + 1, mid + 1, r, ql, qr, val);
            tree[v] = (tree[2 * v] + tree[2 * v + 1]) % MOD;
        }
    }
    void add(ll ql, ll qr, ll val) {
        add(1, 0, n - 1, ql, qr, val);
    }

    ll sum(ll v, ll l, ll r, ll ql, ll qr) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) {
            return tree[v];
        }
        else {
            push(v, l, r);
            ll mid = (l + r) / 2;
            return (sum(2 * v, l, mid, ql, qr) + sum(2 * v + 1, mid + 1, r, ql, qr)) % MOD;
        }
    }
    ll sum(ll ql, ll qr) {
        return sum(1, 0, n - 1, ql, qr);
    }

};


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<int> arr (n);
    for (int i = 0; i < n; i++) cin >> arr[i];
        
    vector<int> sorted = arr;
    sort (sorted.begin(), sorted.end());

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[sorted[i]] = i;
    }

    // coordinated compressed and 0 - indexed for tree
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = mp[arr[i]];
    }
    print(a);
    

    SegmentationTree segtree;
    segtree.init(n);

    print(segtree.tree);

    ll ans = 0;
    for (int i = 0; i < n; i++) {

        // find sum of dps from 0 -> val - 1
        ll sum = 0;
        if (a[i] > 0) {
            sum = segtree.sum(0, a[i] - 1);
        }

        ll dp = (sum + 1) % MOD;
        ans = (ans + dp) % MOD;

        segtree.add(a[i], a[i], dp);
    }

    cout << ans << endl;
    
    return 0;
}