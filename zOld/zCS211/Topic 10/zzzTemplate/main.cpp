#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<string> grid;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool isLoop(int r, int c) {
    char ch = grid[r][c];
    return ch == 'X' || ch == 'A' || ch == 'B';
}

// Walk one loop starting from (sr,sc), going straight through intersections.
// Returns the ordered sequence of cells.
vector<pair<int,int>> walkLoop(
    int sr, int sc,
    const set<pair<int,int>>& intersectionCells,
    const map<pair<int,int>, vector<pair<int,int>>>& allNeighbors)
{
    vector<pair<int,int>> path;
    int cr = sr, cc = sc;
    int pr = -1, pc = -1;

    while (true) {
        path.push_back({cr, cc});
        const auto& nbrs = allNeighbors.at({cr, cc});
        int nr = -1, nc = -1;

        if (intersectionCells.count({cr, cc}) && pr != -1) {
            // Go straight through: continue in the same direction
            int dirR = cr - pr, dirC = cc - pc;
            nr = cr + dirR;
            nc = cc + dirC;
        } else {
            // Pick any neighbor that isn't where we came from
            for (auto [r2, c2] : nbrs) {
                if (r2 == pr && c2 == pc) continue;
                nr = r2; nc = c2;
                break;
            }
        }

        if (nr == -1) break;
        if (nr == sr && nc == sc) break;
        pr = cr; pc = cc;
        cr = nr; cc = nc;
    }
    return path;
}

// Build per-loop neighbor map from the ordered walk.
// Each cell maps to its two neighbors in THIS loop only.
map<pair<int,int>, vector<pair<int,int>>> buildNeighborMap(
    const vector<pair<int,int>>& path)
{
    map<pair<int,int>, vector<pair<int,int>>> nb;
    int n = path.size();
    for (int i = 0; i < n; i++) {
        auto cur  = path[i];
        auto prev = path[(i - 1 + n) % n];
        auto next = path[(i + 1) % n];
        nb[cur].push_back(prev);
        nb[cur].push_back(next);
    }
    return nb;
}

// Ray casting leftward from (r,c).
// Count crossings using the "count if hasUp" rule:
//   - vertical segment (up+down): 1 crossing
//   - corner turning up+horizontal: 1 crossing
//   - corner turning down+horizontal: 0 crossings
//   - pure horizontal: 0 crossings
bool insideLoop(
    int r, int c,
    const set<pair<int,int>>& loopCells,
    const map<pair<int,int>, vector<pair<int,int>>>& nb)
{
    int crossings = 0;
    for (int col = 0; col < c; col++) {
        if (!loopCells.count({r, col})) continue;
        const auto& nbrs = nb.at({r, col});
        bool hasUp = false;
        for (auto [nr2, nc2] : nbrs)
            if (nr2 == r - 1) { hasUp = true; break; }
        if (hasUp) crossings++;
    }
    return (crossings % 2) == 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> R >> C;
    grid.resize(R);
    for (int i = 0; i < R; i++) cin >> grid[i];

    // Find A and B positions
    int ar = -1, ac = -1, br = -1, bc = -1;
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++) {
            if (grid[r][c] == 'A') { ar = r; ac = c; }
            if (grid[r][c] == 'B') { br = r; bc = c; }
        }

    // Build allNeighbors: adjacency among loop cells
    map<pair<int,int>, vector<pair<int,int>>> allNeighbors;
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            if (isLoop(r, c))
                for (int d = 0; d < 4; d++) {
                    int r2 = r + dx[d], c2 = c + dy[d];
                    if (r2 >= 0 && r2 < R && c2 >= 0 && c2 < C && isLoop(r2, c2))
                        allNeighbors[{r,c}].push_back({r2,c2});
                }

    // Intersection cells have 4 loop-neighbors (both loops cross here)
    set<pair<int,int>> intersectionCells;
    for (auto& [pos, nbrs] : allNeighbors)
        if ((int)nbrs.size() == 4)
            intersectionCells.insert(pos);

    // Walk each loop and build its cell set + neighbor map
    auto pathA = walkLoop(ar, ac, intersectionCells, allNeighbors);
    auto pathB = walkLoop(br, bc, intersectionCells, allNeighbors);

    set<pair<int,int>> loopA(pathA.begin(), pathA.end());
    set<pair<int,int>> loopB(pathB.begin(), pathB.end());

    auto nbA = buildNeighborMap(pathA);
    auto nbB = buildNeighborMap(pathB);

    // Flood-fill all '.' regions
    vector<vector<int>> regionId(R, vector<int>(C, -1));
    int numRegions = 0;
    vector<int> regionSize;
    vector<pair<int,int>> rep;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (grid[r][c] != '.' || regionId[r][c] != -1) continue;

            queue<pair<int,int>> q;
            q.push({r, c});
            regionId[r][c] = numRegions;
            int sz = 0;
            rep.push_back({r, c});

            while (!q.empty()) {
                auto [cr, cc] = q.front(); q.pop();
                sz++;
                for (int d = 0; d < 4; d++) {
                    int r2 = cr + dx[d], c2 = cc + dy[d];
                    if (r2 < 0 || r2 >= R || c2 < 0 || c2 >= C) continue;
                    if (grid[r2][c2] == '.' && regionId[r2][c2] == -1) {
                        regionId[r2][c2] = numRegions;
                        q.push({r2, c2});
                    }
                }
            }
            regionSize.push_back(sz);
            numRegions++;
        }
    }

    // Classify each region by ray casting from its representative cell
    int areaA = 0, areaB = 0, areaAB = 0;
    for (int i = 0; i < numRegions; i++) {
        auto [r, c] = rep[i];
        bool inA = insideLoop(r, c, loopA, nbA);
        bool inB = insideLoop(r, c, loopB, nbB);
        if      (inA && inB)  areaAB += regionSize[i];
        else if (inA && !inB) areaA  += regionSize[i];
        else if (!inA && inB) areaB  += regionSize[i];
    }

    cout << areaA << " " << areaB << " " << areaAB << "\n";
    return 0;
}