#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int N, K; cin >> N >> K;

    vector<int> prefix (N); // is really just the arr
    map<int, int> prefix_count;

    prefix_count[0] = N;

    while (K--){
        int l, r; cin >> l >> r;

        for (int i = l-1; i < r; i++){
            prefix[i]++;

            prefix_count[prefix[i]]++;
            prefix_count[prefix[i]-1]--;
        
        }
    }

    int count = 0;

    for (auto x : prefix_count){
        count += x.second;
        if (count > N/2){
            cout << x.first << endl;
            break;
        }
    }

    return 0;
}