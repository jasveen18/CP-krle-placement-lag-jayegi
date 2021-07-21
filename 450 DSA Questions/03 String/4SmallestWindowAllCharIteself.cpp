/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Smallest that contains all characters of itself.
string findSubString(string A) {
    unordered_map<char, int> count;
    unordered_map<char, int> present;

    if (A.size() == 1)
        return A;

    for (auto el : A) {
        present[el] = 1;
    }
    int total = present.size();

    int i = 0, j = 0;
    int n = A.size();
    int res = INT_MAX;
    int start = 0;

    while (j < n) {
        if (present[A[j]] and count[A[j]] == 0)
            total--;
        count[A[j]]++;

        if (total == 0) {
            while (total == 0) {
                if (res > j - i + 1) {
                    res = j - i + 1;
                    start = i;
                }

                count[A[i]]--;
                if (count[A[i]] == 0 and present[A[i]])
                    total++;
                i++;
            }
        }

        j++;
    }

    return A.substr(i - 1, res);
}