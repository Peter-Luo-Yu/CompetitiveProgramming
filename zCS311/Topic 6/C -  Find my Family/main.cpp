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

struct SegmentTree {
    ll n;
    vector<ll> lazy, tree;
 
    void init(ll x) {
        n = x;
        tree = lazy = vector<ll> (4 * n);
    }
 
    void apply(ll v, ll len, ll val) { // changed for max seg tree
        tree[v] += val;
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
            tree[v] = max(tree[2 * v] , tree[2 * v + 1]); // here as well
        }
    }
 
    void add(ll ql, ll qr, ll val) {
        add(1, 0, n - 1, ql, qr, val);
    }
 
    // sum actually returns the max now :)

    ll sum(ll v, ll l, ll r, ll ql, ll qr) {
        if (qr < l || ql > r) return -1e18;
        if (ql <= l && r <= qr) {
            return tree[v];
        }
        else {
            push(v, l, r);
            ll mid = (l + r) / 2;
            return max(sum(2 * v, l, mid, ql, qr), sum(2 * v + 1, mid + 1, r, ql, qr));
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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    int cur = 1;
    vector<int> finalans;
    while (t--) {
        int n; cin >> n;
        vector<int> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        // left - visited on the left
        // right - visited on the right

        SegmentTree right;
        right.init(n + 1);

        // left gets the 1st element, rest go in right

        set<ll> left;
        left.insert(arr[0]);
        for (int i = 1; i < n; i++) {
            right.add(i, i, arr[i]);
        }

        ll ans = 0;

        // I first move the cur element from right to left
        for (int i = 1; i < n - 1; i++) {
            right.add(i, i, -arr[i]);
            
            // i < j < k
            // need ai > aj, and ak > ai
            
            ll alice = 1e18;
            auto it = left.lower_bound(arr[i]);
            if (it != left.end()) alice = *it;

            ll bob = right.sum(i + 1, n);
            

            print(alice, bob);


            left.insert(arr[i]);

            if (alice != 1e18 && bob != -1e18 && alice < bob) {
                ans = 1;
            }
        }

        if (ans) {
            finalans.push_back(cur);
        }
        
        cur++;

        space;
    }

    cout << finalans.size() << endl;
    for (auto a : finalans) {
        cout << a << endl;
    }

}