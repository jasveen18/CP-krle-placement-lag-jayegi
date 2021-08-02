/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Snake and Ladders
int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    vector<int> arr(102, 0);

    for (auto ld : A) {
        int u = ld[0];
        int v = ld[1];

        arr[u] = v;
    }

    for (auto sp : B) {
        int u = sp[0];
        int v = sp[1];

        arr[u] = v;
    }

    int res = 0;
    vector<bool> visited(102, false);
    queue<int> q;

    // First place
    int start = arr[1] == 0 ? 1 : arr[1];
    visited[start] = true;
    q.push(start);

    while (q.empty() == false) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int curr = q.front(); q.pop();

            if (curr == 100)
                return res;

            for (int dice = curr + 1; dice <= min(curr + 6, 100); dice++) {
                int dest = arr[dice] == 0 ? dice : arr[dice];

                if (visited[dest] == false) {
                    visited[dest] = true;
                    q.push(dest);
                }
            }
        }

        res++;
    }

    // cout<<res<<" ";
    return -1;
}
