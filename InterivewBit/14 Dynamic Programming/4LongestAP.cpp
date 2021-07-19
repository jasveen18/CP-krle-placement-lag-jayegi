/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find longest Arithmetic Progression in an integer array A of size N, and return its length.
int Solution::solve(const vector<int> &A) {
    int n = A.size();
    int ans = 1;

    map<int, map<int, int>> mp;

    // One element may be included in multiple AP
    // Map-> {index, {difference, length}}

    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {

            int diff = A[i] - A[j]; // Find the diff of these 2 numbers

            // Check if this difference is already seen or not with j as index
            if (mp[j].find(diff) != mp[j].end()) {
                mp[i][diff] = max(mp[i][diff], mp[j][diff] + 1); // Either include this element in AP or take the max pehle se agar hai toh
                ans = max(ans, mp[i][diff]);
            }
            else {
                mp[i][diff] = max(mp[i][diff], 2); // Update to 2 considering any 2 elements ek AP form krta hai
                ans = max(ans, 2);
            }
        }
    }

    return ans;
}
