/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

int *findTwoElement(int *arr, int n) {
    int *ans = new int(2);

    // First of all sbko ek chota kr dete hai to match index
    for (int i = 0; i < n; i++)
        arr[i] -= 1;

    // Ab sbme N add kr dete hai, count sort jaisa krne ko
    for (int i = 0; i < n; i++)
        arr[arr[i] % n] += n;

    // Ab count nikal lete hai
    for (int i = 0; i < n; i++) {
        arr[i] /= n;

        // Jiska count = 2, then wo duplicate hai
        if (arr[i] == 2)
            ans[0] = i + 1;

        // Jiska count = 0, then wo missing hai
        if (arr[i] == 0)
            ans[1] = i + 1;
    }

    return ans;
}