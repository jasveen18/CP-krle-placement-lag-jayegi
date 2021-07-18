/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Jump Game Array
int Solution::canJump(vector<int> &A) {
    int distance = 0;
    int n = A.size();

    for (int i = 0; i <= distance; i++) {
        distance = max(distance, i + A[i]);

        if (distance >= n - 1)
            return true;
    }

    return false;
}
