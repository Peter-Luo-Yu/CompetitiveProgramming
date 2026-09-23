#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}
#define printP(arr) for (auto x : arr) cout << x.first << " " << x.second << "\n";

vector<string> perm;
vector<bool> chosen;
vector<string> names;
vector<pair<string, string>> like;

bool stop = false;

void recurse () {
    if (perm.size() == names.size()) {
        if (!stop) {
            print(perm);
            stop = true;
        } 
        return;
    }  
    else {
        if (stop) {
            return;
        }
        for (int i = 0; i < names.size(); i++) {
            if (chosen[i]) continue;

            if (perm.size() > 0) {
                bool failed = false;
                for (int j = 0; j < like.size(); j++) { // 
                    if (like[j].first == perm[perm.size() - 1] && like[j].second == names[i]) {
                        failed = true;
                    }
                    if (like[j].second == perm[perm.size() - 1] && like[j].first == names[i]) {
                        failed = true;
                    }
                }

                if (failed) continue;
            }
            chosen[i] = true;           
            perm.push_back(names[i]);   // add it
            recurse ();                 // keep adding
            chosen[i] = false;          
            perm.pop_back();            // remove it
        }

    }
    

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s = "start"; 
    while (s != "") {
        getline(cin, s);

        if (s == "") {
            break;
        }

        chosen = vector<bool> (stoi(s));

        string temp;
        
        for (int i = 0; i < stoi(s); i++) {
            getline(cin, temp);
            names.push_back(temp);
        }

        getline(cin, s);
        for (int i = 0; i < stoi(s); i++) {
            getline(cin, temp);
            //cout << temp << endl;
            
            int idx = temp.find(" ");
            
            like.push_back({temp.substr(0, idx), temp.substr(idx + 1)});
        }

       
        sort (names.begin(), names.end());

        //print(names);
        //printP(like);

        recurse ();
        
        if (!stop) {
            cout << "You all need therapy." << endl;
        }

        names = vector<string> ();
        like = vector<pair<string, string>> ();

        stop = false;

    }
     

    return 0;
}