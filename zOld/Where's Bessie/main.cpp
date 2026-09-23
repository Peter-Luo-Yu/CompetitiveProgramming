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

int n;
int ccidx = 1;
vector<vector<int>> CC;

void dfs (int r, int c, char letter, vector<vector<char>> &data, vector<vector<bool>> &vis, int x1, int x2, int y1, int y2) {
    if (r >= x2 || c >= y2 || r < x1 || c < y1 || data[r][c] != letter || vis[r][c]) {
        return;
    }

    vis[r][c] = true;
    CC[r][c] = ccidx;

    dfs (r + 1, c, letter, data, vis, x1 , x2, y1, y2);
    dfs (r - 1, c, letter, data, vis, x1 , x2, y1, y2);
    dfs (r, c + 1, letter, data, vis, x1 , x2, y1, y2);
    dfs (r, c - 1, letter, data, vis, x1 , x2, y1, y2);
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);

    cin >> n;
    vector<vector<char>> data (n, vector<char> (n));
    
    vector<vector<int>> coords;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> data[i][j];
        }
    }

    int ans = 0;
    for (int x1 = 0; x1 < n; x1++) {
        for (int x2 = x1 + 1; x2 <= n; x2++) {
            for (int y1 = 0; y1 < n; y1++) {
                for (int y2 = y1 + 1; y2 <= n; y2++) {

                    set<char> colors;

                    for (int i = x1; i < x2; i++) {
                        for (int j = y1; j < y2; j++) {
                            //cout << data[i][j] << " ";
                            colors.insert(data[i][j]);
                        }
                        //cout << endl;
                    }
                    //cout << endl;
                    
                    //cout << colors.size() << endl;

                    if (colors.size() == 2) {
                        char one = '-', two = '-';

                        for (int i = x1; i < x2; i++) {
                            for (int j = y1; j < y2; j++) {
                                if (one == '-') {
                                    one = data[i][j];
                                }
                                else if (data[i][j] != one) {
                                    two = data[i][j];
                                }
                            }
                        }

                        //cout << one << " " << two << endl;

                        int oneComp = 0, twoComp = 0;

                        vector<vector<bool>> vis (n, vector<bool> (n));
                        CC = vector<vector<int>> (n, vector<int> (n));
                        ccidx = 1;

                        for (int i = x1; i < x2; i++) {
                            for (int j = y1; j < y2; j++) {
                                if (vis[i][j]) {
                                    continue;
                                }
                                if (data[i][j] != one) {
                                    vis[i][j] = true;
                                }
                                else {
                                    dfs (i, j, one, data, vis, x1, x2, y1, y2);
                                    ccidx++;
                                }
                            }
                        }

                        //print2d(CC);

                        set<int> cnt;

                        for (int i = x1; i < x2; i++) {
                            for (int j = y1; j < y2; j++) {
                                cnt.insert(CC[i][j]);
                            }
                        }
                        
                        oneComp = (cnt.size() - 1);


                        // do the same for second color
                        vis = vector<vector<bool>> (n, vector<bool> (n));
                        CC = vector<vector<int>> (n, vector<int> (n));
                        ccidx = 1;

                        for (int i = x1; i < x2; i++) {
                            for (int j = y1; j < y2; j++) {
                                if (vis[i][j]) {
                                    continue;
                                }
                                if (data[i][j] != two) {
                                    vis[i][j] = true;
                                }
                                else {
                                    dfs (i, j, two, data, vis, x1, x2, y1, y2);
                                    ccidx++;
                                }
                            }
                        }

                        //space; print2d(CC); 

                        cnt = set<int> ();

                        for (int i = x1; i < x2; i++) {
                            for (int j = y1; j < y2; j++) {
                                cnt.insert(CC[i][j]);
                            }
                        }
                        
                        twoComp = (cnt.size() - 1);

                        //cout << "color1: " << oneComp << " color2: " << twoComp << endl;

                        if ((oneComp == 1 && twoComp >= 2) || (twoComp == 1 && oneComp >= 2)) {
                            coords.push_back({x1, x2, y1, y2});
                        }

                    }
                    //cout << "==============" << endl;
                }
            }
        }
    }

    //print2d(coords);

    vector<bool> marked (coords.size());

    for (int i = 0; i < coords.size(); i++) {
        int curX1 = coords[i][0], curX2 = coords[i][1], curY1 = coords[i][2], curY2 = coords[i][3];
        for (int j = 0; j < coords.size(); j++) {
            if (i == j) continue;

            int oX1 = coords[j][0], oX2 = coords[j][1], oY1 = coords[j][2], oY2 = coords[j][3];

            if ((oX1 <= curX1 && curX2 <= oX2) && (oY1 <= curY1 && curY2 <= oY2)) {
                marked[i] = true;
            }
        }
    }

    for (int i = 0; i < marked.size(); i++) {
        if (!marked[i]) ans++;
    }

    
    cout << ans << endl;
    
    return 0;
}
