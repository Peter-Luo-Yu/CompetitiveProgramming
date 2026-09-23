#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int N, Q; cin >> N >> Q;

    vector<int> h (N+1), g (N+1), j(N+1);

    int h_prefix = 0, g_prefix = 0, j_prefix = 0;

    for (int i = 0; i < N; i++){
        int cow; cin >> cow;
        
        h[i+1] = h[i];
        g[i+1] = g[i];
        j[i+1] = j[i];

        if (cow == 1) {h[i+1]++;}
        if (cow == 2) {g[i+1]++;}
        if (cow == 3) {j[i+1]++;}
    }

    //print (h); print(g); print(j);

    while (Q--){
        int l, r; cin >> l >> r;

        cout << h[r] - h[l-1] << " ";
        cout << g[r] - g[l-1] << " ";
        cout << j[r] - j[l-1] << endl;

    }

    return 0;
}