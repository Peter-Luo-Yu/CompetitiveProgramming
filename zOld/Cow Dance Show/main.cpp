#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);

    int n, t; cin >> n >> t;

    vector<int> arr (n);
    for (int i = 0; i < n; i++) {cin >> arr[i];}

    int l = 1, r = n; // binary search on k
    int ans = 2e9;

    while (l <= r) {
        int mid = (l+r)/2;

        int idx = 0;
        vector<int> temp = arr;
        vector<int> q (mid, -1);
        int time = 0;

        /*
        cout << "MID: " << mid << "-----------" <<endl;
        cout << "temp: ";
        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i] << " ";
        } cout << endl;
        */

        while (true) {

            int Min = 2e9;
            for (int i = 0; i < q.size(); i++) {
                if (q[i] == -1 && idx < n) {
                    q[i] = idx;
                    idx++;
                }
                if (q[i] != -1) {
                    Min = min(Min, temp[q[i]]);
                }

                //cout << q[i] << " ";
                
            }
            //cout <<  "min:" << Min << endl;


            for (int i = 0; i < q.size(); i++) {
                if (q[i] != -1) {
                    temp[q[i]] -= Min;
                    if (temp[q[i]] == 0) {
                        q[i] = -1;
                    }
                }
            }
            
            /*
            cout << "temp: ";
            for (int i = 0; i < temp.size(); i++) {
                cout << temp[i] << " ";
            } cout << endl;
            */

            time += Min;

            //cout << time << endl;

            bool done = true;
            for (int i = 0; i < q.size(); i++) {
                if (q[i] != -1) {
                    done = false;
                }
            }

            if (done) {
                break;
            }
        }

        if (time <= t) {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}