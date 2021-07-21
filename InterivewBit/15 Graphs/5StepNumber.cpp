/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Print the step number in range [n to m]. step number -> 123, 545, 432 (difference between adjancent = 1)
void bfs(int n, int m, int num, vector<int> &res) {
    queue<int> q;
    q.push(num);

    while (q.empty() == false) {
        int stepNum = q.front(); q.pop();

        if (stepNum <= m and stepNum >= n)
            res.push_back(stepNum);

        if (num == 0 or stepNum > m)
            continue;

        int lastDigit = stepNum % 10;

        int peeche = stepNum * 10 + (lastDigit - 1);
        int aage = stepNum * 10 + (lastDigit + 1);

        if (lastDigit == 0)
            q.push(aage);

        else if (lastDigit == 9)
            q.push(peeche);

        else {
            q.push(peeche);
            q.push(aage);
        }
    }

    return;
}

vector<int> Solution::stepnum(int A, int B) {
    // Make the graph first
    vector<vector<int>> adjList(10);

    adjList[0].push_back(1);
    for (int i = 1; i < 9; i++) {
        adjList[i].push_back(i - 1);
        adjList[i].push_back(i + 1);
    }
    adjList[9].push_back(8);

    vector<int> res;

    // Run BFS for all the nodes from 0 to 9 and then check.
    for (int i = 0; i <= 9; i++)
        bfs(A, B, i, res);

    sort(res.begin(), res.end());
    return res;
}
