/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.
string Solution::minWindow(string A, string B) {
    unordered_map<char, int> count;
    int res = INT_MAX;
    int start = 0;

    for (auto el : B)
        count[el]++;
    int total = count.size();

    int i = 0, j = 0;
    while (j < A.size()) {
        count[A[j]]--;

        // This character is included here
        if (count[A[j]] == 0)
            total--;

        if (total > 0)
            j++;
        else if (total == 0) {
            while (total == 0) { // Try to take out elements from left
                if (res > j - i + 1) {
                    res = j - i + 1;
                    start = i;
                }

                count[A[i]]++;

                if (count[A[i]] > 0)
                    total++;

                i++;
            }
            j++;
        }
    }

    if (res != INT_MAX)
        return A.substr(start, res);

    return "";
}
