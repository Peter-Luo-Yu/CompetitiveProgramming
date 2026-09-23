#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define print(arr) for (auto x : arr) cout << x << ' '; cout << '\n';

int main() {

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n; cin >> n;

    vector<int> hoof (n+1), paper (n+1), scissor (n+1);

    for (int i = 0; i < n; i++){
        hoof[i+1] = hoof[i];
        paper[i+1] = paper[i];
        scissor[i+1] = scissor[i];

        char val; cin >> val;

        if (val == 'H'){
            hoof[i+1]++;
        }
        if (val == 'P'){
            paper[i+1]++;
        }
        if (val == 'S'){
            scissor[i+1]++;
        }
    }

    int max_wins = 0;

    for (int i = 0; i < n; i++){    // the breaking point is i;
        int first = max ({hoof[i+1], paper[i+1], scissor[i+1]});
        int second = max ({hoof[n] - hoof[i+1], paper[n] - paper[i+1], scissor[n] - scissor[i+1]});

        max_wins = max (max_wins, first + second);
    }
    cout << max_wins << endl;

    return 0;
}