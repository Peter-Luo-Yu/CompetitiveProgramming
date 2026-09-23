#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << " "; cout << "\n";
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) {cout << x.first << " " << x.second << "\n";}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        //cout << s << endl;

        int l1, r1, l2, r2;
        int idx = -1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                idx = i;
                break;
            }
        }

        if (idx == -1) {
            cout << 1 << " " << s.size() << " " << 1 << " " << 1 << endl;
            //cout << "---------" << endl;
            continue;
        }

        l1 = 1; r1 = s.size();

        int len = s.size() - idx;
        //cout << "idx: " << idx << " len: " << len << endl;

        vector<int> best (s.size(), -1);

        for (int i = 0; i < s.size() - len + 1; i++) {
            string s2 = s.substr(i, len);   
            //cout << "s2: " << s2 << endl;

            int idx1 = s.size() - 1;
            int idx2 = s2.size() - 1;

            vector<int> arr (s.size(), 1);

            for (int j = 0; j < s2.size(); j++) {
                int one = s[idx1 - j] - '0';
                int two = s2[idx2 - j] - '0'; 

                int x = one ^ two;

                //cout << "idx: " << idx1 - j << " " << one << " " << two << " xor: " <<  x << endl;

                arr[idx1 - j] = x;
            }

            //cout << "arr: "; print(arr);
            //cout << "l2: " << i + 1 << " r2: " << i + len << endl; 

            //cout << "best: "; print(best);
            for (int j = 0; j < arr.size(); j++) {
                if (best[j] != arr[j])  {
                    if (arr[j] > best[j]) {
                        //cout << "j: " << j << " arr[j]: " << arr[j] << " best[j]: " << best[j] << endl;
                        //cout << "arr is better!"<< endl;
                        best = arr;
                        l2 = i + 1; r2 = i + len;
                    } 
                    break;
                }
            }
            //cout << "----" << endl;
        }
        cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
        //cout << "-----------" << endl;
    }
    
    return 0;
}
