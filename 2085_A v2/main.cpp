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

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        
        vector<char> arr (n);
        string s; cin >> s;
        for (int i = 0; i < n; i++) {
            arr[i] = s[i];
        }

        vector<char> sorted = arr;
        sort (sorted.begin(), sorted.end());

        //print(sorted);

        int ops = 0;
        bool done = false;

        //print(arr);

        for (int i = 0; i < n; i++) {
            
            string one = "", two = "";

            vector<char> rev = arr;
            reverse (rev.begin(), rev.end());

            for (int i = 0; i < n; i++) {
                one += arr[i];
                two += rev[i];
            }

            //cout << one << " " << two << endl;

            if (one < two) {
                done = true;
                break;
            }

            if (ops == k) {
                break;
            }

            if (arr[i] == sorted[i]) continue;

            int idx;
            for (int j = i; j < arr.size(); j++) {
                if (arr[j] == sorted[i]) {
                    idx = j;
                    break;
                }
            }

            swap (arr[i], arr[idx]);
            ops++;

            //print(arr);
        }

        if (done) {
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }

        //space;
    }


    return 0;
}
