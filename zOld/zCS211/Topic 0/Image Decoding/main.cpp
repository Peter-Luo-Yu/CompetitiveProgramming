#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j];} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    bool firstTime = true;
    string t; 
    while (t != "0") {
        getline(cin, t);
        //cout << t << endl;

        if (t != "0" && !firstTime) {
            cout << endl;
        }
        firstTime = false;

        string s; 
        vector<vector<char>> ans;
        int size = -1;
        bool failed = false;

        for (int i = 0; i < stoi(t); i++) {
            getline(cin, s);
            //cout << s << endl;
            s += " ";

            char start = s[0];
            int count = 0;
            string temp = "";
            vector<char> line;
            
            for (int j = 2; j < s.size(); j++) {
                temp += s[j];

                if (s[j] == ' ') {
                    //cout << "size: " << temp << endl;

                    int length = stoi (temp); 

                    count += length;

                    for (int k = 0; k < length; k++) {
                        line.push_back(start);
                    }
                    if (start == '#') {
                        start = '.';
                    } else {
                        start = '#';
                    }

                    temp = "";
                }
            }

            //cout << "line: "; print(line);

            if (size == -1) {
                size = count;
            } else {
                if (size != count) {
                    failed = true;
                }
            }

            ans.push_back(line);

        }

        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j];
            }
            cout << endl;
        }
        if (failed) {
            cout << "Error decoding image" << endl;
        } 
        
        
        
    }
    

    return 0;
}