// Approach - Intersect 2 arrays, then resulting array with third array.
// Time Complexity - O(n1 + n2 + n3)
// Space Complexity - O(n1 + n2 + n3)
vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
{
    int n = n1, m = n2;
    // Auxilliary space to store the array
    vector<int> intersectionArr;

    // Intersection of 2 arrays
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


    // Intersection of resulting array and third array
    vector<int> resIntersection;

    i = 0, j = 0;
    n = n3, m = intersectionArr.size();

    while (i < n and j < m) {
        while (c[i] == c[i + 1] and i < n - 1)
            i++;

        while (intersectionArr[j] == intersectionArr[j + 1] and j < m - 1)
            j++;

        // If same elements then push
        if (c[i] == intersectionArr[j]) {
            resIntersection.push_back(c[i]);
            i++; j++;
        } else if (c[i] > intersectionArr[j])
            j++;
        else if (c[i] < intersectionArr[j])
            i++;
    }

    return resIntersection;
}