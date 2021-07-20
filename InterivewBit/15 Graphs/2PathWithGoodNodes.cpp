/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given a tree with N nodes labelled from 1 to N.

// Each node is either good or bad denoted by binary array A of size N where if A[i] is 1 then ithnode is good else if A[i] is
// 0 then ith node is bad.

// Also the given tree is rooted at node 1 and you need to tell the number of root to leaf paths in the tree that contain not more than C good nodes.
void dfs(int src, vector<vector<int>> &adjList, vector<bool> &visited, vector<int> &good, int curr, int C, int &ans) {
    visited[src] = true;

    bool leaf = true;
    curr = curr + good[src];

    for (auto nbr : adjList[src]) {
        if (visited[nbr] == false) {
            dfs(nbr, adjList, visited, good, curr, C, ans);
            leaf = false;
        }
    }

    if (leaf) {
        if (curr <= C)
            ans++;
    }

    return;
}

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int n = A.size();
    // int mod = 1e9 + 7;

    vector<vector<int>> adjList(n);
    for (auto e : B) {
        adjList[e[0] - 1].push_back(e[1] - 1);
        adjList[e[1] - 1].push_back(e[0] - 1);
    }

    // DFS for the root node
    vector<bool> visited(n, false);
    visited[0] = true;

    int ans = 0;

    for (auto nbr : adjList[0]) {
        dfs(nbr, adjList, visited, A, A[0], C, ans);
    }

    return ans;
}
