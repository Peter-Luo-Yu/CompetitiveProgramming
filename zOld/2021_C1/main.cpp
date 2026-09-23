#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;

    while (t--){
        int n, m, q; cin >> n >> m >> q;

        vector<int> order (n); for (int i = 0; i < n; i++) {cin >> order[i];}
        vector<int> arr (m); for (int i = 0; i < m; i++) {cin >> arr[i];}


        vector<int> tracker;
        map<int, int> visited; 

        for (int i = 0; i < m; i++){
            if (visited[arr[i]] == 0){     // not visited
                tracker.push_back(arr[i]);
                visited[arr[i]]++;
            }
        }

        bool failed = false;

        for (int i = 0; i < tracker.size(); i++){
            if (order[i] != tracker[i]){
                failed = true;
                break;
            }
        }

        //print(tracker); print(order);

        if (failed){
            cout << "TIDAK" << endl;
        } else {
            cout << "YA" << endl;
        }
      
    }

    return 0;
}