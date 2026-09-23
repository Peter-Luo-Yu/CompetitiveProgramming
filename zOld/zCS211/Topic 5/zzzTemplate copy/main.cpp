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

    string s = "sup";

    ld ascend = -1, descend = -1;
    ld temp = 0;
    ld height = 0, maxTime = 0;
    vector<pair<int, int>> up;
    vector<pair<int, int>> down;

    while (!s.empty()) {
        getline (cin, s);
        if (s.empty()) {
            break;
        }
        //cout << s << endl;
        int a, b;
        int idx = s.find(" ");
        //cout << "idx: " << idx << endl;
        a = stoi(s.substr(0, idx));   
        b = stoi(s.substr(idx + 1));

        //cout << a << " " << b << endl;

        if (ascend == -1) {
            ascend = a;
            descend = b;
            continue;
        }
        if (temp < ascend) {
            up.push_back({a, b});
            temp++;
            height += a;
            maxTime += b;
        } else {
            down.push_back({a, b});
        }
    }

    //cout << "ascend: " << ascend << " h: " << height << " t: " << maxTime << endl;
    //printP(up); cout << "---" << endl; printP(down);


    ld l = 0, r = maxTime;
    ld ans = -1;
    while (r - l > 1e-6) {
        ld mid = (r + l) / (ld) 2;     // cur time

        ld posUp = 0, posDown = height;
        ld Tleft = mid;

        // simulate climb
        for (int i = 0; i < up.size(); i++) {
            if (up[i].second <= Tleft) {
                posUp += up[i].first;
                Tleft -= up[i].second; 
            } else {
                posUp += Tleft * ((ld) up[i].first / (ld) up[i].second);
                break;
            }
        }

        // simulate descent
        Tleft = mid;
        for (int i = 0; i < down.size(); i++) {
            if (down[i].second <= Tleft) {
                posDown -= down[i].first;
                Tleft -= down[i].second; 
            } else {
                posDown -= Tleft * ((ld) down[i].first / (ld) down[i].second);
                break;
            }
        }
        
        //cout << "l: " << l << " r: " << r << " "; 
        //cout << "t: " << mid << " up: " << posUp << " down: " << posDown << endl;

        if (posUp < posDown) {
            ans = mid;
            l = mid;
           
        } else {
            r = mid;
        }
         
    }
    
    cout << setprecision (7) << ans << endl;
    
    return 0;
}
