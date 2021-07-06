/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the duplicate in the array of 1 to N, with N+1 elements.
int Solution::repeatedNumber(const vector<int> &A) {
    int slow = A[0];
    int fast = A[A[0]];

    while (slow != fast) {
        slow = A[slow];
        fast = A[A[fast]];
    }

    fast = 0;
    while (slow != fast) {
        slow = A[slow];
        fast = A[fast];
    }

    if (slow == 0)
        return -1;
    return slow;
}

// Other Solutions from Editorial ->
// 1. Editorial with O(sqrt) Space bucketing

int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    vector<int> rt;
    int count[n + 1];

    memset(count, 0, sizeof(count));
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        count[A[i]]++;

        if (count[A[i]] > 1)
            return A[i];
    }

    return 0;
}


// 2. Fastest
int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    long long int sum = 0;

    // Sum nikal kr expected sum se minus kr dia.
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }

    long long int m = n - 1;
    long long int total = (m * (m + 1)) / 2;
    return sum - total;
}


// 3. Lightweight with xors
int Solution::repeatedNumber(const vector<int> &A) {

    int i, xor1 = 0, xor2 = 1;
    for (i = 0; i < A.size(); i++) {
        xor1 ^= A[i];
    }

    int n = A.size();
    for (i = 2; i <= (n - 1); i++) {
        xor2 ^= i;
    }

    int repeat;
    repeat = xor1 ^ xor2;

    return repeat;
}