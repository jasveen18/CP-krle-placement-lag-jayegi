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

