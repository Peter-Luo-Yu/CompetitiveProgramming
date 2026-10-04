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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;

    vector<int> rows, cols; // let rows be odds and cols be evens
    for (int i = 1; i <= m; i += 2) {
        rows.push_back(i);
    }
    for (int i = 2; i <= m; i += 2) {
        cols.push_back(i);
    }

    int R = rows.size(), C = cols.size();
    vector<int> Rcap (R), Ccap (C);
    for (int i = 0; i < R; i++) {
        Rcap[i] = min (rows[i], C);
    }
    for (int i = 0; i < C; i++) {
        Ccap[i] = min (cols[i], R);
    }
    
    sort (Rcap.begin(), Rcap.end(), greater<int> ());
    sort (Ccap.begin(), Ccap.end(), greater<int> ());
    
    //print(Rcap); print(Ccap); space;


    // we do priority queue on the rows {capacity, index}
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < Rcap.size(); i++) {
        pq.push({Rcap[i], i});
    }

    vector<pair<int, int>> intersect;
    for (int i = 0; i < Ccap.size(); i++) {
        int col = Ccap[i];

        vector<pair<int, int>> r; // we match col[i] to these rows

        for (int j = 0; j < col; j++) {
            if (pq.empty()) break;
            if (pq.top().first == 0) {
                pq.pop();
                j--;
            } 
            else {
                r.push_back(pq.top()); 
                pq.pop();
            }
        }

        for (int j = 0; j < r.size(); j++) {
            r[j].first--;
            pq.push(r[j]);
            intersect.push_back({i, r[j].second}); // {col idx, row idx}
        }
    }

    //printP(intersect); space;

    vector<int> Rremain, Cremain;
    Rremain = rows; Cremain = cols;
    sort (Rremain.begin(), Rremain.end(), greater<int>());
    sort (Cremain.begin(), Cremain.end(), greater<int>());

    for (auto i : intersect) {
        Cremain[i.first]--;
        Rremain[i.second]--;
    }

    print(Rremain); print(Cremain); space;

    // cols add upwards, rows add to the right
    vector<pair<int, int>> rest;
    
    for (int i = 0; i < Rremain.size(); i++) {
        int x = m;
        for (int j = 0; j < Rremain[i]; j++) {
            rest.push_back({x, i});
            x++;
        }
    }

    for (int i = 0; i < Cremain.size(); i++) {
        int y = m;
        for (int j = 0; j < Cremain[i]; j++) {
            rest.push_back({i, y});
            y++;
        }
    }

    //printP(rest);

    int Min = intersect.size() + rest.size();

    if (n < Min) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (auto point : intersect) {
            cout << point.first << " " << point.second << endl;
        }
        for (auto point : rest) {
            cout << point.first << " " << point.second << endl;
        }

        int x = 2 * m, y = 2 * m;
        /*
        for (int i = 0; i < n - Min; i++) {
            cout << x << " " << y << endl;
            x++, y++;
        }
            */
    }


    
    return 0;
}
