// Time Complexity - O(Log N)
// Space Complexity - O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int col = m - 1;
    int row = 0;

    // Search in matrix
    while (col >= 0 and row < n) {
        // If target found
        if (matrix[row][col] == target)
            return true;
        // If it is larger then it must be before
        else if (matrix[row][col] > target)
            col--;
        // If it is smaller then it must be after
        else
            row++;
    }

    // Element not found
    return false;
}