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

    string s, t; cin >> s >> t;

    map <char, vector<int>> mp1, mp2;

    for (int i = 0; i < s.size(); i++) {
        mp1[s[i]].push_back(i);
    }
    for (int i = 0; i < t.size(); i++) {
        mp2[t[i]].push_back(i);
    }

    /*
    for (auto x : mp1) {
        cout << x.first << " "; print(x.second);
    } */
    
    
    for (auto &x : mp2) {
        vector<int> temp = x.second;
        reverse(temp.begin(), temp.end());
        x.second = temp;
    }

    /*
    for (auto x : mp2) {
        cout << x.first << " "; print(x.second);
    } */
    
    if (s.size() < 2 || t.size() < 2) {
        cout << "-1" << endl;
        return 0;
    }

    int minLength = 1e9;
    string ans = "-1";


    for (int i = 'a'; i <= 'z'; i++) {
        char c = i;

        vector<int> pos1 = mp1[c];
        vector<int> pos2 = mp2[c];

        //cout << "letter: " << c << endl; print(pos1); print(pos2);

        if (pos1.size() == 0 || pos2.size() == 0) continue;

        int idxS = 0, idxT = 0;
        
        while (pos1[idxS] < 1) {
            idxS++;
        }
        while (pos2[idxT] > t.size() - 2) {
            idxT++;
        }

        if (idxS > pos1.size() - 1 || idxT > pos2.size() - 1) continue;
        

        //cout << idxS << " " << idxT << endl;

        int length = pos1[idxS] + t.size() - pos2[idxT];

        
        if (length < minLength) {
            minLength = length;
            ans = s.substr(0, pos1[idxS]) + t.substr(pos2[idxT]);
        }
    }   

    cout << ans << endl;
    



    

    return 0;
}