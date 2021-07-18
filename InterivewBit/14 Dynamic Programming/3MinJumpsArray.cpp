/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find min jumps to reach n-1.
int Solution::jump(vector<int> &A) {
    int n = A.size();
    if (n <= 1)
        return 0;

    int jumps = 0, currFarthest = 0, currEnd = 0;
    for (int i = 0; i < n - 1; i++) { // n-1 kyunki last index tk hi jaana hai
        currFarthest = max(currFarthest, i + A[i]);

        if (i == currEnd) {
            currEnd = currFarthest;
            jumps++;
        }

        // Not reachable condition
        if (i > currEnd)
            return -1;
    }

    // Check for not reachable
    if (currFarthest < n - 1)
        return -1;

    return jumps;
}
