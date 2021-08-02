/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// 1. 933. Number of Recent Calls
class RecentCounter {
private:
	vector<int> pings;
	int i, j;
public:
	RecentCounter() {
		pings = vector<int>();
		i = -1;
		j = -1;
	}

	int ping(int t) {
		// First entry
		if (i == -1 and j == -1) {
			pings.push_back(t);
			i++; j++;
			return 1;
		}

		pings.push_back(t);
		j++;
		while (i < j and pings[i] + 3000 < pings[j])
			i++;

		return (j - i + 1);
	}
};

