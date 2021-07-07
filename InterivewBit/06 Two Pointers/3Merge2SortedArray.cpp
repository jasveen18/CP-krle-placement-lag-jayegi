/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Merge 2 sorted arrays
void Solution::merge(vector<int> &A, vector<int> &B) {
    int i = 0, j = 0;
    int k = 0;
    int n = A.size();
    int m = B.size();

    vector<int> res(n + m, 0);

    while (i < n and j < m) {
        if (A[i] <= B[j])
            res[k++] = A[i++];
        else
            res[k++] = B[j++];
    }

    while (i < n)
        res[k++] = A[i++];
    while (j < m)
        res[k++] = B[j++];

    A.resize(n + m);
    for (int x = 0; x < n + m; x++)
        A[x] = res[x];

    return;
}


// O(1) space

void Solution::merge(vector<int> &A, vector<int> &B)
{

    // O(1) space
    // If all elements of B are placed in array
    // then elements of A are already in place

    int i = A.size() - 1; // i pointing to last index of A
    int j = B.size() - 1; // j pointing to last index of B

    int lastPos = A.size() + B.size() - 1; // lastPos pointing to last index of merged array A and B

    A.resize(A.size() + B.size());

    while (j >= 0)
    {
        if (i >= 0 and A[i] > B[j])
            A[lastPos--] = A[i--];
        else
            A[lastPos--] = B[j--];
    }

}
