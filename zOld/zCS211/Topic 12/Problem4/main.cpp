#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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

    int r, c; cin >> r >> c;
    vector<vector<int>> data (r, vector<int> (c)); 

    for (int i = 0; i < r; i++) {
        string s; cin >> s;
        for (int j = 0; j < c; j++) {
           data[i][j] = s[j] - '0'; 
        }
    }
    
    //print2d(data);
    
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        priority_queue<pair<int, pair<int, int>>> pq; // distance - node
        vector<vector<int>> distance (r, vector<int> (c)); // node - distance
        vector<vector<int>> vis (r, vector<int> (c)); // node - vis or not

        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;


        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                distance[i][j] = 1e9;
            }
        }

        distance[x1][y1] = 0;
        pq.push({0, {x1, y1}});


        while (!pq.empty()) {
            int curX = pq.top().second.first;
            int curY = pq.top().second.second;

            int curD = -pq.top().first;
            pq.pop();

            if (vis[curX][curY] == true) continue;
            vis[curX][curY] = true;


            vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
            vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

            for (int i = 0; i < 8; i++) {
                int nextX = curX + dx[i];
                int nextY = curY + dy[i];

                if (nextX < 0 || nextY < 0 || nextX > r - 1 || nextY > c - 1) {
                    continue;
                }

                int cost = 1;

                if (data[curX][curY] == 0 && dx[i] == -1 && dy[i] == 0) {
                    cost = 0;
                }
                if (data[curX][curY] == 1 && dx[i] == -1 && dy[i] == 1) {
                    cost = 0;
                }
                if (data[curX][curY] == 2 && dx[i] == 0 && dy[i] == 1) {
                    cost = 0;
                }
                if (data[curX][curY] == 3 && dx[i] == 1 && dy[i] == 1) {
                    cost = 0;
                }
                if (data[curX][curY] == 4 && dx[i] == 1 && dy[i] == 0) {
                    cost = 0;
                }
                if (data[curX][curY] == 5 && dx[i] == 1 && dy[i] == -1) {
                    cost = 0;
                }
                if (data[curX][curY] == 6 && dx[i] == 0 && dy[i] == -1) {
                    cost = 0;
                }
                if (data[curX][curY] == 7 && dx[i] == -1 && dy[i] == -1) {
                    cost = 0;
                }


                if (distance[curX][curY] + cost < distance[nextX][nextY]) {
                    distance[nextX][nextY] = distance[curX][curY] + cost;
                    pq.push({-distance[nextX][nextY], {nextX, nextY}});
                }
            }
        }
        
        cout << distance[x2][y2] << endl;
    
    }

    
    return 0;
}
