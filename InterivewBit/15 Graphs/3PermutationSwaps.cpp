/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Permutation Swaps
int find(int src, vector<int> &parent) {
    if (parent[src] == -1)
        return src;

    return parent[src] = find(parent[src], parent);
}


int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    int n = A.size();
    vector<int> parent(n + 1, -1);

    for (int i = 0; i < C.size(); i++) {
        int x = A[C[i][0] - 1];
        int y = A[C[i][1] - 1];

        // Find parent if, not equal then ek set m add kr do
        int a = find(x, parent);
        int b = find(y, parent);

        if (a != b)
            parent[b] = a;
    }

    for (int i = 0; i < n; i++) {
        if (A[i] != B[i]) {
            // If not equal then parent (same set) m atleast hona chaiye
            int a = find(A[i], parent);
            int b = find(B[i], parent);

            if (a != b) return 0;
        }
    }

    return 1;
}
