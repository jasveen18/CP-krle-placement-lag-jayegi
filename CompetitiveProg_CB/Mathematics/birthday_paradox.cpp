/*
Determine the minimum number of people required in the room
so that two have same birthday with probability
greater than or equal to 'p'.
(Assume there are 365 days in every year)
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	// x - probablity of 2 people having the same birthday
	double x = 1.0;
	double numerator = 365;
	double denominator = 365;

	double p;
	cin >> p;

	int people = 0;

	while (x > 1 - p) {
		x = x * (numerator / denominator);
		numerator--;
		people++;
	}

	cout << people << endl;
}