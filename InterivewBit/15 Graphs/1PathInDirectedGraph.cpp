/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - If node 1 to node A path possible.
void dfs(int src, vector<vector<int>> &adjList, vector<bool> &visited) {
    visited[src] = true;

    for (auto nbr : adjList[src]) {
        if (visited[nbr] == false)
            dfs(nbr, adjList, visited);
    }

    return;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    // Make adj list
    vector<vector<int>> adjList(A + 1);
    for (auto e : B)
        adjList[e[0]].push_back(e[1]);

    // Let's do a simple DFS and check
    vector<bool> visited(A + 1, false);
    dfs(1, adjList, visited);

    return visited[A];
}
