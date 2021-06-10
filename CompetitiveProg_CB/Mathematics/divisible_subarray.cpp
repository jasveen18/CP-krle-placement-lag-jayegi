#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<ll> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		unordered_map<ll, ll> divs;
		ll res = 0;
		ll sum = 0;

		divs[0] = 1;
		for (int i = 0; i < n; i++) {
			sum += arr[i];
			divs[((sum % n) + n) % n]++;
		}

		for (auto x : divs) {
			res += (x.second) * (x.second - 1) / 2;
		}

		cout << res << endl;
	}
}