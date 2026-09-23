#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n; cin >> n;   
    vector<double> arr (n);
    for (int i = 0; i < n; i++) {cin >> arr[i];}
    sort (arr.begin(), arr.end());
    
    double l = arr[0], r = arr[arr.size() - 1];
    double ans;
    while (l <= r) {
        double mid = (l+r)/2;
        double x = (double) (arr[0] + arr[arr.size() - 1])/ (double) 2;


        //print(arr); cout << "x: " << x << endl;

        // finds first element smaller
        int left = 0, right = arr.size() - 1;
        int idx;
        while (left <= right) {
            int middle = (left + right)/2;
            //cout << "middle: " <<  middle << endl;
            if (arr[middle] > x) {
                right = middle - 1;
                idx = right;
            } 
            else if (arr[middle] < x) {
                left = middle + 1;
            }
            else {
                idx = middle;
                break;
            }
        }
        //cout << idx << endl;


        // simulate
        bool failed = false;

        vector<double> tracker (n, -1); // tracks explosion radius 
        int i = idx + 1;
        int j = i;                      // current blast that detonated the ith haybale
        double maxrange = x + mid;

        //cout << "starting radius: " << mid << " range: " << maxrange << endl;
        while (maxrange >= arr[i] && i < n) {
            if (maxrange == x + mid) {
                tracker[i] = mid - 1;
                if (arr[i] + tracker[i] > maxrange) {
                    maxrange = arr[i] + tracker[i];
                }

                //cout << "i: " << i << " a[i]: " << arr[i] << " r: " << tracker[i] << " range: " << maxrange << endl;
                i++;
            }
            else {
                if (arr[i] <= arr[j] + tracker[j]) {
                    tracker[i] = tracker[j];
                    if (arr[i] + tracker[i] > maxrange) {
                        maxrange = arr[i] + tracker[i];
                    }
                }
                else if ((arr[i] > arr[j] + tracker[j]) && (arr[i] <= maxrange)) {
                    tracker[i] = tracker[j] - 1;
                    if (arr[i] + tracker[i] > maxrange) {
                        maxrange = arr[i] + tracker[i];
                    }
                    j = i;
                }
                //cout << "i: " << i << " a[i]: " << arr[i] << " r: " << tracker[i] << " range: " << maxrange << endl;
                i++;
            }
        }

        //cout << "i: " << i << endl;


        int i2 = idx;
        int j2 = i2;                      // current blast that detonated the ith haybale
        double maxrange2 = x - mid;

        //cout << "starting radius: " << mid << " range: " << maxrange2 << endl;
        while (maxrange2 <= arr[i2] && i2 >= 0) {
            if (maxrange2 == x - mid) {
                tracker[i2] = mid - 1;
                if (arr[i2] - tracker[i2] < maxrange2) {
                    maxrange2 = arr[i2] - tracker[i2];
                }

                //cout << "i: " << i2 << " a[i]: " << arr[i2] << " r: " << tracker[i2] << " range: " << maxrange2 << endl;
                i2--;
            }
            else {
                if (arr[i2] >= arr[j2] - tracker[j2]) {
                    tracker[i2] = tracker[j2];
                    if (arr[i2] - tracker[i2] < maxrange2) {
                        maxrange2 = arr[i2] - tracker[i2];
                    }
                }
                else if ((arr[i2] > arr[j2] - tracker[j2]) && (arr[i2] >= maxrange2)) {
                    tracker[i2] = tracker[j2] - 1;
                    if (arr[i2] - tracker[i2] < maxrange2) {
                        maxrange2 = arr[i2] - tracker[i2];
                    }
                    j2 = i2;
                }
                //cout << "i: " << i2 << " a[i]: " << arr[i2] << " r: " << tracker[i2] << " range: " << maxrange2 << endl;
                i2--;
            }
        }
        //cout << "i2: " << i2 << endl;

        //cout << "---------------------" << endl;

        if (i != n || i2 != -1) {
            l = mid + 1;
        } else {
            ans = mid;
            r = mid - 1;
        }



    }

    cout << fixed << setprecision(1) << ans << endl;
    

    return 0;
}