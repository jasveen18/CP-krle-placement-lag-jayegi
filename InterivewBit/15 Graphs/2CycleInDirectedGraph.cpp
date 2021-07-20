/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Cycle in directed graph
bool isCyclePresent(int src, vector<vector<int>> &adjList, vector<bool> &visited, vector<bool> &path) {
    visited[src] = true;
    path[src] = true;

    for (auto nbr : adjList[src]) {
        // Check if already visited
        if (path[nbr] == true)
            return true;

        if (visited[nbr] == false) {
            bool cycle = isCyclePresent(nbr, adjList, visited, path);
            if (cycle)
                return true;
        }
    }

    // Not found yet
    path[src] = false;
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    // Make adj list
    vector<vector<int>> adjList(A + 1);
    for (auto e : B)
        adjList[e[0]].push_back(e[1]);

    // Let's do a simple DFS and check
    vector<bool> visited(A + 1, false);
    vector<bool> path(A + 1, false);

    for (int i = 1; i <= A; i++) {
        if (visited[i] == false) {
            bool cycle = isCyclePresent(i, adjList, visited, path);
            if (cycle)
                return true;

            path.clear();
        }
    }

    return false;
}
