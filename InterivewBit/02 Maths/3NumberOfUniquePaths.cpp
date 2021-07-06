/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Robot from 0, 0 to (n-1, m-1). Count number of paths.

// 1 -> Recursion, if(n == 1 or m == 1) return 1, rest dono direction pe recusion
// 2 -> Optimize recusion with DP.
// 3 -> You can also use space optimized DP be eliminating one dimension with sums hi.
// 4 -> Combinatorics
// (A + B - 2) C (A - 1)

int Solution::uniquePaths(int A, int B) {
    int paths = 1;
    for (int i = A; i < (A + B - 1); i++) {
        paths *= i;
        paths /= (i - A + 1);
    }

    return paths;
}
