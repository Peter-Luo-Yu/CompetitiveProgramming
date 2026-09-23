#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct NodeInfo {
    vector<int> top_diffs;
    ll total_enjoyment;
};

struct Candidate {
    int difficulty;
    ll enjoyment;

    bool operator<(const Candidate& other) const {
        if (difficulty != other.difficulty)
            return difficulty < other.difficulty;
        return enjoyment < other.enjoyment;
    }
};

int main() {
    // Optimize I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    // We use a flat structure because p_i < i ensures 
    // we can process nodes in increasing order.
    vector<NodeInfo> nodes(n + 1);
    nodes[1].total_enjoyment = 0;
    // top_diffs remains empty for node 1 (no incoming edge)

    for (int i = 2; i <= n; ++i) {
        int p, d, e;
        cin >> p >> d >> e;

        nodes[i].total_enjoyment = nodes[p].total_enjoyment + e;
        
        // Inherit parent's top difficulties and add current edge
        nodes[i].top_diffs = nodes[p].top_diffs;
        nodes[i].top_diffs.push_back(d);
        
        // Keep only the top 11, sorted descending
        sort(nodes[i].top_diffs.rbegin(), nodes[i].top_diffs.rend());
        if (nodes[i].top_diffs.size() > 11) {
            nodes[i].top_diffs.resize(11);
        }
    }

    // Create 11 lists, one for each possible courage level c (0 to 10)
    vector<vector<Candidate>> lists(11);
    for (int i = 1; i <= n; ++i) {
        for (int c = 0; c <= 10; ++c) {
            // The (c+1)-th largest difficulty determines the skill s needed.
            // If the path has fewer than c+1 edges, required skill is 0.
            int req_skill = (c < (int)nodes[i].top_diffs.size()) ? nodes[i].top_diffs[c] : 0;
            lists[c].push_back({req_skill, nodes[i].total_enjoyment});
        }
    }

    // Sort each list and compute prefix maximums
    for (int c = 0; c <= 10; ++c) {
        sort(lists[c].begin(), lists[c].end());
        for (int i = 1; i < (int)lists[c].size(); ++i) {
            lists[c][i].enjoyment = max(lists[c][i].enjoyment, lists[c][i-1].enjoyment);
        }
    }

    int m;
    cin >> m;
    while (m--) {
        int s, c;
        cin >> s >> c;

        // Binary search for the maximum enjoyment where difficulty <= s
        // upper_bound finds the first element > s, so we take the one before it.
        auto it = upper_bound(lists[c].begin(), lists[c].end(), Candidate{s, (ll)2e18});
        
        if (it == lists[c].begin()) {
            cout << 0 << "\n";
        } else {
            cout << prev(it)->enjoyment << "\n";
        }
    }

    return 0;
}