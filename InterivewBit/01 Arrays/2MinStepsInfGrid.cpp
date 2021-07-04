/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Min Steps in Inf Grid
int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    vector<pair<int, int>> coords;
    int n = A.size();
    for (int i = 0; i < n; i++) {
        coords.push_back({A[i], B[i]});
    }

    int x = coords[0].first, y = coords[0].second;
    int steps = 0;
    for (int i = 1; i < n; i++) {
        int diagmove = min(abs(coords[i].first - x), abs(coords[i].second - y));
        int xmoves = abs(coords[i].first - x) - diagmove;
        int ymoves = abs(coords[i].second - y) - diagmove;

        steps += diagmove + xmoves + ymoves;

        x = coords[i].first;
        y = coords[i].second;
    }

    return steps;
}
