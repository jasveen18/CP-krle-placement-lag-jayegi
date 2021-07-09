/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Sort 0 1 2
void Solution::sortColors(vector<int> &A) {
    int n = A.size();
    int i = 0, j = n - 1;
    int trav = 0;

    while (trav <= j) {
        if (A[trav] == 2) {
            swap(A[trav], A[j]);
            j--;
        } else if (A[trav] == 1) {
            trav++;
        } else if (A[trav] == 0) {
            swap(A[i], A[trav]);
            i++; trav++;
        }
    }

    return;
}
