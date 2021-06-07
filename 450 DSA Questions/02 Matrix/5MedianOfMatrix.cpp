// Approach 1 - Brute Force
// Time Complexity - O(r*c Log(r*c))
// Space Complexity - O(r*c)
int median(vector<vector<int>> &matrix, int r, int c) {
    vector<int> flatten;

    // Store all the elements of the matrix
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            flatten.push_back(matrix[i][j]);
        }
    }

    // Sort the elements and return mid element
    sort(flatten.begin(), flatten.end());
    return flatten[r * c / 2];
}


// Approach 2 - Binary Search on possible answers.
// Time Complexity - O(32 * r * log(c))
//                     32 for search on numbers
//                          r for each row
//                                c binary search on each row
// Space Complexity - O(1)

// Find the min and max elements, this is our search space.
// We will apply binary search on each row to find the number of elements smaller than it.
// For median, it should have (r*c) / 2 number smaller that it.
int median(vector<vector<int>> &matrix, int r, int c) {

    // Get the min and max el for search space
    int minEl = INT_MAX, maxEl = INT_MIN;
    for (int i = 0; i < r; i++) {
        minEl = min(matrix[i][0], minEl);
        maxEl = max(matrix[i][c - 1], maxEl);
    }

    // Binary search
    int medianCount = (r * c + 1) / 2;
    while (minEl < maxEl) {
        int midEl = minEl + (maxEl - minEl) / 2;
        int smallCount = 0;

        // Count the number of numbers smaller than mid
        for (int i = 0; i < r; i++) {
            smallCount += upper_bound(matrix[i].begin(), matrix[i].end(), midEl) - matrix[i].begin();
        }

        if (smallCount < medianCount)
            minEl = midEl + 1;
        else
            maxEl = midEl;
    }

    return minEl;
}