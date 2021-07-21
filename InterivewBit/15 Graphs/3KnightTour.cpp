/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Min distance from src to dest
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    // BFS krte hai
    int n = A, m = B; // Dimension of board
    int xs = C - 1, ys = D - 1; // Start position
    int xt = E - 1, yt = F - 1; // Target position

    // BFS ke lie DS
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {xs, ys}});

    // Movements
    vector<int> delx {2, 2, 1, 1, -1, -1, -2, -2};
    vector<int> dely { -1, 1, -2, 2, -2, 2, -1, 1};

    while (q.empty() == false) {
        int distance = q.front().first;
        int xcurr = q.front().second.first;
        int ycurr = q.front().second.second;
        q.pop();

        // cout<<xcurr<<" "<<ycurr<<"|";

        // Check for target
        if (xcurr == xt and ycurr == yt)
            return distance;

        vis[xcurr][ycurr] = true;

        // BFS for all the directions
        for (int i = 0; i < 8; i++) {
            int x = xcurr + delx[i];
            int y = ycurr + dely[i];

            if (x >= 0 and y >= 0 and x < n and y < m and vis[x][y] == false) {
                q.push({distance + 1, {x, y}});
                vis[x][y] = true;
            }
        }
    }

    return -1;
}
