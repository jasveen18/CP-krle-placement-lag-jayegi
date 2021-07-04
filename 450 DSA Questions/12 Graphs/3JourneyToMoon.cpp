/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Just find the number of components.
long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    // Make the adj list
    vector<int> adjList[n];
    for (int i = 0; i < astronaut.size(); i++) {
        adjList[astronaut[i][0]].push_back(astronaut[i][1]);
    }

    // Approach to find the number of components in the graph along with number in each comp.
    // DFS use kr lenge
    vector<int> res;
    vector<bool> vis(n, false);

    long long ans = (n);
    ans *= (n - 1);
    ans /= 2;

    for (int i = 0; i < n; i++) {
        int count = 0;
        if (vis[i] == false) {
            dfsKrdo(i, adjList, vis, count);
        }

        ans -= (((count) * (count - 1)) / 2);
    }

    return ans;
}