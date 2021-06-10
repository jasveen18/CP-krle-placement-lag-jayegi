// Catalan Series
// ----------------------
//
// : 1, 1, 2, 5, 14, 42, 132, ...
// Direct formula - 2nCn / (n+1)
// Recursive formula - iterate over all n and add - f(i-1)*f(n-1)

#include<bits/stdc++.h>
using namespace std;

int catalanDP(int n) {
	int catalan[n + 1];
	catalan[0] = catalan[1] = 1;


	for (int i = 2; i <= n; i++) {
		catalan[i] = 0;
		for (int j = 0; j < i; j++)
			catalan[i] += catalan[j] * catalan[i - j - 1];
	}

	return catalan[n];

}

int main() {
	int n = 10;
	for (int i = 0; i <= n; i++) {
		cout << catalanDP(i) << endl;
	}
}

