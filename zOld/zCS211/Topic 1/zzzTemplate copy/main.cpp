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

    string t;
    while (t != "0") {
        getline(cin, t);
        if (t == "0") break;
        //cout << t << endl;
        
        vector<string> orig;
        vector<int> hash;

        for (int i = 0; i < stoi(t); i++) {
            string s;
            getline(cin, s);
            //cout << s << endl;

            orig.push_back(s);
            int result = s[0];
            for (int j = 1; j < s.size(); j++) {
                result = result ^ s[j];
            }  
            hash.push_back(result);
        }

        //print(orig);
        //print(hash);
        int coll = 0;
        int uniq = 0;
        set<string> st;

        st.insert(orig[0]);
        for (int i = 0; i < hash.size() - 1; i++) {
            st.insert(orig[i+1]);
            for (int j = i + 1; j < hash.size(); j++) {
                if (hash[i] != hash[j]) {  // different hash = unique, overcount twice
                    uniq += 1;
                }
                else {  // same hash
                    if (orig[i] != orig[j]) {   // different string = collision, good
                        coll++;
                        uniq += 1;
                    } else {                    // same string
                        uniq -= 1;
                    }
                }
            }
        }
        

        cout << st.size() << " " << coll << endl;
    }
    

    return 0;
}