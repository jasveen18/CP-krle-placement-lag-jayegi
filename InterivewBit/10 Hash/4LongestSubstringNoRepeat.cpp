/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given a string,

// find the length of the longest substring without repeating characters.
int Solution::lengthOfLongestSubstring(string A) {
    unordered_map<char, int> count;

    int i = 0, j = 0, res = 0;

    while (j < A.size()) {
        count[A[j]]++;

        // This means that jitna len ka window hai utna hi element map pe hai
        if (count.size() == j - i + 1) {
            res = max(res, j - i + 1);
            j++;
        } else if (count.size() < j - i + 1) {
            // Jab tk shii track pe ni aa jaate hai
            while (count.size() < j - i + 1) {
                count[A[i]]--;

                if (count[A[i]] == 0)
                    count.erase(A[i]);
                i++;
            }

            j++;
        }
    }

    return res;
}
