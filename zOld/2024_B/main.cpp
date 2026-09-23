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
        int n, k; cin >> n >> k;

        vector<int> arr (n); for (int i = 0; i < n; i++){cin >> arr[i];}
        vector<int> tracker;

        int ops = 0, score = 0;
        sort (arr.begin(), arr.end());

        tracker.push_back(n);
        for (int i = 0; i < n-1; i++){
            if (arr[i] != arr[i+1]){
                tracker.push_back(n - (i+1));
            }
        }

        vector<int> avail;
        avail.push_back(arr[0]);
        for (int i = 0; i < n-1; i++){
            if (arr[i] != arr[i+1]){
                avail.push_back(arr[i+1]-arr[i]);
            }
        }

        //print(tracker); print(avail); 
        
        //cout << "k: " << k << endl;

        int index = 0;
        while (score != k){
            ll cur = (ll) tracker[index] * avail[index];


            if (cur >= k - score){
                ops += k-score;
                score += k-score;
                
                //cout << "ops: " << ops << " score: " << score << " cur: " << cur << endl;
            }
            else {
                ops += (cur + tracker[index] - tracker[index+1]);
                score += cur;
                index++;

                //cout << "ops: " << ops << " score: " << score << " cur: " << cur << endl;
            }
            
        }

        cout << ops << endl;
    }

    return 0;
}