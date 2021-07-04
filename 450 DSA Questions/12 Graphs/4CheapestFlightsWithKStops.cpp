/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Dijkstra with K stops.
#define tuple(int, int, int) ti
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    // Make adj list
    vector<pair<int, int>> adjList[n];
    for (int i = 0; i < flights.size(); i++)
        adjList[flights[i][0]].push_back({flights[i][1], flights[i][2]});

    // Data structure to store (weight so far, currnode, steps taken).
    priority_queue<ti, vector<ti>, greater<ti>> pq;

    // Push src data
    pq.emplace(0, src, 0);

    while (!pq.empty()) {
        // Take out the nearest node
        auto [cost, currNode, steps] = pq.top(); pq.pop();

        if (currNode == dst)
            return cost;

        // If this is the case then it won't contribute
        if (steps > k)
            continue;

        // Push its neighbors
        for (auto nbr : adjList[currNode]) {
            pq.emplace(cost + nbr.second, nbr.first, steps + 1);
        }
    }

    return -1;
}