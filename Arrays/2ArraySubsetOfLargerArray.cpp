string isSubset(int a1[], int a2[], int n, int m) {
    int countArr[100000 + 4] = {0};
    for (int i = 0; i < n; i++) {
        countArr[a1[i]]++;
    }

    // Check if element there or not
    for (int i = 0; i < m; i++) {
        countArr[a2[i]]--;

        if (countArr[a2[i]] < 0)
            return "No";
    }

    return "Yes";
}