/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.
void Solution::arrange(vector<int> &A) {
    int n = A.size();

    for (int i = 0; i < n; i++) {
        A[i] = A[i] + (n * (A[A[i]] % n));
    }

    for (int i = 0; i < n; i++) {
        A[i] /= n;
    }

    return;
}
