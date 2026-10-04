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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cruise.in", "r", stdin);
    freopen("cruise.out", "w", stdout);

    int n, m, k; 
    cin >> n >> m >> k;

    vector<pair<int, int>> arr (n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        arr[i].first--;
        arr[i].second--;
    }

    vector<char> order (m);
    for (int i = 0; i < m; i++) {
        cin >> order[i];
    }

    vector<vector<int>> vis (n, vector<int> (m));
    int curN = 0, curM = 0;
    while (!vis[curN][curM]) {
        vis[curN][curM] = true;

        if (order[curM] == 'L') {
            curN = arr[curN].first;
        } else {
            curN = arr[curN].second;
        }
        curM++;

        if (curM == m) {
            curM = 0;
        }
    }

    //cout << curN << " " << curM << endl;

    // now we know the first state that repeats = start of cycle
    int startN = curN, startM = curM;
    int len_to_cycle = 0;

    curN = 0, curM = 0;
    while (curN != startN || curM != startM) {
        if (order[curM] == 'L') {
            curN = arr[curN].first;
        } else {
            curN = arr[curN].second;
        }
        curM++;
        if (curM == m) {
            curM = 0;
        }
        len_to_cycle++;
    }

    //cout << "len to cycle: " << len_to_cycle << endl;

    int cycle_len = 0;
    vector<int> cycle;

    curN = startN, curM = startM;
    do {
        cycle.push_back(curN);
        if (order[curM] == 'L') {
            curN = arr[curN].first;
        } else {
            curN = arr[curN].second;
        }
        curM++;
        if (curM == m) {
            curM = 0;
        }
        cycle_len++;

    } while (curN != startN || curM != startM);


    //cout << "cycle len: " << cycle_len << endl;
    //print(cycle);


    ll ans_idx = ((ll) m * (ll) k - len_to_cycle) % cycle_len;
    cout << cycle[ans_idx] + 1 << endl;


    return 0;
}
