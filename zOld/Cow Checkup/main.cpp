#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';
#define print2d(arr) for (int i = 0; i < arr.size(); i++) {for (int j = 0; j < arr[i].size(); j++) {cout << arr[i][j] << " ";} cout << "\n";}
#define printG(arr) for (int i = 0; i < adj.size(); i++) {cout << "i: " << i << " | "; for (int j = 0; j < adj[i].size(); j++) {cout << adj[i][j] << " ";} cout << endl;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<int> a(N + 1), b(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) cin >> b[i];

    // match0[i] = 1 if a[i] == b[i]
    vector<int> match0(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        if (a[i] == b[i]) match0[i] = 1;
    }

    // Prefix sum of match0
    vector<int> pref0(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        pref0[i] = pref0[i - 1] + match0[i];
    }
    int total_match0 = pref0[N];

    // ans[c] = number of (l,r) giving exactly c checked cows
    vector<long long> ans(N + 1, 0);

    cout << "matches0: ";
    print(match0);
    cout << "pref0: ";
    print(pref0);
    cout << "----------" << endl;
    // Fix k = l + r
    for (int k = 2; k <= 2 * N; k++) {
        int L = max(1, k - N);
        int R = min(N, k - 1);

        // c[i] = 1 if a[k-i] == b[i]
        vector<int> c(N + 1, 0);
        for (int i = L; i <= R; i++) {
            if (a[k - i] == b[i]) c[i] = 1;
        }
        
        // prefix sum for c
        vector<int> prefC(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            prefC[i] = prefC[i - 1] + c[i];
        }
        cout << "BIG K: " << k << endl;
        cout << "L: " << L << " R: " << R << endl;
        cout << "c: "; print(c);
        cout << "prefC: "; print(prefC);
       
        // iterate valid l,r
        for (int l = L; l <= k / 2; l++) {
            int r = k - l;
            if (r > N) continue;

            int inside = prefC[r] - prefC[l - 1];
            int removed = pref0[r] - pref0[l - 1];
            int outside = total_match0 - removed;

            int checked = inside + outside;
            ans[checked]++;

            cout << "l: " << l << " r: " << r << " | inside: " << inside << " total: " << total_match0 << " removed: " << removed << " checked: " << checked << endl;
        } 

        cout << "----------" << endl;
    }

        

    // Output results for c = 0..N
    for (int c = 0; c <= N; c++) {
        cout << ans[c] << "\n";
    }

    return 0;
}
