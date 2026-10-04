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

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k; cin >> n >> k;

    int and12, or12, and13, or13, and23, or23;

    cout << "and 1 2" << endl; 
    cout.flush();
    cin >> and12;

    cout << "or 1 2" << endl; 
    cout.flush();
    cin >> or12;

    cout << "and 1 3" << endl; 
    cout.flush();
    cin >> and13;

    cout << "or 1 3" << endl; 
    cout.flush();
    cin >> or13;

    cout << "and 2 3" << endl; 
    cout.flush();
    cin >> and23;

    cout << "or 2 3" << endl; 
    cout.flush();
    cin >> or23;

    
    vector<int> a(n + 1);

    // a + b = (a and b) + (a or b)
    // a1 + a2 + a1 + a3 - a2 - a3 = 2 * a1

    a[1] = (and12 + or12 + and13 + or13 - and23 - or23) / 2;
    
    a[2] = (and12 + or12) - a[1];
    a[3] = (and23 + or23) - a[2];

    for (int i = 4; i <= n; i++) {
        // find sum (a1 + ai) using and + or, ai = sum - a1

        int AND, OR;

        cout << "and 1 " << i << endl;
        cout.flush();
        cin >> AND;

        cout << "or 1 " << i << endl;
        cout.flush();
        cin >> OR;

        a[i] = AND + OR - a[1];
    }

    sort (a.begin(), a.end());

    cout << "finish " << a[k] << endl;

    return 0;
}
