#include<bits/stdc++.h>

using namespace std;

#define long long long
const long M = 1000000007 // Modulo
               map<long, long> F;

long fib(long n) {
    if (F.count(n)) return F[n];

    long k = n / 2;
    if (n % 2 == 0) {
        return F[n] = (fib(k) * fib(k) + f(k - 1) * f(k - 1)) % M;
    }
    else {
        return F[n] = (fib(k) * fib(k + 1) + f(k - 1) * f(k)) % M;
    }
}

int main() {
    long n;
    F[0] = F[1] = 1;
    while (cin >> n) {
        cout << (n == 0) ? 0 : fib(n - 1) << endl;
    }
}