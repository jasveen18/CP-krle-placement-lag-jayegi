/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Take only one edge from E and return the min cost path
typedef pair<int, int> pi;
int dijkstra(int src, int dest, int n, vector<vector<pi>> &adjList) {
    vector<int> dist(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);

    priority_queue<pi, vector<pi>, greater<pi>> minHeap;
    minHeap.push({0, src});
    dist[src] = 0;

    while (minHeap.empty() == false) {
        pi curr = minHeap.top(); minHeap.pop();
        int currNode = curr.second;

        if (visited[currNode] == true) continue;
        visited[currNode] = true;

        for (auto nbr : adjList[currNode]) {
            int v = nbr.first;
            int weight = nbr.second;

            if (dist[v] > dist[currNode] + weight) {
                dist[v] = dist[currNode] + weight;
                minHeap.push({dist[v], v});
            }

        }
    }

    return dist[dest];
}


int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {
    vector<vector<pi>> adjList(A + 1);
    for (auto v : B) {
        adjList[v[0]].push_back({v[1], v[2]});
    }

    int ans = INT_MAX;

    // Take one edge from E and then we can process using that
    for (auto v : E) {
        if (v[0] > A or v[1] > A) continue; // Some edges are greater then vertex

        // Push into adjList, E has undirected edges
        adjList[v[0]].push_back({v[1], v[2]});
        adjList[v[1]].push_back({v[0], v[2]});

        // Find min distrance by dij
        int singleAns = dijkstra(C, D, A, adjList);
        ans = min(ans, singleAns);

        // Remove the edge now
        adjList[v[0]].pop_back();
        adjList[v[1]].pop_back();
    }

    return ans == INT_MAX ? -1 : ans;
}
