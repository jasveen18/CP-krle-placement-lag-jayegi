// Function to return the count of number of elements in union of two arrays.
// Approach - Sort the array and push valid elements
// Time Complexity - O((n+m)(Log(n+m)))
// Space Complexity - O(n + m)
int doUnion(int a[], int n, int b[], int m)  {
    // Sort the array
    sort(a, a + n);
    sort(b, b + m);

    // Auxilliary space to store the array
    vector<int> unionArr;

    int i = 0, j = 0;
    while (i < n and j < m) {
        // Skip Duplicates
        while (a[i] == a[i + 1] and i < n - 1)
            i++;

        while (b[j] == b[j + 1] and j < m - 1)
            j++;

        // If same elements, push only one
        if (a[i] == b[j]) {
            unionArr.push_back(a[i]);
            i++; j++;
        } else if (a[i] > b[j]) {
            unionArr.push_back(b[j]);
            j++;
        } else if (a[i] < b[j]) {
            unionArr.push_back(a[i]);
            i++;
        }
    }

    // Push the left elements
    while (i < n) {
        while (a[i] == a[i + 1] and i < n - 1)
            i++;
        unionArr.push_back(a[i++]);
    }
    while (j < m) {
        while (b[j] == b[j + 1] and j < m - 1)
            j++;
        unionArr.push_back(b[j++]);
    }

    // unionArr has the union of 2 arrays
    // Return size of arr
    return unionArr.size();
}


// Function to return the total count of intersection of two arrays.
// Approach - Sort the array and push valid elements
// Time Complexity - O((n+m)(Log(n+m)))
// Space Complexity - O(n + m)
int doIntersection(int a[], int n, int b[], int m) {
    // Sort the array
    sort(a, a + n);
    sort(b, b + m);

    // Auxilliary space to store the array
    vector<int> intersectionArr;

    int i = 0, j = 0;
    while (i < n and j < m) {
        // Skip Duplicates
        while (a[i] == a[i + 1] and i < n - 1)
            i++;

        while (b[j] == b[j + 1] and j < m - 1)
            j++;

        // If same elements, push to the array
        if (a[i] == b[j]) {
            intersectionArr.push_back(a[i]);
            i++; j++;
        } else if (a[i] > b[j]) {
            j++;
        } else if (a[i] < b[j]) {
            i++;
        }
    }

    // intersectionArr has the intersection of 2 arrays
    // Return size of arr
    return intersectionArr.size();
}