/*
Find number of ways to choose n marbels, such that
you have k distinct marbles.
*/

#include <iostream>
using namespace std;

#define int long long

int getncr(int n, int k) {
	int res = 1;
	if (k > n - k)
		k = n - k;
	for (int i = 0; i < k; ++i) {
		res *= (n - i);
		res /= (i + 1);
	}
	return res;
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t-- > 0) {
		int n, k;
		cin >> n >> k;
		cout << getncr(n - 1, k - 1) << "\n";
	}
	return 0;
}