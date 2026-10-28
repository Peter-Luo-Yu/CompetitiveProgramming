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

vector<ll> skills;
vector<vector<ll>> adj;
vector<bool> vis;
vector<ll> depth, value;

ll ans = 0;

void calcdepth(ll s) {
    if (vis[s]) return;
    vis[s] = true;

    for (auto u : adj[s]) {
        if (vis[u]) continue;

        depth[u] = depth[s] + 1;
        calcdepth(u);
    }
}


void calcans(ll s) {
    if (vis[s]) return;
    vis[s] = true;

    if (adj[s].size() == 1) { // skip leaf
        return;
    }

    ll sum = 0;
    ll winner = -1;
    for (auto u : adj[s]) {
        if (vis[u]) continue;

        calcans(u);

        winner = max(winner, value[u]);
        sum += value[u];
        
    }
    value[s] = winner;
    ans += sum;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n, k; cin >> n >> k;

    skills = vector<ll> (k);
    for (ll i = 0; i < k; i++) cin >> skills[i];

    adj = vector<vector<ll>> (n);
    for (ll i = 1; i < n; i++) {
        ll p; cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    print(adj);

    vis = vector<bool> (n);
    depth = vector<ll> (n);

    calcdepth(0);

    print(depth);

    // put all the depths together, only for the leaves though :)
    map<ll, vector<ll>> mp;
    for (ll i = 0; i < n; i++) {
        if (adj[i].size() == 1) {
            mp[depth[i]].push_back(i);
        }
    }
    print(mp);

    // now we try to assign values
    value = vector<ll> (n);
    sort (skills.begin(), skills.end());
    ll l = 0, r = skills.size() - 1;

    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        for (int i = 0; i < (it -> second).size(); i++) {
            if (i == 0) {
                value[(it -> second)[0]] = skills[r];
                r--;
            }
            else {
                value[(it -> second)[i]] = skills[l];
                l++;
            }
        }
    }

    print(value);

    vis = vector<bool> (n);

    calcans(0);

    print(ans);

    cout << ans << endl;

    return 0;
}