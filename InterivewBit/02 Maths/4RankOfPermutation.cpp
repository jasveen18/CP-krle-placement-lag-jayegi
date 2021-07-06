/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find rank of permutation
vector<long long> factorial(int n, int mod) {
    vector<long long> res(n + 1, 0);
    res[0] = 1;
    res[1] = 1;

    for (int i = 2; i <= n; i++) {
        res[i] = (res[i - 1] * i) % mod;
    }

    return res;
}

int findSmallerRight(string s, int low, int right) {
    char here = s[low];
    int count = 0;
    for (int i = low + 1; i < right; i++) {
        if (here > s[i])
            count++;
    }

    return count;
}

int Solution::findRank(string A) {
    // Permutation of any number is n!.
    int mod = 1000003;
    int n = A.size();

    vector<long long> fact = factorial(n, mod);

    string sortedStr = A;
    sort(sortedStr.begin(), sortedStr.end());

    int firstUnmatchedIdx = 0;
    while (firstUnmatchedIdx < n and A[firstUnmatchedIdx] == sortedStr[firstUnmatchedIdx])
        firstUnmatchedIdx++;

    if (firstUnmatchedIdx == n)
        return 1;

    int res = 0;
    for (int i = firstUnmatchedIdx; i < n; i++) {
        res += ((findSmallerRight(A, i, n) % mod) * (fact[n - i - 1] % mod)) % mod;
    }

    return (res + 1) % mod;
}
