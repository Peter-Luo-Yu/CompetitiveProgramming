/*Author: Peter Yu
   It is ok to share my code anonymously for educational purposes*/

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

    string s = "-";
    while (true) {
        getline(cin, s);
        
        if (s == "0") break;

        int n = stoi (s);

        vector<int> years (n), rain (n);
        
        for (int i = 0; i < n; i++) {
            getline(cin, s);

            int year = stoi(s.substr(0, s.find(" ")));
            int amt = stoi(s.substr(s.find(" ") + 1));

            print(year, amt);

            rain[i] = amt;
            years[i] = year;
           
        }

        print(years);
        print(rain);


        // rip a max segment tree

        SegmentTree segtree;
        segtree.init(n);

        for (int i = 0; i < n; i++) {
            segtree.add(i, i, rain[i]);
        }


        // process queries

        getline(cin, s);
        int q = stoi(s);

        while (q--) {
            getline(cin, s);

            int y1 = stoi(s.substr(0, s.find(" ")));
            int y2 = stoi(s.substr(s.find(" ") + 1));

         
            int idx1 = lower_bound(years.begin(), years.end(), y1) - years.begin();
            int idx2 = lower_bound(years.begin(), years.end(), y2) - years.begin();

            bool know1 = false, know2 = false;
            if (idx1 < n && years[idx1] == y1) know1 = true;
            if (idx2 < n && years[idx2] == y2) know2 = true;

            print(know1, know2);

            // we never care about the final year's value
            int r = idx2 - 1;

            // am I supposed to ignore the starting year as well?
            int l = idx1;
            if (know1) {
                l++;
            }

            print(y1, idx1, y2, idx2);


            ll maximum = -1;
            if (l <= r) {
                maximum = segtree.sum(l, r);
            }
            print(l, r, maximum);

            // just do what it tells you -- True if:
            // know everything and y1 >= y2 and y2 > all in between
            // finally rain[y2] <= rain[y1]
            
            // maybe occurs if you don't fail
            // you fail if max > rain[idx2]
            // but since rain[idx2] < rain[idx1], implies if max > rain[idx1] we also fail
            
            if (know1 && know2 && rain[idx1] < rain[idx2]) { 
                cout << "false" << endl;
            }
            else if (know2 && maximum >= rain[idx2]) {
                cout << "false" << endl;
            }
            else if (know1 && maximum >= rain[idx1]) {
                cout << "false" << endl;
            }
            else if (know1 && know2 && (y2 - y1 == idx2 - idx1)) {
                cout << "true" << endl;
            }
            else {
                cout << "maybe" << endl;
            }


        }

        getline(cin, s);
        cout << endl;
        space;

    }


    return 0;
}