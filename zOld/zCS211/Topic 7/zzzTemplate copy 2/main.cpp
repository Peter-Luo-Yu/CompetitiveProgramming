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

    int n; cin >> n;
    vector<string> arr (n);

    stack<pair<string, int>> stk;
    int depth = 0;
    int T = -1;
    map<int, vector<pair<string, int>>> mp;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        string cur = arr[i].substr(arr[i].size() - 1, 1);
        //cout << cur << endl;

        if (cur == "{") {
            stk.push({cur, i});
            depth++;
        }
        
        else if (cur == "}") {
            pair<string, int> top = stk.top();
            stk.pop();

            mp[depth].push_back({cur, i});
            mp[depth].push_back(top);

            depth--;
        } 
    }

    /*
    for (auto m : mp) {
        cout << m.first << endl; printP(m.second);
    } */
    
    
    // s(l) + t(l) * t = s(r) + t(r) * t
    for (int t = 1; t <= 1000; t++) {
        map<int, vector<int>> widths;

        for (auto x : mp) { // 2 loops total to 100
            for (int i = 0; i < x.second.size(); i++) { 
                int idx = x.second[i].second;
                //cout << "idx: " << idx << endl;
                int curW = 0;

                for (int j = 0; j < arr[idx].size() - 1; j++) { // 1000
                    if (arr[idx][j] == 's') {
                        curW += 1;
                    } else {
                        curW += t;
                    }
                } 

                widths[x.first].push_back(curW);
            }
        }

        bool all_same = true;
        bool width_fail = false;
        int prev_width = -1;
        int K = -1;

        for (auto x : widths) {
            // first = depth, second = widths
            
            //cout << x.first << endl; print(x.second); 

            for (int i = 0; i < x.second.size() - 1; i++) {
                if (x.second[i] != x.second[i+1]) {
                    all_same = false; break;
                }
            }
            if (!all_same) {
                break;
            }

            int cur_width = x.second[0];
            if (prev_width == -1) {
                prev_width = cur_width;
            }
            else {
                if (K == -1) {
                    K = cur_width - prev_width;
                    if (K == 0) {
                        width_fail = true;
                        break;
                    }
                    prev_width = cur_width;
                } else {
                    if (cur_width - prev_width != K) {
                        width_fail = true;
                        break;
                    } else {
                        prev_width = cur_width;
                    }
                }
            }
        }
        if (!width_fail && all_same) {
            T = t; break;
        }
    }
    
    
    cout << T << endl;
    
    
    return 0;
}
