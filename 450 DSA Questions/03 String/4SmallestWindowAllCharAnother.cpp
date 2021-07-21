/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Smallest window string all char of another
string smallestWindow (string A, string B) {
    vector<int> count(26, 0);
    int res = INT_MAX;
    int start = 0;

    int total = 0;

    for (int i = 0; i < B.size(); i++) {
        if (count[B[i] - 'a'] == 0)
            total++;
        count[B[i] - 'a']++;
    }

    int i = 0, j = 0;
    while (j < A.size()) {
        count[A[j] - 'a']--;

        if (count[A[j] - 'a'] == 0)
            total--;

        if (total > 0)
            j++;
        else if (total == 0) {
            while (total == 0) {
                if (res > j - i + 1) {
                    res = j - i + 1;
                    start = i;
                }

                count[A[i] - 'a']++;

                if (count[A[i] - 'a'] > 0)
                    total++;

                i++;
            }
            j++;
        }
    }

    if (res != INT_MAX)
        return A.substr(start, res);

    return "-1";
}