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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;
    while (t--)  {
        int a, b, c; cin >> a >> b >> c;

        vector<pair<int, char>> temp = {{a, 'R'}, {b, 'G'}, {c, 'B'}};
        sort (temp.begin(), temp.end());
        reverse (temp.begin(), temp.end());

        //printP(temp);

        pair<int, char> R = {temp[0].first, temp[0].second};
        pair<int, char> G = {temp[1].first, temp[1].second};
        pair<int, char> B = {temp[2].first, temp[2].second};
        
        if (R.first > G.first + B.first + 1) {
            R.first = G.first + B.first + 1;
        }

        int bg_block = B.first;
        int g_block = G.first - B.first;

        //cout << "bg: " << bg_block << " g: " << g_block << endl;
       

        string s1 = "";
        // we first pad the G block, GRGRGRGR...
        for (int i = 0; i < g_block; i++) {
            s1 += G.second; G.first--;
            s1 += R.second; R.first--;
        }

        //cout << s1 << endl;

        // only after padding the first block, you check if there is an odd number of R's
        bool add_r_at_start = false;
        if (R.first % 2 == 1) {
            add_r_at_start = true; R.first--;
        }


        string s2 = "";
        // now there's an even number of R's to put into the second block BRGR BRGR GB GB GB

        for (int i = 0; i < bg_block; i++) {
            if (R.first > 0) { 
                s2 += B.second; B.first--;
                s2 += R.second; R.first--;
                s2 += G.second; G.first--;
                s2 += R.second; R.first--;
            } else {
                s2 += G.second; G.first--;        
                s2 += B.second; B.first--;
            }
        }

        //cout << s2 << endl;

        if (add_r_at_start == true) {
            s1 = R.second + s1;
        }

        cout << s1 << s2 << endl;



        //space;
       
    }
    
    
    return 0;
}