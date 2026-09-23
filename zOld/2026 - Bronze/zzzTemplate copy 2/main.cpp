#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(adj) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}


// poss: 1 = M, 0 = O;
int n;
vector<int> poss; 
vector<int> freq1;
vector<vector<vector<int>>> pairs;


vector<int> scores;

void recurse () {
    if (poss.size() == n) {
        //print(poss);

        int score = 0;
        for (int i = 0; i < poss.size(); i++) { // found M
            if (poss[i] == 1) {   
                for (int j = 0; j < poss.size(); j++) {
                    if (i == j) continue;

                    if (poss[j] == 0) {
                        for (int k = j + 1; k < poss.size(); k++) {
                            if (poss[k] == 0) {
                                score += pairs[i][j][k];
                                score += pairs[i][k][j];

                            }
                        }
                    }
                }

            } 
        }

        scores.push_back(score);
        //cout << "score: " << score << " | "; print(poss);
        
    
        return;
    }

    for (int i = 0; i < 2; i++) {
        poss.push_back(i);
        recurse ();
        poss.pop_back();
    }


}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int k; cin >> n >> k;

    freq1 = vector<int> (n);    
    pairs = vector<vector<vector<int>>> (n, vector<vector<int>> (n, vector<int> (n)));

    for (int i = 0; i < k; i++) {
        int x, y, z; cin >> x >> y >> z;
        x--, y--,z--;
        freq1[x]++;

        pairs[x][y][z]++;
    }

    /*
    print(freq1); cout << endl; 
    for (int i = 0; i < pairs.size(); i++) {
        cout << "i: " << i << endl;
        for (int j = 0; j < pairs[i].size(); j++) {
            for (int k = 0; k < pairs[i][j].size(); k++) {
                cout << pairs[i][j][k] << " ";
            } cout << endl;
        } cout << endl;
    }
    */

    recurse();

    int Max = 0;
    vector<int> freq (n + 1, 0); 
    for (int i = 0; i < scores.size(); i++) {
        freq[scores[i]]++;
        Max = max (scores[i], Max);
    }


    cout << Max << " " << freq[Max] << endl;

    return 0;
}