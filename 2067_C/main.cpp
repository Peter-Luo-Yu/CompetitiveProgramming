#include <bits/stdc++.h>
using namespace std;

bool has7(long long x) {
    while (x) {
        if (x % 10 == 7) return true;
        x /= 10;
    }
    return false;
}

bool can(long long n, int ops) {
    long long m = n - ops;

    vector<int> d;
    while (m) {
        d.push_back(m % 10);
        m /= 10;
    }

    while (d.size() < 15) d.push_back(0);

    static bool dp[20][20][20][2];
    memset(dp, 0, sizeof(dp));

    dp[0][0][0][0] = true;

    for (int pos = 0; pos < 15; pos++) {
        for (int used = 0; used <= ops; used++) {
            for (int carry = 0; carry <= ops; carry++) {
                for (int ok = 0; ok < 2; ok++) {
                    if (!dp[pos][used][carry][ok]) continue;

                    for (int add = 0; used + add <= ops; add++) {

                        int val = d[pos] + carry + add;
                        int digit = val % 10;
                        int nc = val / 10;

                        int nok = ok || (digit == 7);

                        dp[pos + 1][used + add][nc][nok] = true;
                    }
                }
            }
        }
    }

    return dp[15][ops][0][1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    while (T--) {
        long long n;
        cin >> n;

        if (has7(n)) {
            cout << 0 << '\n';
            continue;
        }

        for (int ops = 1; ops <= 9; ops++) {
            if (can(n, ops)) {
                cout << ops << '\n';
                break;
            }
        }
    }
}