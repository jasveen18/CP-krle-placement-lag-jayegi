/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Min cost nodes to connect all.
class DSU {
    // DSU pe 2 methods hoga with optimization
    // Do attribute hoga
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int v) {
        parent = vector<int> (v + 1, -1);
        rank = vector<int> (v + 1, 0);
    }

    int findSet(int i) {
        if (parent[i] == -1)
            return i;

        return parent[i] = findSet(parent[i]);
    }

    bool unionSet(int u, int v) {
        int s1 = findSet(u);
        int s2 = findSet(v);

        if (s1 == s2)
            return true;

        // Rank se jodo
        if (rank[s1] < rank[s2]) {
            parent[s1] = s2;
            rank[s2] += rank[s1];
        } else {
            parent[s2] = s1;
            rank[s1] += rank[s2];
        }

        return false;
    }
};

int Solution::solve(int A, vector<vector<int> > &B) {
    // MST nikalna hai.
    // Kruskal kr lete hai

    // Sort by weight
    sort(B.begin(), B.end(), [](vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    });

    DSU d(A);
    int ans = 0;

    for (auto edge : B) {
        int u = edge[0], v = edge[1], wt = edge[2];

        // This means ki no node is present between these 2 nodes, then ye node lelo
        // Also, edges weight se sorted hai toh yahi best choice hai.
        if (d.findSet(u) != d.findSet(v)) {
            d.unionSet(u, v);

            ans += wt;
        }
    }

    return ans;
}
