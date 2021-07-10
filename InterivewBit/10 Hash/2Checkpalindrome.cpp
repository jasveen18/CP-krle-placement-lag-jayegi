/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Check palindrome
int Solution::solve(string A) {
    int n = A.size();
    unordered_map<char, int> count;

    for (int i = 0; i < n; i++) {
        count[A[i]]++;
    }

    int ignore = 0;
    for (auto el : count)
        if (el.second & 1)
            ignore++;

    if (ignore >= 2)
        return 0;
    return 1;
}
