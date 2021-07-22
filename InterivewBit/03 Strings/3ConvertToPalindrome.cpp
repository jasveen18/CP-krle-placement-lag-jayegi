/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Convert the string to palindrome by removing one element
int Solution::solve(string A) {
    int n = A.size();

    int invalid = 0;
    int i = 0, j = n - 1;
    while (i <= j and i < n and j < n) {
        if (A[i] == A[j]) {
            i++; j--;
        }
        // Invalid case, now check ki kis element ko discard kre
        else {
            invalid++;

            if (A[i + 1] == A[j])
                i++;
            else if (A[i] == A[j - 1])
                j--;
            else
                return 0;
        }
    }

    return invalid == 1;
}
