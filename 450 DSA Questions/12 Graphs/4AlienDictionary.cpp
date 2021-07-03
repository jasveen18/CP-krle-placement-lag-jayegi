/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given some words and letters, find the sorted list of letters. (note this is not alphabetical, voi find krna hai);

// Approach -
// 1. Make a graph.
// 2. Each node ka child will be the one later.
// 3. Run a topological sort to find the ordering.

string findOrder(string dict[], int N, int K) {
    unordered_map<char, list<char>> adjList;
    unordered_map<char, int> inDegree;

    // Make the graph.
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < min(dict[i].size(), dict[i - 1].size()); j++) {
            if (dict[i][j] != dict[i - 1][j]) {
                adjList[dict[i - 1][j]].push_back(dict[i][j]);

                // Store the indegree too
                inDegree[dict[i][j]]++;

                break;
            }
        }
    }

    // Run the BFS algo with indegree wala concept.
    string res = "";
    unordered_map<char, bool> visited;
    queue<char> q;

    // Find the nodes with 0 indegree
    for (auto el : adjList) {
        if (inDegree[el.first] == 0)
            q.push(el.first);
    }

    while (!q.empty()) {
        char curr = q.front(); q.pop();
        res += curr;

        for (auto nbr : adjList[curr]) {
            inDegree[nbr]--;

            if (inDegree[nbr] == 0)
                q.push(nbr);
        }
    }

    return res;
}