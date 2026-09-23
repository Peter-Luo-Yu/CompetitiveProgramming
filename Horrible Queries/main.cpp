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

struct SegmentTree {
    int n;
    vector<ll> tree, lazy;

    void init (int x) {
        n = x;
        tree = lazy = vector<ll> (4 * n);
    }

    void apply (ll v, ll len, ll val) {
        tree[v] += val * len;
        lazy[v] += val;
    }
    
    void push(ll v, ll l, ll r) {
        ll mid = (l + r) / 2;
        apply(2 * v, mid - l + 1, lazy[v]);
        apply(2 * v + 1, r - mid, lazy[v]);
        lazy[v] = 0;
    }

    // if segment inside query, you increment the cur tree node immediately
    // otherwise you push first and then later increment
    void add (ll v, ll l, ll r, ll ql, ll qr, ll val) {
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) {
            apply(v, r - l + 1, val);
        }
        else {
            push(v, l, r);
            ll mid = (l + r) / 2;
            add(2 * v, l, mid, ql, qr, val);
            add(2 * v + 1, mid + 1, r, ql, qr, val);

            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }

    void add (ll ql, ll qr, ll val) {
        add (1, 0, n - 1, ql, qr, val);
    }

    ll sum (ll v, ll l, ll r, ll ql, ll qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) {
            return tree[v];
        }
        push(v, l, r);
        ll mid = (l + r) / 2;
        return sum(2 * v, l, mid, ql, qr) + sum(2 * v + 1, mid + 1, r, ql, qr);
    }
    
    ll sum (ll ql, ll qr) {
        return sum (1, 0, n - 1, ql, qr);
    }

};



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        
        SegmentTree segtree;
        segtree.init(n);

        while (q--) {
            int t; cin >> t;

            if (t == 0) {
                int l, r, v; cin >> l >> r >> v; l--, r--;
                segtree.add(l, r, v);
            }
            else {
                int l, r; cin >> l >> r; l--, r--;
                cout << segtree.sum(l, r) << endl;
            }

        }


    }

    
    
    return 0;
}