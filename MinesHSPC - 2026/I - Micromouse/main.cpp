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

    // left hand on the wall
    string response = "", moved = "";
    while (response != "failure") {
        cout << "move" << endl; cout.flush();
        cin >> response;
        if (response == "exit") {
            return 0;
        }
    }
    

    cout << "right" << endl; cout.flush();
    cin >> response;

    response = "";

    while (true) {
        // check if you can go left
        cout << "left" << endl; cout.flush();
        cin >> response;

        cout << "move" << endl; cout.flush();
        cin >> moved;

        if (moved == "exit") return 0;

        // turn right if failed
        while (moved != "success") {
            cout << "right" << endl; cout.flush();
            cin >> response;

            cout << "move" << endl; cout.flush();
            cin >> moved;

            if (moved == "exit") return 0;
 
        }

        response = "", moved = "";
    }


    return 0;
}
