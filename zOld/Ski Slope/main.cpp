#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "---------" << endl;

struct Node {
    ll enjoy;
    vector<ll> difficulty;
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ll n; cin >> n;
    vector<vector<int>> adj (n);
    vector<Node> nodes (n);

    nodes[0].enjoy = 0;
    nodes[0].difficulty = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 1; i < n; i++) {
        // going down the ski slope: i -> p
        // so going up: p -> i, p is parent of i

        ll p, d, e; cin >> p >> d >> e; p--;
        adj[p].push_back(i); 

        // there is 1 unique path to each child
        // so you can just sum up the parent's enjoyment with new enjoyment
        nodes[i].enjoy = (nodes[p].enjoy + e);
    
        // take in parent's 11 difficulties
        for (int j = 0; j < nodes[p].difficulty.size(); j++) {
            nodes[i].difficulty.push_back(nodes[p].difficulty[j]);
        }
        // add the current difficulty (now there are 12 difficulties)
        nodes[i].difficulty.push_back(d);

        // drop the lowest one (which is the first in the list)
        sort (nodes[i].difficulty.begin(), nodes[i].difficulty.end());
        nodes[i].difficulty.erase(nodes[i].difficulty.begin(), nodes[i].difficulty.begin() + 1);
    }

    /*
    for (int i = 0; i < nodes.size(); i++) {
        cout << nodes[i].enjoy << " | ";
        print(nodes[i].difficulty);
    }
    space;
    */


    // Now, we know all the enjoyments and difficulties for each node!
    // given skill s and courage c, we need the c + 1th difficulty to be <= s.
    // clearly we must group the friends (queries) by courage

    vector<vector<pair<ll, ll>>> friends (11); // pair: skill - index (orig position)
    ll m; cin >> m;
    for (int i = 0; i < m; i++) {
        ll s, c; cin >> s >> c;
        
        friends[c].push_back({s, i});
    }


    vector<ll> ans (m);

    for (int c = 0; c <= 10; c++) {

        vector<pair<ll, ll>> arr; // first sort by difficulty, then by enjoyment
        for (int i = 0; i < nodes.size(); i++) {
            arr.push_back({nodes[i].difficulty[10 - c], nodes[i].enjoy});
        }

        // sorting the vector of pairs automatically sorts it correctly
        sort (arr.begin(), arr.end());

        // DON'T FORGET: store the (prefix) maximum, just because you have high skill
        // you can still take an easier but more enjoyable ride
        for (int i = 1; i < arr.size(); i++) {
            arr[i].second = max (arr[i].second, arr[i - 1].second);
        }
        //printP(arr);

        for (int i = 0; i < friends[c].size(); i++) {
            ll skill = friends[c][i].first;

            pair<ll, ll> search = {skill, 1e18};

            // use upperbound to find the first difficulty greater
            ll idx = upper_bound(arr.begin(), arr.end(), search) - arr.begin();

            //cout << "found: " << arr[idx].first << " " << arr[idx].second << endl;

            // take max enjoyment the previous difficulty 
            ans[friends[c][i].second] = arr[idx - 1].second;
        
        }

    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}
