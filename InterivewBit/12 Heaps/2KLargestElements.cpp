/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Return k largest elements.
vector<int> Solution::solve(vector<int> &A, int B) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < A.size(); i++) {
        pq.push(A[i]);

        if (pq.size() > B)
            pq.pop();
    }

    vector<int> res;
    while (pq.empty() == false) {
        res.push_back(pq.top());
        pq.pop();
    }

    return res;
}
