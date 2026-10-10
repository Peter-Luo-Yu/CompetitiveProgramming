<<<<<<< HEAD
//#define LOCAL
=======
#define LOCAL
>>>>>>> 27437abf1c7a21494695ab2a2d2b6fc861744816

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


<<<<<<< HEAD
struct SegmentTree {
    ll n;
    vector<ll> lazy, tree;
 
    void init(ll x) {
        n = x;
        tree = lazy = vector<ll> (4 * n);
    }
 
    void apply(ll v, ll len, ll val) {
        tree[v] += len * val;
        lazy[v] += val;
    }
 
    void push(ll v, ll l, ll r) {
        ll mid = (l + r) / 2;
        apply(2 * v, mid - l + 1, lazy[v]);
        apply(2 * v + 1, r - mid, lazy[v]);
        lazy[v] = 0;
    }
 
    void add(ll v, ll l, ll r, ll ql, ll qr, ll val) {
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
 
    void add(ll ql, ll qr, ll val) {
        add(1, 0, n - 1, ql, qr, val);
    }
 
    ll sum(ll v, ll l, ll r, ll ql, ll qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) {
            return tree[v];
        }
        else {
            push(v, l, r);
            ll mid = (l + r) / 2;
            return sum(2 * v, l, mid, ql, qr) + sum(2 * v + 1, mid + 1, r, ql, qr);
        }
    }
 
    ll sum(ll ql, ll qr) {
        return sum(1, 0, n - 1, ql, qr);
    }
 
    ll findk (ll k) { // 0 indexed
        ll v = 1, l = 0, r = n - 1;
 
        while (l < r) {
            push(v, l, r);
            ll mid = (l + r) / 2;
            if (tree[2 * v] > k) { // left side has more than k active
                v = 2 * v;
                r = mid;
            }
            else {
                k -= tree[2 * v];
                v = 2 * v + 1;
                l = mid + 1;
            }
        }
 
        return l;
    }
 
};


=======
>>>>>>> 27437abf1c7a21494695ab2a2d2b6fc861744816
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

<<<<<<< HEAD
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // I will implement everything 1 indexed

    // You might initially think to do some fancy range update,
    // but the issue is, you don't know which elements are above the 1,
    // in a range.

    // Instead we have to observe that once a 1 or a N is shoved into the correct
    // position, it doesn't actually affect the relative ordering of the rest of the elements
    // which means the segment tree is stores 
    // which position -> which element is "active"
    // so you can easily query for how many swaps you need to do
    // to get somebody to the edge

    int n; cin >> n;
    vector<int> arr (n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    SegmentTree segtree;
    segtree.init(n + 1);

    // initially everybody is active
    segtree.add(1, n, 1);

    print(arr);
    print(pos);

    int l = 1, r = n;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            int target = l;
            int cur = pos[l];

            print(cur, target);
            
            // it's not easy to see, but query always goes until the end of
            // original array
            cout << segtree.sum(0, cur - 1) << endl;

            // now we have to make l inactive
            segtree.add(pos[l], pos[l], -1);
            l++;
        }
        else {
            int target = r;
            int cur = pos[r];

            print(target, cur);

            cout << segtree.sum(cur + 1, n) << endl;

            // now we have to make l inactive
            segtree.add(pos[r], pos[r], -1);
            r--;
        }
    }

    space;
    
=======
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

>>>>>>> 27437abf1c7a21494695ab2a2d2b6fc861744816
    


    return 0;
}