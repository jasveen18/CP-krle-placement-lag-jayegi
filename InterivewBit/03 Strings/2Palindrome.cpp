/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Check for palindrome, only take alphanumeric cases.
int Solution::isPalindrome(string A) {
    string newRes = "";

    // Take the required string
    for (int i = 0; i < A.size(); i++) {
        if (A[i] >= 97 and A[i] < (97 + 26)) {
            newRes += A[i];
        } else if (A[i] >= 65 and A[i] < (65 + 26)) {
            newRes += (A[i] + (97 - 65));
        } else if (A[i] >= '0' and A[i] <= '9') {
            newRes += A[i];
        }
    }

    // Check palindrome
    int i = 0;
    int j = newRes.size() - 1;

    while (i < j) {
        if (newRes[i] != newRes[j])
            return 0;

        i++; j--;
    }

    return 1;
}
