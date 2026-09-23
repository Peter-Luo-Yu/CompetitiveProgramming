#include <iostream>
#include <vector>

using namespace std;

void solve() {
    long long n, d;
    cin >> n >> d;

    vector<int> res;
    res.push_back(1);

    // Divisibility by 3
    // n! * d % 3 == 0? 
    // If n >= 3, n! is multiple of 3. If n=2, n!=2.
    if (n >= 3 || (d % 3 == 0)) {
        res.push_back(3);
    }

    // Divisibility by 5
    if (d == 5) {
        res.push_back(5);
    }

    // Divisibility by 7
    // 111,111 is divisible by 7. So if n! >= 6, it's divisible.
    // n! >= 6 happens when n >= 3.
    if (n >= 3 || (n == 2 && (d * 2) % 7 == 0) || (d % 7 == 0)) {
        res.push_back(7);
    }

    // Divisibility by 9
    // n! * d % 9 == 0?
    // n! contains 9 if n >= 6.
    // If n=3, n!=6, 6*d % 9 == 0? (if d is 3, 6, 9)
    // If n=4, n!=24, 24*d % 9 == 0? (if d is 3, 6, 9)
    // If n=5, n!=120, 120*d % 9 == 0? (if d is 3, 6, 9)
    bool div9 = false;
    if (n >= 6) div9 = true;
    else {
        long long fact = 1;
        for (int i = 1; i <= n; i++) fact *= i;
        if ((fact * d) % 9 == 0) div9 = true;
    }
    if (div9) res.push_back(9);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << (i == res.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}