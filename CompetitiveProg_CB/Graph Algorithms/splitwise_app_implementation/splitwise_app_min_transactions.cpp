#include <iostream>
#include <set>

using namespace std;

int main() {
	int no_of_transactions, friends;
	cin >> no_of_transactions >> friends;

	int x, y, amount;

	// 1D Array to store the net amount of each person.
	int net[100000] = {0};

	while (no_of_transactions--) {
		cin >> x >> y >> amount;
		net[x] -= amount;
		net[y] += amount;
	}

	// Add the net transactions into multiset.
	multiset<int> m;
	for (int i = 0; i < friends; i++) {
		if (net[i] != 0) {
			m.insert(net[i]);
		}
	}

	// Take out 2 people from both ends, highest crediter and highest debiter.
	int count_transactions = 0;
	while (!m.empty()) {
		auto low = m.begin();
		auto high = prev(m.end());

		int debit = *low;
		int credit = *high;

		// Remove the amounts
		m.erase(low); m.erase(high);

		// Do Settlement
		int settlement_amount = min(-debit, credit);
		debit += settlement_amount;
		credit -= settlement_amount;

		// One of them is zero and for the other we push back into multiset.
		if (debit) m.insert(debit);
		if (credit) m.insert(credit);

		// One transaction done
		count_transactions++;
	}

	cout << count_transactions << endl;
}