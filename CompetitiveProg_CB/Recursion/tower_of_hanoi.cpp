#include<bits/stdc++.h>
using namespace std;

void move(int n, char src, char helper, char dest) {
	// Base Case
	if (n == 0)
		return;

	// Recursive Case
	// Step 1 - Move n-1 disks from source to helper.
	move(n - 1, src, dest, helper);
	// Step 2 - Move the nth disk from source to destination.
	cout << "Shift disk" << n << " from " << src << " to " << dest << endl;
	// Step 3 - Move those n-1 disks from helper to destination.
	move(n - 1, helper, src, dest);
}


int main () {
	int n;
	cin >> n;

	move(n, 'A', 'B', 'C');

	return 0;
}