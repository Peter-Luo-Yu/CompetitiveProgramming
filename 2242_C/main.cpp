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
        vector<int> arr (n);

        map<int, int> cnth; // val - freq
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            cnth[arr[i]]++;
        }

        map<int, int> distinct; // distinct height - sum of all occurences of that height
        map<int, int> distinctCnt; // distinct height - freq
        for (auto x : cnth) {
            distinct[x.second] += x.second;
            distinctCnt[x.second]++;
        }

        //printP(cnth); space; printP(distinct); space; printP(distinctCnt); space;

        vector<int> heights, tempH, tempC;
        for (auto x : distinct) {
            heights.push_back(x.first);
            tempH.push_back(x.second);
        }
        for (auto x : distinctCnt) {
            tempC.push_back(x.second);
        }

        //print(heights); print(tempH); print(tempC);

        vector<int> suffH(tempH.size() + 1), suffC(tempC.size() + 1);

        for (int i = tempH.size() - 1; i >= 0; i--) {
            suffH[i] = suffH[i + 1] + tempH[i];
            suffC[i] = suffC[i + 1] + tempC[i];
        }

        //print(suffH); print(suffC);

        int ans = 0;

        for (int i = 0; i < heights.size(); i++) {
            int S = suffH[i]; 
            int N = suffC[i];

            if ((k - S) % N == 0) {
                if ((k - S) / N >= -heights[i] + 1) {
                    ans++;
                }
            }
        }

        cout << ans << endl;

        //space; space;
    }


    return 0;
}
