/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given num, divide it into 2 prime nums.
bool isPrime(int num) {
    if (num == 2)
        return true;
    if (num <= 1)
        return false;

    for (int i = 2; i <= sqrt(num) + 1; i++) {
        if (num % i == 0)
            return false;
    }

    return true;
}

vector<int> Solution::primesum(int num) {
    if (num == 4)
        return {2, 2};

    for (int i = 2; i <= num; i++) {
        if (isPrime(i) == true and isPrime(num - i) == true)
            return {i, num - i};
    }

    return {0, 0};
}
