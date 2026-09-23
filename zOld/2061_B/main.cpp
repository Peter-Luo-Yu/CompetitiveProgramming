#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}
#define space cout << "----------" << endl;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> arr (n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort (arr.begin(), arr.end());

        //print(arr);

        // sum of 3 sides must exceed 4th side.
        // 2x + y > z -> 2x > z - y

        map<int, int> temp;
        map<int, pair<int, int>> diff;

        for (int i = 0; i < n; i++) {
            temp[arr[i]]++;
        }

        //printP(temp);

        vector<pair<int, int>> freq;
        for (auto x : temp) {
            freq.push_back({x.first, x.second});
        }
        reverse (freq.begin(), freq.end());

        //printP(freq);

       
        int Max = -1;
        for (auto x : freq) {
            if (x.second >= 2) {
                Max = max(Max, x.first);
            }
        }

        //cout << "MAX: " << Max << endl;
        
        if (Max == -1) {
            cout << "-1" << endl;
            //space;
            continue;
        }

        // updating freq
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i].first == Max) {
                freq[i].second -= 2;
            }
        }

        reverse (freq.begin(), freq.end());

        //printP(freq);

        // kind of a two pointers
        int r;
        bool found = false;
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i].second == 0) {
                continue;
            }
            else if (freq[i].second > 1) {   // done use the rectangle
                cout << freq[i].first << " " << freq[i].first << " " << Max << " " << Max << endl;
                found = true;
                break;
            }
            else {
                r = i + 1;
                while (freq[r].second <= 0) {
                    if (r >= freq.size() - 1) {
                        break;
                    }
                    r++;
                }
                if (r > freq.size() - 1) {
                    break;
                }

                //cout << "r: " << r << endl;

                if (2 * Max > freq[r].first - freq[i].first) {
                    cout << freq[r].first << " " << freq[i].first << " " << Max << " " << Max << endl;
                    found = true;
                    break;
                }
            }

        }
        

        if (!found) {
            cout << "-1" << endl;
        }

    }
    
    
    return 0;
}
