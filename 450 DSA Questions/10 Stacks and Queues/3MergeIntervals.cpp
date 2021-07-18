/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Merge Intervals
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> res;
    vector<int> temp{intervals[0][0], intervals[0][1]};

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= temp[1]) {
            temp[1] = max(intervals[i][1], temp[1]);
        } else {
            res.push_back(temp);
            temp[0] = intervals[i][0];
            temp[1] = intervals[i][1];
        }
    }
    res.push_back(temp);

    return res;
}