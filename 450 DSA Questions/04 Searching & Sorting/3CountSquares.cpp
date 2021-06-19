/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Consider a sample space S consisting of all perfect squares starting from 1, 4, 9 and so on. You are given a number N, you have to output the number of integers less than N in the sample space S.

// So basically, floor of sqrt chaiye.

int countSquares(int N) {
    start = 0, end = N - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (mid * mid == N - 1)
            return mid;
        else if (mid * mid > N - 1)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return start;
}