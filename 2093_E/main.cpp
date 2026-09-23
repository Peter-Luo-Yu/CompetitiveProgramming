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

        for (int i = 0; i < n; i++) cin >> arr[i];

        int l = 0, r = 1e9;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            //cout << "mid: " << mid << endl;

            int cnt = 0;

            set<int> st;
            int size = 0;

            for (int i = 0; i < n; i++) {
                st.insert(arr[i]);
                size++;

                int mex = 0;
                for (int i = 0; i < size; i++) {
                    if (st.count(i)) {
                        mex++;
                    } else {
                        break;
                    }
                }

                //cout << "mex: " << mex << endl;

                if (mex >= mid) {
                    cnt++;

                    st = set<int> ();
                    size = 0;
                    mex = 0;
                }
            }
            
            if (cnt >= k) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }

          
        }

        cout << ans << endl;

        //space;
    }


    return 0;
}
