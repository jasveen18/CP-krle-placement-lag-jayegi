/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find pair with difference = k.
int Solution::diffPossible(vector<int> &A, int B) {
    if (A.size() == 1)
        return 0;

    int n = A.size();
    int p1 = 0, p2 = 1; // Dono start se start honge.

    while (p2 < n and p1 < n) {
        while (p2 < n and A[p2] - A[p1] < B)
            p2++;

        // Check if they are not same index
        if (A[p2] - A[p1] == B and p2 != p1)
            return 1;
        // If same index then p2 ko badha do to make them different
        if (A[p2] - A[p1] == B and p2 == p1)
            p2++;

        while (p2 < n and p1 < n and A[p2] - A[p1] > B)
            p1++;
    }

    return 0;
}
