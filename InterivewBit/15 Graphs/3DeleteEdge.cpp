/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Delete edge to maximize product of sum of node weight of 2 trees.
int mod = 1e9 + 7;
int dfs(int src, vector<vector<int>> &adjList, vector<bool> &visited, long long &res, int &sum, vector<int> &w) {
    visited[src] = true;

    long long sumHere = 0;
    for (auto nbr : adjList[src]) {
        if (visited[nbr] == false)
            sumHere += dfs(nbr, adjList, visited, res, sum, w);
    }

    sumHere += w[src];
    res = max(res, (long long)((sum - sumHere) * (sumHere)) % mod ) % mod;

    return sumHere;
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    int n = A.size();
    // int mod = 1e9 + 7;

    vector<vector<int>> adjList(n);
    for (auto e : B) {
        adjList[e[0] - 1].push_back(e[1] - 1);
        adjList[e[1] - 1].push_back(e[0] - 1);
    }

    int sumTotal = 0;
    for (auto el : A)
        sumTotal += el;

    // Now DFS to find the sum of sub-trees
    long long res = 0;
    vector<bool> visited(n, false);
    dfs(0, adjList, visited, res, sumTotal, A);

    return res % mod;
}
