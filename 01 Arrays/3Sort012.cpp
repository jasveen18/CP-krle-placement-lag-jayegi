// Idea - Throw 2 at the end, throw 0 at beginning, leave 1, it'll settle.
// Time Complexity - O(N)
// Space Compleixty - O(1)
void sort012(int a[], int n)
{
    int left = 0, right = n - 1;
    int traversal = 0;

    while (traversal <= right) {
        // If the element is 2, send to last
        if (a[traversal] == 2) {
            swap(a[traversal], a[right]);
            right--;
        } else if (a[traversal] == 0) { // If the element is 0, send to beg
            swap(a[left], a[traversal]);
            left++; traversal++;
        } else { // If element is 1, traverse
            traversal++;
        }
    }
}