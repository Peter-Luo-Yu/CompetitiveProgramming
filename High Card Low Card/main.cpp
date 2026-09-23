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

    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);

    int n; cin >> n;
    vector<int> elsie (n);
    for (int i = 0; i < n; i++) cin >> elsie[i];
    
    vector<int> arr = elsie;
    sort (arr.begin(), arr.end());

    vector<int> bessie;
    int idx = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (i == arr[idx]) {
            idx++;
        } else {
            bessie.push_back(i);
        }
    }

    sort (bessie.begin(), bessie.end());

    //print(elsie); print(bessie);

    vector<int> elsie1, bessie1;
    for (int i = 0; i < n/2; i++) {
        elsie1.push_back(elsie[i]);
    }
    for (int i = n/2; i < n; i++) {
        bessie1.push_back(bessie[i]);
    }
    sort (elsie1.begin(), elsie1.end());
    sort (bessie1.begin(), bessie1.end());

    //print(elsie1); print(bessie1);

    int ans = 0;
    int l = 0, r = 0; // l = elsie, r = bessie
    while (l < elsie1.size() && r < bessie1.size()) { // l and r < n / 2
        if (bessie1[r] > elsie1[l]) {
            l++, r++; ans++;
        } else {
            r++;
        }
    }


    vector<int> elsie2, bessie2;
    for (int i = n/2; i < n; i++) {
        elsie2.push_back(elsie[i]);
    }
    for (int i = 0; i < n/2; i++) {
        bessie2.push_back(bessie[i]);
    }
    sort (elsie2.begin(), elsie2.end()); reverse (elsie2.begin(), elsie2.end());
    sort (bessie2.begin(), bessie2.end()); reverse (bessie2.begin(), bessie2.end());

    //print(elsie2); print(bessie2);

    l = 0, r = 0; // l = elsie, r = bessie
    while (l < elsie2.size() && r < bessie2.size()) { // l and r < n / 2
        if (bessie2[r] < elsie2[l]) {
            l++, r++; ans++;
        } else {
            r++;
        }
    }



    cout << ans << endl;


    return 0;
}
