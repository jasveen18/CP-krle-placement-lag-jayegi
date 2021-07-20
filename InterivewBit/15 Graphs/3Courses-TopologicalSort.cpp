/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Topological Sort
int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    // Topological sorting kr dete hai.
    int n = B.size();

    if (n == 0)
        return 1;

    vector<vector<int>> adjList(A);
    vector<int> indegree(A, 0);

    for (int i = 0; i < n; i++) {
        adjList[B[i] - 1].push_back(C[i] - 1);
        indegree[C[i] - 1]++;
    }

    queue<int> q;
    for (int i = 0; i < A; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<bool> visited(A, false);

    while (q.empty() == false) {
        int currNode = q.front();
        q.pop();

        visited[currNode] = true;

        for (auto nbr : adjList[currNode]) {
            indegree[nbr]--;

            if (indegree[nbr] == 0) {
                q.push(nbr);
            }
        }
    }

    for (int i = 0; i < A; i++) {
        if (visited[i] == false)
            return false;
    }

    return true;
}
