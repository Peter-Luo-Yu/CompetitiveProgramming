#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;

    vector<ld> pos (n), speed (n);
    for (int i = 0; i < n; i++) {cin >> pos[i];}
    for (int i = 0; i < n; i++) {cin >> speed[i];}

    vector<pair<ld, ld>> arr (n);
    for (int i = 0; i < n; i++) {
        arr[i] = {pos[i], speed[i]};
    }
    sort (arr.begin(), arr.end());

    ld l = arr[0].first, r = arr[arr.size() - 1].first;
    ld ans = 9e18;     
    while (r - l > 0.0000001) {
        ld mid = (l+r)/ (ld) 2;       // where to meet
        
        bool leftHasMax = false, rightHasMax = false;
        ld max_time = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i].first == mid) continue;

            // new max
            if ((abs(arr[i].first - mid)/arr[i].second) > max_time) {
                max_time = (abs(arr[i].first - mid)/arr[i].second);

                leftHasMax = false;
                rightHasMax = false;
                if (arr[i].first < mid) {
                    leftHasMax = true;
                } else {
                    rightHasMax = true;
                }
            }

            else if ((abs(arr[i].first - mid)/arr[i].second) == max_time) {
                if (arr[i].first < mid) {
                    leftHasMax = true;
                } else {
                    rightHasMax = true;
                }
            }
        }   

        ans = min(ans, max_time); // question asks for min time
        
        if (leftHasMax && rightHasMax) {
            break;
        }
        else if (leftHasMax && !rightHasMax) {   // can't subtract 1 because it too big
            r = mid;    // the max is on the left, so we move left by shifting the right point.
        } else {
            l = mid;
        }

       
    }
    
    if (ans == 9e18) {
        cout << 0 << endl;
    } else {
        cout << fixed << ans << endl;
    }

    return 0;
}