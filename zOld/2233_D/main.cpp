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

bool check (vector<int> &arr) {
    map<int, int> last, first, cnt;
    for (int i = 0; i < arr.size(); i++) {
        cnt[arr[i]]++;

        if (cnt[arr[i]] == 1) {
            first[arr[i]] = i;
        }
        
        last[arr[i]] = i;
    }

    bool good = true;

    for (auto x : cnt) {
        if (last[x.first] - first[x.first] + 1 != x.second) {
            good = false;
        }
    }

    return good;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr (n);
        map<int, int> last, first, cnt;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            cnt[arr[i]]++;

            if (cnt[arr[i]] == 1) {
                first[arr[i]] = i;
            }
           
            last[arr[i]] = i;
        }

        //printP(first); space; printP(last); space; printP(cnt); space;

        vector<int> bad;
        for (auto x : cnt) {
            if (last[x.first] - first[x.first] + 1 != x.second) {
                bad.push_back(x.first);
            }
        }

        //cout << "BAD: "; print(bad);

        if (bad.size() > 2) { // impossible
            cout << "NO" << endl;
            continue;
        }

        if (bad.size() == 0) { // already good
            cout << "YES" << endl;
        }
        else if (bad.size() == 2) {
            bool succeed = false;
            
            int idx1 = first[bad[0]], idx2 = last[bad[0]]; 
            int idx3 = first[bad[1]], idx4 = last[bad[1]];

            // swap idx1 with idx3 and idx4, swap idx2 with idx3 and idx4

            vector<int> swapped = arr; 
            swap(swapped[idx1], swapped[idx3]);
            if (check(swapped)) succeed = true;

            swapped = arr; 
            swap(swapped[idx1], swapped[idx4]);
            if (check(swapped)) succeed = true;
            
            swapped = arr; 
            swap(swapped[idx2], swapped[idx3]);
            if (check(swapped)) succeed = true;

            swapped = arr; 
            swap(swapped[idx2], swapped[idx4]);
            if (check(swapped)) succeed = true;

            if (succeed) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
        else {
            bool succeed = false;

            int idx1 = first[bad[0]], idx2 = last[bad[0]]; 
            int idx3 = -1, idx4 = -1, idx5 = -1, idx6 = -1;
            for (int i = idx1 + 1; i < idx2; i++) {
                if (arr[i] != bad[0]) {
                    idx3 = i;
                    break;
                }
            }
    
            for (int i = idx2 - 1; i > idx1; i--) {
                if (arr[i] != bad[0]) {
                    idx4 = i;
                    break;
                }
            }

            for (int i = last[bad[0]] + 1; i < n; i++) {
                if (arr[i] != bad[0]) {
                    idx5 = i;
                    break;
                }
            }

            for (int i = first[bad[0]] - 1; i >= 0; i--) {
                if (arr[i] != bad[0]) {
                    idx6 = i;
                    break;
                }
            }
            
            //cout << idx1 << " " << idx2 << " " << idx3 << " " << idx4 << endl;

            vector<int> swapped = arr; 
            swap(swapped[idx1], swapped[idx3]);
            if (check(swapped)) succeed = true;

            swapped = arr; 
            swap(swapped[idx1], swapped[idx4]);
            if (check(swapped)) succeed = true;
            
            swapped = arr; 
            swap(swapped[idx2], swapped[idx3]);
            if (check(swapped)) succeed = true;

            swapped = arr; 
            swap(swapped[idx2], swapped[idx4]);
            if (check(swapped)) succeed = true;

            if (idx5 != -1) {
                swapped = arr; 
                swap(swapped[idx1], swapped[idx5]);
                if (check(swapped)) succeed = true;

                swapped = arr; 
                swap(swapped[idx2], swapped[idx5]);
                if (check(swapped)) succeed = true;
            }

            if (idx6 != -1) {
                swapped = arr; 
                swap(swapped[idx1], swapped[idx6]);
                if (check(swapped)) succeed = true;

                swapped = arr; 
                swap(swapped[idx2], swapped[idx6]);
                if (check(swapped)) succeed = true;
            }

            if (succeed) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }

        }
        
        //cout << "==========" << endl;
    }


    return 0;
}
