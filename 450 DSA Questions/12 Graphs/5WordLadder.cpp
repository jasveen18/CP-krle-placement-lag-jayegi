/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find min steps to reach begin word to end word

unordered_map<string, vector<string>> adjList;

// Check if valid edge and then add into the graph
void addEdge(string x, string y) {
    int differences = max(x.size() - y.size(), y.size() - x.size());

    for (int i = 0; i < min(x.size(), y.size()); i++)
        differences += (x[i] != y[i]) ? 1 : 0;

    if (differences == 1) {
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    return;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    // Check if end word present or not and add possible edges of begin word
    bool present = false;
    int n = wordList.size();

    for (int i = 0; i < n; i++) {
        if (endWord == wordList[i])
            present = true;

        addEdge(beginWord, wordList[i]);
    }

    if (present == false)
        return 0;

    // Make the whole graph
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            addEdge(wordList[i], wordList[j]);
        }
    }

    // Let's do BFS in the graph and find the shortest path
    int V = adjList.size();
    unordered_map<string, bool> visited;
    queue<pair<int, string>> q;

    q.push({1, beginWord});
    visited[beginWord] = true;

    while (!q.empty()) {
        string curr = q.front().second;
        int currSteps = q.front().first;
        q.pop();

        if (curr == endWord)
            return currSteps;

        // Traverse the neighbors
        for (auto nbr : adjList[curr]) {
            if (visited[nbr] == false) {
                q.push({currSteps + 1, nbr});
                visited[nbr] = true;
            }
        }
    }

    return 0;
}

