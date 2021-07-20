/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the largest distance between any two nodes of a tree.
int dfs(int src, vector<vector<int>> &adjList, vector<bool> &visited, int &res) {
    visited[src] = true;

    vector<int> depths;
    for (auto nbr : adjList[src]) {
        if (visited[nbr] == false) {
            int d = dfs(nbr, adjList, visited, res);
            depths.push_back(d);
        }
    }

    // If leaf
    if (depths.size() == 0) {
        res = max(res, 1);
        return 1;
    }

    if (depths.size() == 1) {
        res = max(res, depths[0] + 1);
        return depths[0] + 1;
    }

    // Else
    sort(depths.begin(), depths.end());
    int takeThisAsRoot = depths[depths.size() - 1] + depths[depths.size() - 2] + 1;
    res = max(res, takeThisAsRoot);

    return max(depths[depths.size() - 1] , depths[depths.size() - 2]) + 1;
}

int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> adjList(A.size());
    int root = -1;

    for (int i = 0; i < A.size(); i++) {
        if (A[i] == -1) {
            root = i;
            continue;
        }

        adjList[A[i]].push_back(i);
    }

    int res = 0;
    vector<bool> visited(n, false);

    dfs(root, adjList, visited, res);
    return res - 1;
}
