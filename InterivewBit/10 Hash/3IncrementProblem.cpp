/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Stream of integers, increment the first occurance if it is present by 1.
vector<int> Solution::solve(vector<int> &A) {
    unordered_map<int, int> count;
    int n = A.size();

    for (int i = 0; i < n; i++) {
        if (count.find(A[i]) == count.end())
            count[A[i]] = i;

        else {
            int idx = count[A[i]];
            A[idx]++;

            count[A[i]] = i;

            if (count.find(A[idx]) == count.end())
                count[A[idx]] = idx;
            else if (count[A[idx]] > idx) {
                count[A[idx]] = idx;
            }
        }
    }

    return A;
}
