/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Can you divide two teams?
void dfs(int src, vector<vector<int>> &adjList, vector<bool> &visited, vector<int> &colors, bool &poss, int c) {
    visited[src] = true;
    if (colors[src] == -1)
        colors[src] = c;

    for (auto nbr : adjList[src]) {
        if (colors[src] == colors[nbr]) {
            poss = false;
            // return;
        }

        if (visited[nbr] == false) {
            dfs(nbr, adjList, visited, colors, poss, 1 - c);
        }
    }

    return;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    int n = A;
    // int mod = 1e9 + 7;

    vector<vector<int>> adjList(n);
    for (auto e : B) {
        adjList[e[0] - 1].push_back(e[1] - 1);
        adjList[e[1] - 1].push_back(e[0] - 1);
    }

    // Bipartite check kr lenge ab bss
    // 2 coloring problem krenge in the graph
    vector<int> colors(A, -1); // -1, no color assigned, 0 and 1 are colors
    vector<bool> visited(A, false);

    bool possible = true;

    for (int i = 0; i < n; i++) {
        if (visited[i] == false)
            dfs(i, adjList, visited, colors, possible, 0);
    }

    return possible;
}
