vector <int> numToVec(int N) {
    vector<int> digit;
    while (N != 0) {
        digit.push_back(N % 10);
        N = N / 10;
    }
    if (digit.size() == 0)
        digit.push_back(0);

    reverse(digit.begin(), digit.end());
    return digit;
}


int Solution::solve(vector<int> &A, int B, int C) {
    int lenC = 0;
    int temp = C;
    int n = A.size();

    // Check for 0 present in A.
    bool zeroPresent = false;
    for (int i = 0; i < n; i++) {
        if (A[i] == 0) {
            zeroPresent = true;
            break;
        }
    }

    while (temp) {
        lenC++;
        temp /= 10;
    }

    // Case 1 - If B is greater than length of C.
    if (B > lenC or A.size() == 0)
        return 0;

    // Case 2 - If B is smaller than length of C.
    if (B < lenC) {
        // If zero is not present then all choices
        if (!zeroPresent) {
            return pow(d, B);
        } else { // If zero present then usko first pe ni rakhenge, then all choices
            return (n - 1) * pow(n, B);
        }
    }

    // Case 3 - If len of B == len of C
    vector<int> digit = numToVec(C);

    int dp[B + 1], lower[11];

    for (int i = 0; i <= B; i++)
        dp[i] = 0;
    for (int i = 0; i <= 10; i++)
        lower[i] = 0;
    for (int i = 0; i < n; i++)
        lower[A[i] + 1] = 1;

    for (int i = 1; i <= 10; i++)
        lower[i] = lower[i - 1] + lower[i];

    bool flag = true;
    dp[0] = 0;
    for (int i = 1; i <= B; i++) {

        d2 = lower[digit[i - 1]];
        dp[i] = dp[i - 1] * n;

        // For first index we can't use 0
        if (i == 1 &&  A[0] == 0 && B != 1)
            d2 = d2 - 1;

        //Whether (i-1) digit of generated number can be equal to (i - 1) digit of C.
        if (flag)
            dp[i] += d2;
        //Is digit[i - 1] present in A ?
        flag = flag & (lower[digit[i - 1] + 1] == lower[digit[i - 1]] + 1);
    }


    return dp[B];
}
