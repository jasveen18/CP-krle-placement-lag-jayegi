/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the first non-repeating char in stream of chars
string Solution::solve(string A) {
    int n = A.size();
    unordered_map<char, int> count;
    queue<char> first;

    string res = "";

    for (int i = 0; i < n; i++) {
        // Mark as visited
        count[A[i]]++;

        // If first occurance then push into queue
        if (count[A[i]] == 1) {
            first.push(A[i]);
        } else {  // If first ni hai toh, find the next element with 1 occurance
            while (first.empty() == false and count[first.front()] >= 2) first.pop();
        }

        // Insert char as per available character
        if (first.empty())
            res += '#';
        else
            res += first.front();
    }

    return res;
}
