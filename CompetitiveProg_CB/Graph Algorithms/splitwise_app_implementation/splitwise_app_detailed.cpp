#include <iostream>
#include <set>
#include <map>
using namespace std;


class person_compare {
public:
	bool operator()(pair<string, int> p1, pair<string, int> p2) {
		return p1.second < p2.second;
	}
};

int main() {
	int no_of_transactions, friends;
	cin >> no_of_transactions >> friends;


	string x, y;
	int amount;

	map<string, int> net;

	while (no_of_transactions--) {
		cin >> x >> y >> amount;
		if (net.count(x) == 0) net[x] = 0;
		if (net.count(y) == 0) net[y] = 0;

		net[x] -= amount;
		net[y] += amount;
	}

	// Iterate over persons and add in the multiset.
	multiset<pair<string, int>, person_compare> m;
	for (auto person : net) {
		string name = person.first;
		int amount = person.second;

		if (net[name] != 0) {
			m.insert(make_pair(name, amount));
		}
	}


	// Now, we will do settlements
	int count_transactions = 0;
	while (!m.empty()) {
		auto low = m.begin();
		auto high = prev(m.end());

		int debit = low->second;
		string debit_person = low->first;

		int credit = high->second;
		string credit_person = high->first;

		// Erase from multiset
		m.erase(low);
		m.erase(high);

		// Settlement
		int settlement_amount = min(-debit, credit);
		debit += settlement_amount;
		credit -= settlement_amount;

		// Print the transaction
		cout << debit_person << " will pay " << settlement_amount << " to " << credit_person << endl;

		// If settlement is not zero, insert again.
		if (debit) m.insert(make_pair(debit_person, debit));
		if (credit) m.insert(make_pair(credit_person, credit));

		count_transactions++;
	}

	return 0;
}
