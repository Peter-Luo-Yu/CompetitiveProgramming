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

    string s;
    getline(cin, s);
    while (s != "") {
        //cout << s << endl;

        int N, L, W;
        
        int space = 0, count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (count == 0) {
                    //cout << "1: " << (s.substr(0, i)) << endl;
                    N = stoi(s.substr(0, i));
                    count++; space = i;
                }
                else if (count == 1) {
                    //cout << "2: " << (s.substr(space + 1, i - space)) << endl;
                    L = stoi(s.substr(space + 1, i - space));
                    count++; space = i;
                } 
            }
        }
        W = stoi(s.substr(space + 1));
        
        ld n = (ld) N, l = (ld) L, w = (ld) W;
        //cout << N << " " << L << " " << W << endl;
        
        vector<pair<ld, ld>> arr;

        for (int i = 0; i < N; i++) {
            getline (cin, s);

            for (int j = 0; j < s.size(); j++) {
                if (s[j] == ' ') {
                    space = j;
                }
            }

            int X = stoi(s.substr(0, space)), R = stoi(s.substr(space + 1));
            ld x = (ld) X, r = (ld) R;

            // interval: x - sqrt (r^2 - (w/2)^2)
            if (r < w / 2) continue;

            ld left = x - sqrtl (r * r - w * w / 4);
            ld right = x + sqrtl (r * r - w * w / 4);
            arr.push_back({left, right});
        }

        sort (arr.begin(), arr.end());
        /*
        for (auto x: arr) {
            cout << x.first << " " << x.second << endl;
        } */

        vector<bool> used (arr.size());
        ld cur = 0;
        int ans = 0;

        while (cur < l) {
            ld furthest = -1; 
            int idx = -1;
            for (int i = 0; i < arr.size(); i++) {
                if (used[i]) continue;

                if (arr[i].first <= cur) {
                    if (arr[i].second > furthest) {
                        furthest = arr[i].second;
                        idx = i;
                    }
                }
            }
            //cout << "cur: " << cur << " idx: " << idx << " chosen: " << furthest << endl;

            if (idx == -1) {
                ans = -1;
                break;
            }

            cur = furthest;
            used[idx] = true;
            ans++;
            
        }

        
        cout << ans << endl;
        
        getline(cin, s);
        
    }
    return 0;
}