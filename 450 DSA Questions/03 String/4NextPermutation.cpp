// T - O(N)
// S - O(1)
vector<int> nextPermutation(int N, vector<int> arr) {
    int n = arr.size();
    int i = n - 2;
    while (i >= 0 and arr[i] > arr[i + 1]) {
        i--;
    }

    if (i != -1) {
        int j = n - 1;
        while (j >= 0 and arr[j] <= arr[i]) {
            j--;
        }
        swap(arr[i], arr[j]);
    }

    reverse(arr.begin() + i + 1, arr.end());
    return arr;
}