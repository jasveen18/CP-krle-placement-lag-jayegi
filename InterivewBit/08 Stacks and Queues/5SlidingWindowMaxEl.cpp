/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find max element for each window
#include<list>

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    vector<int> res;
    int n = A.size();

    list<int> highestElement;

    if (B > n)
        return {*max_element(A.begin(), A.end())};

    int i = 0, j = 0;
    while (j < n) {
        // Insert kro, and isse chote jitne bhi element hai ab tk, unko uda do
        while (highestElement.size() > 0 and highestElement.back() < A[j])
            highestElement.pop_back();

        highestElement.push_back(A[j]);

        if (j - i + 1 < B) {
            j++;
        } else if (j - i + 1 == B) {
            // Process
            res.push_back(highestElement.front());

            // Slide
            if (highestElement.front() == A[i])
                highestElement.pop_front();
            i++; j++;
        }
    }

    return res;
}
