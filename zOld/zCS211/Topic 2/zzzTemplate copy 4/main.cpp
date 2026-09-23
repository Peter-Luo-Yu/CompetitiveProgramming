#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int p, n; cin >> p >> n;
        vector<int> a (n);
        int sum = 0;
        for (int i = 0; i < n; i++) {cin >> a[i]; sum += a[i];}

        if (p > sum) {cout << "IMPOSSIBLE" << endl; continue;}
        
        vector<vector<int>> arr;

        int avg = p / n;

        //cout << "avg: " <<  avg << endl;

        // first sort by payment
        for (int i = 0; i < n; i++) {
            arr.push_back({a[i], avg, i});
        }

        sort (arr.begin(), arr.end());

        /*
        for (int i= 0; i < n; i++) {
            cout << "before: " <<  arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << endl;
        } */
        

        // sort by position as well
        int curIdx = 0;
        int minIdx = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i][0] > arr[i][1] && minIdx == -1) {
                minIdx = i;
            }
            if (arr[i][0] != arr[curIdx][0]) {
                //cout << "reversing: " << curIdx << " " << i << endl;
                reverse (arr.begin() + curIdx, arr.begin() + i);
                curIdx = i;
            }
        }
        //cout << "reversing: " << curIdx << " " << n - 1 << endl;
        reverse (arr.begin() + curIdx, arr.end());


        // adding the rest, since 

        //cout << "remainder: " << p % n << endl;
        // int temp = arr.size() - 1;
        for (int i = 0; i < p % n; i++) {
            /*
            if (temp < 0) {
                temp = arr.size() - 1;
            }
            if (arr[temp][0] > arr[temp][1]) {
                arr[temp][1]++;
                temp--;
            } else {
                temp--;
                i--;
            } */
            arr[arr.size() - 1 - i][1]++;
        
        }
        
        /*
        for (int i= 0; i < n; i++) {
            cout << "after: " <<  arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << endl;
        } 
        */

        //cout << "startingpoint: " << minIdx << endl;

        int index = arr.size() - 1; 
        //cout << "startingIdx: " << index << endl;
        for (int i = 0; i < arr.size(); i++) {
            //cout << arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << endl;
            
            if (arr[i][0] < arr[i][1]) {
                int diff = arr[i][1] - arr[i][0];

                //cout << "diff: " << diff << endl;

                for (int j = 0; j < diff; j++) {
                    if (index < 0) {
                        index = arr.size() - 1;
                    }

                    if (arr[index][1] >= arr[index][0]) {
                        index--;
                        j--;
                    }
                    else {
                        arr[index][1]++;
                        //cout << "idx: " << index << " updated!" << endl;
                        index--;
                       
                    }
                }
            }

        }

        vector<int> ans (n);
        for (int i = 0; i < n; i++) {
            ans[arr[i][2]] = min (arr[i][0], arr[i][1]);
        }

        print(ans);

        //cout << "------------" << endl;
       
    }
    

    return 0;
}