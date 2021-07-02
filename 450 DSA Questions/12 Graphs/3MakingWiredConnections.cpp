/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the number of connections required.
class Solution {
public:
    list<int> *l;
    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void markVisitedDFS(int src, vector<bool> &visited) {
        visited[src] = true;

        for (auto nbr : l[src]) {
            if (!visited[nbr])
                markVisitedDFS(nbr, visited);
        }

        return;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        // Not possible case -
        if (n - 1 > connections.size())
            return -1;

        // Solution is to find the number of components in the graph
        // Create a graph
        l = new list<int>[n];

        // Add edges
        for (int i = 0; i < connections.size(); i++) {
            addEdge(connections[i][0], connections[i][1]);
        }

        // Find the number of components using DFS
        int numComponents = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                markVisitedDFS(i, visited);
                numComponents++;
            }
        }

        return numComponents - 1;
    }
};