/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Return the highest product of 3 numbers
int Solution::maxp3(vector<int> &A) {
    int n = A.size();
    if (n < 3)
        return 0;

    sort(A.begin(), A.end());

    int peecheTeen = A[n - 1] * A[n - 2] * A[n - 3];
    int aageDoPeecheEk = A[n - 1] * A[0] * A[1];

    return  max(peecheTeen, aageDoPeecheEk);
}
