/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Max Sum Combinations
// A hash function used to hash a pair of any kind
struct hash_pair {
    inline std::size_t operator()(const std::pair<int, int> & v) const {
        return v.first * 31 + v.second;
    }
};

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    priority_queue< pair<int, pair<int, int> > > pq;
    unordered_set<pair<int, int>, hash_pair> seen;
    vector<int> res;

    pq.push({A[n - 1] + A[n - 1], {n - 1, n - 1}});

    for (int i = 1; i <= C; i++) {
        int top = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        res.push_back(top);

        if (seen.find({x - 1, y}) == seen.end())
            pq.push({A[x - 1] + B[y], {x - 1, y}});
        if (seen.find({x, y - 1}) == seen.end())
            pq.push({A[x] + B[y - 1], {x, y - 1}});

        seen.insert({x - 1, y});
        seen.insert({x, y - 1});
    }

    return res;
}
