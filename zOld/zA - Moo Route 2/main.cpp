#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

// Using a tuple to represent (departure, destination, arrival)
typedef tuple<long long, int, long long> Flight;

int main() {
    // Fast I/O for 200,000 constraints
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    const long long INFTY = 1e18 + 7; // Use a larger infinity for 10^9 times

    // flights_base storage
    vector<vector<Flight>> flights(N + 1);
    for (int i = 0; i < M; i++) {
        int c, d;
        long long r, s;
        cin >> c >> r >> d >> s;
        // We will adjust departure times by layovers in the next step
        flights[c].push_back({r, d, s});
    }

    vector<long long> layovers(N + 1);
    for (int i = 1; i <= N; i++) cin >> layovers[i];

    // Ignore layovers at airport 1 as per logic
    layovers[1] = 0;

    // Adjust flights and sort descending
    for (int c = 1; c <= N; c++) {
        for (auto& f : flights[c]) {
            get<0>(f) -= layovers[c]; // Adjust departure: r - layover
        }
        // Sort DESCENDING by departure time (first element of tuple)
        sort(flights[c].begin(), flights[c].end(), [](const Flight& a, const Flight& b) {
            return get<0>(a) > get<0>(b);
        });
    }

    vector<long long> time_reached(N + 1, INFTY);
    time_reached[1] = 0;

    // idx[d] tracks how many flights from airport d have been added to the queue
    vector<int> idx(N + 1, 0);

    // Queue of flights to process: (r, d, s)
    vector<Flight> q;
    
    // Initial: add all flights departing from airport 1
    // In the Python logic, since time[1]=0, any flight from 1 (r >= 0) is valid.
    for (const auto& f : flights[1]) {
        q.push_back(f);
        idx[1]++;
    }

    int qid = 0;
    while (qid < q.size()) {
        Flight current = q[qid++];
        long long r = get<0>(current);
        int d = get<1>(current);
        long long s = get<2>(current);

        // Relax the arrival time at destination airport
        if (s < time_reached[d]) {
            time_reached[d] = s;
        }

        // Check if this arrival unlocks new flights at airport d
        // While the next available flight's departure (adjusted) >= our arrival time s
        while (idx[d] < (int)flights[d].size() && get<0>(flights[d][idx[d]]) >= s) {
            q.push_back(flights[d][idx[d]]);
            idx[d]++;
        }
    }

    // Output formatting
    for (int i = 1; i <= N; i++) {
        if (time_reached[i] != INFTY) {
            cout << time_reached[i] << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}