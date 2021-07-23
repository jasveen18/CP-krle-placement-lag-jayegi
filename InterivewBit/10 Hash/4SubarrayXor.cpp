/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find number of subarrays with all xors equal to B.
int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> store;
    int n = A.size();

    int res = 0;
    int running = 0;
    // store[0] = 1;

    for (int i = 0; i < n; i++) {
        // Add B also to store it with the xor of current num
        running ^= A[i] ^ B;

        if (store.find(running) != store.end()) {
            res += store[running];
        }

        if (running == 0)
            res++;

        // Revert back to original running
        running ^= B;

        store[running]++;
    }

    return res;
}
