/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the quadruple making target sum

vector<vector<int> > fourSum(vector<int> &arr, int k) {
    vector<vector<int>> res;
    int n = arr.size();

    // Sort the array for 2 pointer approach
    sort(arr.begin(), arr.end());

    // Nested loops ke andar 2 pointer
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int start = j + 1, end = n - 1;
            while (start < end) {
                // while(start == i or start == j and start < end)
                //     start++;
                // while(end == i or end == j and start < end)
                //     end--;

                int sumHere = arr[i] + arr[j] + arr[start] + arr[end];
                if (sumHere < k)
                    start++;
                else if (sumHere > k)
                    end--;
                else {
                    res.push_back({arr[i], arr[j], arr[start], arr[end]});
                    start++; end--;
                }
            }
        }
    }

    // Sort the answers to match the online judge
    for (int i = 0; i < res.size(); i++)
        sort(res[i].begin(), res[i].end());
    sort(res.begin(), res.end());

    // Remove Dups
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}