/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Intersection of 2 arrays
vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int n1 = A.size();
    int n2 = B.size();

    vector<int> res;
    int curr1 = 0, curr2 = 0;

    while (curr1 < n1 and curr2 < n2) {
        if (A[curr1] == B[curr2]) {
            res.push_back(A[curr1]);
            curr1++;
            curr2++;
        } else if (A[curr1] < B[curr2]) {
            curr1++;
        } else {
            curr2++;
        }
    }

    return res;
}
