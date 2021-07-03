vector<int> Solution::findPerm(const string A, int B) {
    vector<int> res;
    int start = 1, end = B;

    for (int i = 0; i < A.size(); i++) {
        if (A[i] == 'I')
            res.push_back(start++);
        else
            res.push_back(end--);
    }

    res.push_back(start);

    return res;
}