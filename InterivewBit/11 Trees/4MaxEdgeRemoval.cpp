/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Remove max edges such that every component has even number of edges
int dfs(vector<vector<int>> &adjList, int src, vector<bool> &visited, int &res) {
    visited[src] = true;
    int currComp = 0;

    for (auto nbr : adjList[src]) {
        if (visited[nbr] == false) {
            int nbrComp = dfs(adjList, nbr, visited, res);

            if (nbrComp % 2 == 0) // If even number hai toh edge burn kro and increment count
                res++;
            else
                currComp += nbrComp; // Else count pe add kr do
        }
    }

    return currComp + 1; // +1 kyunki ye node included
}

int Solution::solve(int A, vector<vector<int> > &B) {
    // Make adjList
    vector<vector<int>> adjList(A);
    for (auto edge : B) {
        adjList[edge[0] - 1].push_back(edge[1] - 1);
        adjList[edge[1] - 1].push_back(edge[0] - 1);
    }

    // Do DFS and keep track of number of nodes, even hota hai toh burn the edge
    vector<bool> visited(A, false);
    int res = 0;

    dfs(adjList, 0, visited, res);

    return res;
}
