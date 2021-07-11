/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Distinct Numbers in a window
vector<int> Solution::dNums(vector<int> &A, int B) {
    int n = A.size();
    if (B > n)
        return {};

    vector<int> res;
    int distinct = 0;
    unordered_map<int, int> count;

    int i = 0, j = 0;
    while (j < n) {
        count[A[j]]++;
        if (count[A[j]] == 1)
            distinct++;

        if (j - i + 1 < B)
            j++;
        else {
            res.push_back(distinct);

            // Slide the window
            count[A[i]]--;
            if (count[A[i]] == 0)
                distinct--;
            i++; j++;
        }
    }

    return res;
}
