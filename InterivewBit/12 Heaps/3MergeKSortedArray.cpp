/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Merge K sorted arrays
typedef pair<int, pair<int, int>> PII;
vector<int> Solution::solve(vector<vector<int> > &A) {
    vector<int> res;
    priority_queue<PII, vector<PII>, greater<PII>> pq;

    int n = A.size();
    int m = A[0].size();

    for (int i = 0; i < n; i++)
        pq.push({A[i][0], {i, 0}});

    while (pq.empty() == false) {
        int topKey = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        res.push_back(topKey);
        if (y + 1 < m) {
            pq.push({A[x][y + 1], {x, y + 1}});
        }
    }

    return res;
}
