/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Floor Sqrt of a number
int Solution::sqrt(int A) {
    if (A == 0)
        return 0;
    if (A == 1)
        return 1;

    long long int start = 0, end = A;
    int ans = 0;

    while (start <= end) {
        long long int mid = start + (end - start) / 2;
        if (mid * mid == A)
            return mid;
        else if (mid * mid > A)
            end = mid - 1;
        else {
            start = mid + 1;
        }
    }

    return end;
}
