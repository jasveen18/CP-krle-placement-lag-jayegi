/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given number as an array. Add one to it.
vector<int> Solution::plusOne(vector<int> &A) {
    int n = A.size();
    reverse(A.begin(), A.end());

    int carry = 1;
    int i = 0;

    while (i < A.size() and carry) {
        int sumHere = A[i] + carry;
        carry = sumHere / 10;
        A[i] = sumHere % 10;
        i++;
    }

    if (carry) {
        A.push_back(carry);
    }

    reverse(A.begin(), A.end());

    // Eliminate zeroes
    i = 0;
    while (i < A.size() and A[i] == 0)
        i++;
    A = vector<int> (A.begin() + i, A.end());
    return A;
}