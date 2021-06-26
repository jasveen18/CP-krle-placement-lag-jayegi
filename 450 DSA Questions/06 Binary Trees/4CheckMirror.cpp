/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Check if mirror image in n-ary tree.
// https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1
int checkMirrorTree(int n, int e, int A[], int B[]) {
    // Your approach was to make a map and store ek ka aage se and dusre ka reversed.
    vector<stack<int>> s(n + 1);
    vector<queue<int>> q(n + 1);

    for (int i = 0; i < 2 * e; i += 2) {
        s[A[i]].push(A[i + 1]);
        q[B[i]].push(B[i + 1]);
    }

    // Now we will take them out one by one and check, ek sidha hona chaiye and ek end se.
    // Har node ka n-children check krre hai original mein 1, 2, 3 hoga toh mirror pe 3, 2, 1 hoga.

    for (int i = 1; i <= n; i++) {
        while (!s[i].empty() and !q[i].empty()) {
            if (s[i].top() != q[i].front())
                return false;

            s[i].pop(); q[i].pop();
        }
    }

    return true;
}