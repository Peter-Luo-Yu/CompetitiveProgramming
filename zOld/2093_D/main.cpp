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

    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;

        while (q--) {
            string s; cin >> s;

            if (s == "->") {
                ll x, y; cin >> x >> y;

                ll l = 1, r = (1LL << n) * (1LL << n) + 1LL;
                ll centerX = (1 << n) / 2, centerY = (1 << n) / 2LL;

                ll step = (1LL << (n - 2));
                //cout << "step: " << step << endl;
                
                while (step >= 1) {
                    //cout << centerX << " " << centerY << " " << l << " " << r << endl;
                    ll fourth = (r - l) / 4LL;

                    if (x > centerX) {
                        if (y > centerY) { // 2
                            l += fourth;
                            r = l + fourth;

                            centerX += step;
                            centerY += step;
                        } else { // 3
                            l += 2 * fourth;
                            r = l + fourth;

                            centerX += step;
                            centerY -= step;
                        }
                    } else {
                        if (y > centerY) { // 4
                            l += 3 * fourth;
                            r = l + fourth;

                            centerX -= step;
                            centerY += step;

                        } else { // 1

                            l = l;
                            r = l + fourth;

                            centerX -= step;
                            centerY -= step;
                        }
                    }

                    step /= 2LL;
                }

                //cout << centerX << " " << centerY << " " << l << " " << r << endl;

                if (x == centerX && y == centerY) {
                    cout << l << endl;
                } 
                else if (x == centerX + 1 && y == centerY + 1) {
                    cout << l + 1 << endl;
                } 
                else if (x == centerX + 1 && y == centerY) {
                    cout << l + 2 << endl;
                } else {
                    cout << l + 3 << endl;
                }

            }
            else {
                ll d; cin >> d;

                ll l = 1, r = (1LL << n) * (1LL << n) + 1LL;
                
                ll centerX = (1LL << n) / 2LL, centerY = (1LL << n) / 2LL;
                ll step = (1LL << (n - 2));

                while (step >= 1) { 
                    ll fourth = (r - l) / 4LL;

                    if (l <= d && d < l + fourth) { // 1 is top left
                        centerX -= step;
                        centerY -= step;

                        l = l;
                        r = l + fourth;
                    }
                    else if (l + fourth <= d && d < l + 2 * fourth) { // 2 is bot right
                        centerX += step;
                        centerY += step;

                        l += fourth;
                        r = l + fourth;
                    }
                    else if (l + 2 * fourth <= d && d < l + 3 * fourth) { // 3 is bot left
                        centerX += step;
                        centerY -= step;

                        l += 2 * fourth;
                        r = l + fourth;
                    }
                    else { // 4 is top right
                        centerX -= step;
                        centerY += step;

                        l += 3 * fourth;
                        r = l + fourth;
                    }

                    step /= 2LL;
                }

                //cout << centerX << " " << centerY << " " << l << " " << r <<endl;

                if (l == d) {
                    // already corresponds to top left
                } 
                else if (l + 1 == d) {
                    centerX += 1;
                    centerY += 1;
                }
                else if (l + 2 == d) {
                    centerX += 1;
                } else {
                    centerY += 1;
                }

                cout << centerX << " " << centerY << endl;

            }

        }


        //space;
    }


    return 0;
}
