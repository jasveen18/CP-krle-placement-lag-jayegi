/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Function to merge k sorted arrays.
vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
    vector<int> res;

    for (int i = 0; i < K; i++)
        minHeap.push({arr[i][0], {i, 0}});


    while (minHeap.size() > 0) {
        pair<int, pair<int, int>> minel = minHeap.top();
        minHeap.pop();

        res.push_back(minel.first);

        if (minel.second.second < K - 1) {
            minHeap.push({arr[minel.second.first][minel.second.second + 1], {minel.second.first, minel.second.second + 1}});
        }
    }

    return res;
}