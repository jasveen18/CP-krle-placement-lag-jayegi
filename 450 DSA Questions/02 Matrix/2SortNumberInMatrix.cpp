// Time Complexity - O(N*N Log N)
// Space Complexity - O(N*N)
vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
    vector<int> flatten;

    // Store all the elements of the matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            flatten.push_back(Mat[i][j]);
        }
    }

    // Sort the elements and return mid element
    sort(flatten.begin(), flatten.end());
    int k = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Mat[i][j] = flatten[k++];
        }
    }

    return Mat;
}