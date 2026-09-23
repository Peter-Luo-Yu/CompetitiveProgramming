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

vector<int> convert (int n) {
    vector<int> temp (8);
    int idx = 7;

    while (n > 0) {
        temp[idx] = n % 2;
        idx--;
        n /= 2;
    }
    
    return temp;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;

    vector<vector<int>> table, arr;
    vector<int> mask;

    vector<int> temp;
    for (int i = 0; i < n; i++) {
        temp = vector<int> ();

        string s; cin >> s;
        int prev = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '.') {
                //cout << s.substr(prev, j - prev) << endl;
                int num = stoi(s.substr(prev, j - prev));
                
                vector<int> binary = convert(num);
                for (int k = 0; k < 8; k++) {
                    temp.push_back(binary[k]);
                }

                prev = j + 1;
            }
            if (s[j] == '/') {
                //cout << s.substr(prev, j - prev) << endl;
                int num = stoi(s.substr(prev, j - prev));

                vector<int> binary = convert(num);
                for (int k = 0; k < 8; k++) {
                    temp.push_back(binary[k]);
                }

                prev = j + 1;
            }
        }
        table.push_back(temp);

        int num = stoi(s.substr(prev));

        mask.push_back(num);

    }

    for (int i = 0; i < m; i++) {
        temp = vector<int> ();

        string s; cin >> s;
        int prev = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '.') {
                //cout << s.substr(prev, j - prev) << endl;
                int num = stoi(s.substr(prev, j - prev));
                
                vector<int> binary = convert(num);
                for (int k = 0; k < 8; k++) {
                    temp.push_back(binary[k]);
                }

                prev = j + 1;
            }
            if (s[j] == '/') {
                //cout << s.substr(prev, j - prev) << endl;
                int num = stoi(s.substr(prev, j - prev));

                vector<int> binary = convert(num);
                for (int k = 0; k < 8; k++) {
                    temp.push_back(binary[k]);
                }

                prev = j + 1;
            }
        }

        int num = stoi(s.substr(prev));
        vector<int> binary = convert(num);
        for (int k = 0; k < 8; k++) {
            temp.push_back(binary[k]);
        }

        arr.push_back(temp);
    }
    
    
    //print2d(table); print(mask); space
    //print2d(arr);

    for (int i = 0; i < arr.size(); i++) {
        int Max = -1;
        int maxIdx = -1;

        for (int j = 0; j < table.size(); j++) {
            int cur = 0;

            for (int k = 0; k < arr[i].size(); k++) {
                if (arr[i][k] == table[j][k]) {
                    cur++;
                } else {
                    break;
                }

            }
            
            //cout << "cur matches: " << cur;
            cur = min (cur, mask[j]);
            //cout << " actually: " << cur << endl;

            if (cur > Max && cur >= mask[j]) {
                Max = cur;
                maxIdx = j;
            }
        }

        if (maxIdx != -1) {
            cout << maxIdx + 1 << endl;
        } else {
            cout << -1 << endl;
        }
        
    }

    return 0;
}
