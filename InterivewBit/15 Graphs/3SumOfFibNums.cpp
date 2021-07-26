/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - How many fib number required to make A
int Solution::fibsum(int A) {
    // Fib bana lete hai
    vector<long long> fib;
    fib.push_back(1);
    fib.push_back(1);

    while (fib[fib.size() - 1] <= A) {
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }

    // Fib banne ke baad ab ek simple kaatna start krte hai
    int res = 0;
    int n = fib.size();
    while (n >= 0 and A > 0) {
        if (fib[n - 1] <= A) {
            A -= fib[n - 1];
            res++;
        } else {
            n--;
        }
    }

    return res;
}
