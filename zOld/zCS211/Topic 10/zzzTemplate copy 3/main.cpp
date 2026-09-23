#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<long long> e(n+1);
    vector<int> indeg(n+1, 0);
    vector<vector<int>> children(n+1); // edges: i -> child (child depends on i)
    
    for(int i = 1; i <= n; i++){
        int d;
        cin >> e[i] >> d;
        for(int j = 0; j < d; j++){
            int b; cin >> b;
            children[b].push_back(i);
            indeg[i]++;
        }
    }
    
    // Check if we can achieve max meeting length <= T
    // Meeting i at position k (0-indexed) costs e[i] + k
    // So we need k <= T - e[i], i.e., deadline D[i] = T - e[i]
    // Greedy: EDF (earliest deadline first) among available nodes
    auto check = [&](long long T) -> bool {
        // priority queue: (deadline, node), min-heap
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        vector<int> cur_indeg(indeg.begin(), indeg.end());
        
        for(int i = 1; i <= n; i++){
            long long D = T - e[i];
            if(D < 0) return false;
            if(cur_indeg[i] == 0){
                pq.push({D, i});
            }
        }
        
        int pos = 0; // current meeting index (0-based)
        int scheduled = 0;
        
        while(!pq.empty()){
            auto [D, u] = pq.top(); pq.pop();
            if(pos > D) return false;
            pos++;
            scheduled++;
            for(int v : children[u]){
                cur_indeg[v]--;
                if(cur_indeg[v] == 0){
                    long long Dv = T - e[v];
                    if(Dv < 0) return false;
                    pq.push({Dv, v});
                }
            }
        }
        return scheduled == n;
    };
    
    // Binary search on T
    // Lower bound: max(e[i]) (best case, topic is first)
    // Upper bound: max(e[i]) + n - 1 (worst case, topic is last)
    long long lo = 0, hi = 0;
    for(int i = 1; i <= n; i++) hi = max(hi, e[i]);
    hi += n - 1;
    lo = hi - (n - 1); // could start lower, but let's be safe
    lo = 0;
    
    while(lo < hi){
        long long mid = (lo + hi) / 2;
        if(check(mid)) hi = mid;
        else lo = mid + 1;
    }
    
    cout << lo << "\n";
    return 0;
}