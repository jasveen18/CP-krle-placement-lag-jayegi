/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the elements whose value is equal to that of its index value.

vector<int> valueEqualToIndex(int arr[], int n) {
	vector<int> elementsFound;

	for (int i = 0; i < n; i++) {
		if (arr[i] == i + 1)
			elementsFound.push_back(i + 1);
	}

	return elementsFound;
}