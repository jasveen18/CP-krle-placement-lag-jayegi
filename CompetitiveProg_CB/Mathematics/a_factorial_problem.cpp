// Mike found an interesting problem. In this problem you are given two integers, n and k. You need to find the the maximum value of x, such that, n! % kx = 0.

#include<bits/stdc++.h>
using namespace std;

int main() {

	int t; cin >> t;
	while (t--) {
		long long int n, k;
		cin >> n >> k;

		long long int ans = 0;

		while (n) {
			ans += (n / k);
			n /= k;
		}

		cout << ans << endl;
	}
}