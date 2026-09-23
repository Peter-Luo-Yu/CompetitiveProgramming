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

    string s; getline(cin, s);
    s += '\n';  // some cheese to get it to read the last sentence
    
    vector<vector<pair<string, int>>> arr; // 0 = nothing, 1 = before, 2 = after, 3 = both
    map<string, vector<pair<int, int>>> pos;

    int prev_idx = 0;
    char prev = ' ';
    vector<pair<string, int>> sentence;

    queue<pair<string, int>> q; // 1 = before, 2 = after

    for (int i = 0; i < s.size(); i++) {
        string temp;

        if (s[i] == ' ' || s[i] == '\n') {
            temp = s.substr(prev_idx, i - prev_idx);
            prev_idx = i + 1;

            //cout << "temp: " << temp << endl;


            if (prev == ',') {
                if (temp[temp.size() - 1] == ',') {
                    sentence.push_back({temp.substr(0, temp.size() - 1), 3});
                    q.push({temp.substr(0, temp.size() - 1), 1});
                    q.push({temp.substr(0, temp.size() - 1), 2});

                    prev = ',';
                }
                else if (temp[temp.size() - 1] == '.') {
                    sentence.push_back({temp.substr(0, temp.size() - 1), 1});
                    q.push({temp.substr(0, temp.size() - 1), 1});
 
                    arr.push_back(sentence);
                    sentence = vector<pair<string, int>> ();
                    prev = '.';
                } else {
                    sentence.push_back({temp, 1});
                    prev = ' ';
                }
            } 
            else if (prev == ' ') {
                if (temp[temp.size() - 1] == ',') {
                    sentence.push_back({temp.substr(0, temp.size() - 1), 2});
                    q.push({temp.substr(0, temp.size() - 1), 2});

                    prev = ',';
                }
                else if (temp[temp.size() - 1] == '.') {
                    sentence.push_back({temp.substr(0, temp.size() - 1), 0});
                    arr.push_back(sentence);
                    sentence = vector<pair<string, int>> ();
                    prev = '.';
                } else {
                    sentence.push_back({temp, 0});
                    prev = ' ';
                }
            } 
            else { // prev == .
                if (temp[temp.size() - 1] == ',') {
                    sentence.push_back({temp.substr(0, temp.size() - 1), 2});
                    q.push({temp.substr(0, temp.size() - 1), 2});

                    prev = ',';
                }
                else if (temp[temp.size() - 1] == '.') {
                    sentence.push_back({temp.substr(0, temp.size() - 1), 0});
                    arr.push_back(sentence);
                    sentence = vector<pair<string, int>> ();
                    prev = '.';
                } else {
                    sentence.push_back({temp, 0});
                    prev = ' ';
                }
            } 
        }

    }
    
    
    //space;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            //cout << arr[i][j].first << " " << arr[i][j].second << endl;
            
            pos[arr[i][j].first].push_back({i, j});
        }
    } //space;

    /*
    for (auto x: pos) {
        cout << x.first << " "; printP(x.second);
    } space;
    */

    map<pair<string, int>, bool> vis;

    while (!q.empty()) {
        pair<string, int> cur = q.front();
        q.pop();

        //cout << "cur: " << cur.first << " " << cur.second << endl;

        if (vis[cur]) continue;
        vis[cur] = true;

        vector<pair<int, int>> positions = pos[cur.first];

        for (int i = 0; i < positions.size(); i++) {
            int I = positions[i].first, J = positions[i].second;

            if (cur.second == 1) {  // add comma to left
                if (J == 0) continue;

                if (arr[I][J].second == 0) {
                    arr[I][J].second = 1;
                } 
                else if (arr[I][J].second == 2) {
                    arr[I][J].second = 3;
                }

                q.push({arr[I][J - 1].first, 2});
            }
            else if (cur.second == 2) {
                if (J == arr[I].size() - 1) continue;
                
                if (arr[I][J].second == 0) {
                    arr[I][J].second = 2;
                } 
                else if (arr[I][J].second == 1) {
                    arr[I][J].second = 3;
                }

                q.push({arr[I][J + 1].first, 1});
            }
      
        }
    }

    /*
    space;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j].first << " " << arr[i][j].second << endl;
        }
    } space;
    */

    //space;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size() - 1; j++) {
            if (arr[i][j].second == 0 && arr[i][j + 1].second == 1) {
                cout << arr[i][j].first << ", ";
            }
            else if (arr[i][j].second == 0 && arr[i][j + 1].second == 3) {
                cout << arr[i][j].first << ", ";
            }

            else if (arr[i][j].second == 1 && arr[i][j + 1].second == 1) {
                cout << arr[i][j].first << ", ";
            }
            else if (arr[i][j].second == 1 && arr[i][j + 1].second == 3) {
                cout << arr[i][j].first << ", ";
            }

            else if (arr[i][j].second == 2) {
                cout << arr[i][j].first << ", ";
            }
            else if (arr[i][j].second == 3) {
                cout << arr[i][j].first << ", ";
            } else {
                cout << arr[i][j].first << " ";
            }
        }
        cout << arr[i][arr[i].size() - 1].first << ". ";
    } //space;

    
    return 0;
}
