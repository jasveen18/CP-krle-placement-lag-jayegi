/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Remove all instance of element from array.
int Solution::removeElement(vector<int> &A, int B) {
    int el = 0;
    int n = A.size();

    while (el < n and A[el] != B)
        el++;

    int nonEl = el + 1;
    while (nonEl < n and A[nonEl] == B)
        nonEl++;

    while (nonEl < n and el < n) {
        swap(A[el], A[nonEl]);

        while (el < n and A[el] != B)
            el++;

        while (nonEl < n and A[nonEl] == B)
            nonEl++;
    }

    int countEl = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == B)
            countEl++;
    }

    A.erase(A.begin() + n - countEl, A.end());
    return A.size();
}
