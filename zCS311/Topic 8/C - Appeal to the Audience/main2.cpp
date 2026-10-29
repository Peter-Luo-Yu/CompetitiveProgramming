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

// I promise no AI was used here: https://raw.githubusercontent.com/RussellDash332/kattis/main/src/Appeal%20to%20the%20Audience/appealtotheaudience.py

// Obs 1: every node contributes once except the root
// Idea: at each internal node, you have to select who gets to continue contributing 
//       and who is cut off and no longer continues to contribute
// Obs 2: you want the maximum value to contribute the most -> 
//        WHOEVER WAS ALREADY CONTRIBUTING THE MOST TAKES PRIORITY
// Obs 3: we track how many times any value could theoretically contribute,
//        and then calculate the answer from the sorted array 


vector<vector<ll>> adj;
vector<bool> vis;
vector<ll> skills, contrib; 

ll dfs(ll s, ll p, ll depth) { // returns depth from the leaf - distance to furthest leaf in cur subtree

    if (adj[s].size() == 1) { // if leaf
        return 1; // can only contribute itself once
    }

    ll maxDepth = -1;
    vector<ll> childDepths;
    for (auto u : adj[s]) {
        if (u == p) continue;

        ll d = dfs(u, s, depth + 1);
        childDepths.push_back(d);
        maxDepth = max(maxDepth, d);
    }

    print(s, childDepths);


    for (int i = 0; i < childDepths.size(); i++) {
        if (childDepths[i] == maxDepth) {  // any max survives
            for (int j = 0; j < childDepths.size(); j++) { // everybody else is dead
                if (i != j) {
                    contrib.push_back(childDepths[j]);
                }
            }
            return maxDepth + 1;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll n, k; cin >> n >> k;

    skills = vector<ll> (k);
    for (ll i = 0; i < k; i++) cin >> skills[i];
    sort (skills.begin(), skills.end());

    adj = vector<vector<ll>> (n);
    for (ll i = 1; i < n; i++) {
        ll p; cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    //print(adj);

    vis = vector<bool> (n);

    contrib.push_back(dfs(0, -1, 0));

    print(contrib);

    
    sort (contrib.begin(), contrib.end());
    contrib[contrib.size() - 1]--; // it overcounts the root

    
    ll ans = 0;

    for (int i = 0; i < k; i++) {
        ans += skills[i] * contrib[i];
    }

    cout << ans << endl;
    

    return 0;
}