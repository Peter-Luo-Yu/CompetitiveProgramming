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

    string s; cin >> s;
    int n; cin >> n;
    vector<pair<string, string>> arr (n);

    for (int i = 0; i < n; i++) {
        string temp; cin >> temp;

        int idx = temp.find('=');

        arr[i].first = temp.substr(0, idx);
        arr[i].second = temp.substr(idx + 1);
    }


    int ops = 0;
    
    while (ops <= 5000) {
        bool found = false;

        string a; string b; int idx;

        //cout << "s: " << s << endl;
    
        for (int i = 0; i < arr.size(); i++) {
            
            a = arr[i].first;
            b = arr[i].second;

            if (a.size() > s.size()) {
                continue;
            }

            //cout << "before: " << s << " " << a << " " << b << endl;

            for (int j = 0; j <= s.size() - a.size(); j++) {

                string sub = s.substr(j, a.size());

                //cout << "sub: " << sub << endl;
                if (sub == a) {
                    found = true;
                    idx = j;

                    //cout << "found: " << sub << " at: " << idx << endl;
                    break;
                }
            }
            if (found) {
                break;
            }
        }

        if (found) {
            s = s.substr(0, idx) + b + s.substr(idx + a.size());
            ops++;
            if (s.size() > 255) {
                break;
            }
            //cout << s << " ops: " << ops << endl;
        } else {
            break;
        }
    }

    if (ops > 5000) {
        cout << "Time Limit Exceeded" << endl;
    } else if (s.size() > 255) {
        cout << "Memory Limit Exceeded" << endl;
    } 
    else {
        cout << s << endl; 
        //cout << ops << endl;
    }
    
    
    
    return 0;
}
