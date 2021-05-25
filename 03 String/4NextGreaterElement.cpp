int nextGreaterElement(int n) {
    if (n == INT_MAX)
        return -1;

    // Convert integer to a list of integers (digits)
    string s = to_string(n);
    vector<int> arr;
    for (int i = 0; i < s.size(); i++)
        arr.push_back(s[i] - '0');

    n = arr.size();

    // Next Permutation Logic
    int i = n - 2;
    while (i >= 0 and arr[i] >= arr[i + 1]) {
        i--;
    }

    if (i != -1) {
        int j = n - 1;
        while (j >= 0 and arr[j] <= arr[i]) {
            j--;
        }
        swap(arr[i], arr[j]);
    } else {
        return -1;
    }

    reverse(arr.begin() + i + 1, arr.end());

    // Convert back to integer
    long long int ans = 0;
    for (int i = arr.size() - 1; i >= 0; i--) {
        ans += arr[i] * pow(10, arr.size() - i - 1);
    }

    // If integer is out of range
    if (ans > INT_MAX)
        return -1;

    return ans;
}