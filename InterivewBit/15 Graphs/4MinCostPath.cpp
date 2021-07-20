/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement -You are given a AB character matrix named C. Every cell in C has a character U,R,L or D indicating up,right,left and down.

// Your target is to go from top left corner to the bottom right corner of the matrix.

// But there are some restrictions while moving along the matrix:

// If you follow what is written in the cell then you can move freely.
// But if you don't follow what is written in the cell then you have to pay 1 unit of cost.

#define pii pair<int, pair<int, int>>
int Solution::solve(int A, int B, vector<string> &C) {
    vector<vector<int>> distance(A, vector<int> (B, INT_MAX));
    distance[0][0] = 0;

    vector<int> delx{ -1, 1, 0, 0};
    vector<int> dely{0, 0, -1, 1};
    vector<char> direction{'U', 'D', 'L', 'R'};

    // {distance, {i, j}} // distance required to call less weighted node first
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    // Push source
    pq.push({0, {0, 0}});

    // Dijkstra Algo
    while (pq.empty() == false) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;

        pq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + delx[i];
            int ny = y + dely[i];

            int valid = (C[x][y] == direction[i]) ? 0 : 1;

            if (nx >= 0 and ny >= 0 and nx < A and ny < B and distance[nx][ny] > distance[x][y] + valid) {
                distance[nx][ny] = distance[x][y] + valid;
                pq.push({distance[nx][ny], {nx, ny}});
            }
        }
    }


    return distance[A - 1][B - 1];
}
