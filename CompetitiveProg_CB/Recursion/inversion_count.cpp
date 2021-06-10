// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]

long long int merge(long long *arr, long long start, long long end, long long int &ans) {
    long long mid = start + (end - start) / 2;

    long long i = start;
    long long j = mid + 1;
    long long k = start;

    long long temp[10000];
    long long int count = 0;

    while (i <= mid and j <= end) {
        if (arr[i] <= arr[j]) {
            // ans++;
            temp[k++] = arr[i++];
        } else if (arr[i] > arr[j]) {
            count += mid - i;
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= end)
        temp[k++] = arr[j++];

    for (int i = start; i <= end; i++)
        temp[i] = arr[i];
}


long long int invMerge(long long *arr, long long start, long long end, long long int &ans) {
    if (start >= end)
        return;

    long long mid = start + (end - start) / 2;

    long long int x = invMerge(arr, start, mid);
    long long int y = invMerge(arr, mid + 1, end);

    return x + y + merge(arr, start, end);
}


long long int inversionCount(long long arr[], long long N)
{
    return invMerge(arr, 0, N - 1);
}


// { Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }

        cout << inversionCount(A, N) << endl;
    }

    return 0;
}
// } Driver Code Ends