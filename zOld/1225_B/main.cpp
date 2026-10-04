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
        int n, k, d; cin >> n >> k >> d;
        vector<int> arr (n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        int l = 1, r = n;
        int ans;
        while (l <= r) {
            int mid = (l + r) / 2;
            //cout << "mid: " << mid << endl;

            map<int, int> freq;
            int shows = 0;

            for (int i = 0; i < d; i++) {
                if (freq[arr[i]] == 0) {
                    shows++;
                }
                freq[arr[i]]++;
            }

            //cout << "start: " << shows << endl;
            bool failed = true;
            if (shows <= mid) {
                failed = false;

            }

            for (int i = d; i < n; i++) {
                //cout << "i: " << i << " shows: " << shows << endl; 

                //printP(freq);

                //cout << "remove: " << arr[i - d] << " add: " << arr[i] << endl;;
                //cout << freq[arr[i - d]] << " " << freq[arr[i]] << endl;

                if (freq[arr[i - d]] == 1) {
                    shows--;
                } 
                freq[arr[i - d]]--;
                

                if (freq[arr[i]] == 0) {
                    shows++;
                }
                freq[arr[i]]++;
            
                if (shows <= mid) {
                    failed = false;
                    break;
                }

                //space;
            }


            

            if (failed) {
                l = mid + 1;
            } else {
                ans = mid;
                r = mid - 1;
            }

            //space;
        }


        cout << ans << endl;
        //cout << "=======" << endl;
    }


    return 0;
}
