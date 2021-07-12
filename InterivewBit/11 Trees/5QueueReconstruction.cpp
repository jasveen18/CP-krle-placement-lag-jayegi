/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement -You are given the following :

// A positive number N
// Heights : A list of heights of N persons standing in a queue
// Infronts : A list of numbers corresponding to each person (P) that gives the number of persons who are taller than P and standing in front of P
// You need to return  list of actual order of persons’s height


// Approach 1 - O(N*N)
// We put people in an array of length n. The number k means that we should put this person in the kth empty position from the beginning. The empty position mean that there will be higher or equal height person coming in here, so leave these positions out first. For everyone, we should first insert the lower h person. For the person who has same h we should first insert the person has larger k value. For everyone to put in, it takes O(n) time to find kth empty position, so it will take the O(n^2) time for all people.
// E.g.
// input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
// sort: [[4,4], [5,2], [5,0], [6,1], [7,1], [7,0]]

// step1: [[  ,  ], [  ,  ], [  ,  ], [  ,  ], [4,4], [  ,  ]]
// step2: [[  ,  ], [  ,  ], [5,2], [  ,  ], [4,4], [  ,  ]]
// step3: [[5,0], [  ,  ], [5,2], [  ,  ], [4,4], [  ,  ]]
// step4: [[5,0], [  ,  ], [5,2], [6,1], [4,4], [  ,  ]]
// step5: [[5,0], [  ,  ], [5,2], [6,1], [4,4], [7,1]]
// step6: [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
bool comp(pair<int, int> &a, pair<int, int> &b) {
	if (a.first == b.first)
		return a.second < b.second;

	return a.first < b.first;
}

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
	int n = A.size();

	BIT = vector<int>(n + 1, 0); //BIT[i+1] recorded the res[i] information because BIT[0] is not used.
	for (int i = 2; i <= n; i++) update(i, 1); // BIT[1] is the 0th empty position, so we didn't add 1

	vector<pair<int, int>> people;
	for (int i = 0; i < n; i++) {
		people.push_back({A[i], B[i]});
	}

	sort(people.begin(), people.end(), comp);

	vector<int> res(n, -1);

	for (int i = 0; i < n; i++) {
		int count = people[i].second;

		for (int j = 0; j < n; j++) {
			if (res[j] == -1 and count == 0) {
				res[j] = people[i].first;
				break;
			} else if (res[j] == -1 or res[j] > people[i].first) {
				count -= 1;
			}
		}
	}

	return res;
}


// Approach 2 - Now we will optimize the nested loop in the above approach
// to find the correct position.
// This method is an optimization of method 1. In solution 1, it takes O(n) time to find kth empty position for everyone.
// If you can find the kth empty position using the binary search method, it will save a lot of time.
// To use a binary search, you need to have a data structure to record the current position is the nth empty positions.
// The easiest thing to think about is an array, but each time you put in a person, you need to update the empty count value after this position in the array.
//It's still takes O(n) time. If we use the binary index tree, we can get the nth information with the complexity of O(logn), and we can use the O(logn) complexity to update the subsequent position.

vector<int> BIT;
int n;

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
	int n = A.size();

	vector<pair<int, int>> people;
	for (int i = 0; i < n; i++) {
		people.push_back({A[i], B[i]});
	}

	sort(people.begin(), people.end(), comp);

	vector<int> res(n);

	for (int i = 0; i < n; i++) {

		// Binary indexed tree se O(Log N) m find
		int l = 0, r = n;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (getSum(mid + 1) < people[i].second) l = mid + 1;
			else r = mid;
		}

		res[l] = people[i].first;
		update(l + 1, -1);
	}

	return res;
}


void update(int x, int v) {
	for (int i = x; i <= n; i += (i & -i)) {
		BIT[i] += v;
	}
}


int getSum(int x) {
	int sum = 0;
	for (int i = x; i > -; i -= (i & -i))
		sum += BIT[i];

	return sum;
}