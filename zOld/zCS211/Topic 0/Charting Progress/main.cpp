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
    vector<vector<char>> arr;
    vector<vector<char>> ans;
    vector<char> temp;

    while (getline(cin, s)) {        
        temp = vector<char> ();
        for (int i = 0; i < s.size(); i++) {
            temp.push_back(s[i]);
        }
        arr.push_back(temp);

        if (s.empty()) {
            //print2d(arr);
            
            int idx = arr[0].size() - 1;

            for (int i = 0; i < arr.size(); i++) {
                //cout << "len: " << arr[i].size() << endl;

                int count = 0;

                for (int j = 0; j < arr[i].size(); j++) {
                    if (arr[i][j] == '*') {
                        count++;
                    }
                }

                //cout << count << endl;

                temp = vector<char> ();
                for (int j = 0; j <= idx - count; j++) {
                    temp.push_back('.');
                }
                for (int j = idx - count + 1; j <= idx; j++) {
                    temp.push_back('*');
                }
                for (int j = idx + 1; j < arr[i].size(); j++) {
                    temp.push_back('.');
                }

                //cout << "len: " << temp.size() << endl;

                idx -= count;

                ans.push_back(temp);

            }

            for (int i = 0; i < ans.size(); i++) {
                for (int j = 0; j < ans[i].size(); j++) {
                    cout << ans[i][j];
                }
                cout << endl;
            }

            arr = vector<vector<char>> ();
            temp = vector<char> ();
            ans = vector<vector<char>> ();
        }
    }

    
    int idx = arr[0].size() - 1;
    for (int i = 0; i < arr.size(); i++) {
        //cout << "len: " << arr[i].size() << endl;

        int count = 0;

        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == '*') {
                count++;
            }
        }

        //cout << count << endl;

        temp = vector<char> ();
        for (int j = 0; j <= idx - count; j++) {
            temp.push_back('.');
        }
        for (int j = idx - count + 1; j <= idx; j++) {
            temp.push_back('*');
        }
        for (int j = idx + 1; j < arr[i].size(); j++) {
            temp.push_back('.');
        }

        //cout << "len: " << temp.size() << endl;

        idx -= count;

        ans.push_back(temp);

    }

    
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j];
        }
        cout << endl;
    } 
        

    return 0;
}