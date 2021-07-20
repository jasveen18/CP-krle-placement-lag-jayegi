/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Detect cycle in undirected graph
bool dfsCycle(int src, vector<vector<int>>&adjList, vector<bool> &visited, int parent) {
    visited[src] = true;

    for (auto nbr : adjList[src]) {
        if (visited[nbr] == false) {
            bool cycle = dfsCycle(nbr, adjList, visited, src);

            if (cycle)
                return true;
        }
        // If already visited hai and parent bhi ni hai
        else if (visited[nbr] == true and nbr != parent)
            return true;
    }

    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    int n = A;
    // int mod = 1e9 + 7;

    vector<vector<int>> adjList(n);
    for (auto e : B) {
        adjList[e[0] - 1].push_back(e[1] - 1);
        adjList[e[1] - 1].push_back(e[0] - 1);
    }

    vector<bool> visited(n, false);
    int parent = -1;

    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            parent = -1;
            bool cycle = dfsCycle(i, adjList, visited, parent);

            if (cycle)
                return true;
        }
    }

    return false;
}
