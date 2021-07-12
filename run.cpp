/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define max4(a, b, c, d) max(a, max3(b, c, d))
#define min4(a, b, c, d) min(a, min3(b, c, d))

#define TestCase ll t = 1; cin >> t; while (t--)
#define vin ll n; cin >> n; vector<int> v(n); for (ll i = 0; i < n; i++) cin >> v[i]
#define vout for (ll i = 0; i < n; i++) cout << v[i] << " "
#define ain ll n, k; cin >> n >> k; ll a[n]; for (ll z = 0; z < n; z++) cin >> a[z]
#define aout for (ll i = 0; i < n; i++) cout << a[i] << " "

#define blink                \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const double PI = 3.141592653589793238463;
/********************************/
/**** Your code goes here - ****/
/*******************************/

void dfsTimeIt(int src, vector<int> adjList[], vector<bool> &vis, int &timer, vector<int> &startTime, vector<int> &endTime) {
	vis[src] = true;
	startTime[src] = timer++;

	for (auto nbr : adjList[src]) {
		if (vis[nbr] == false) {
			dfsTimeIt(nbr, adjList, vis, timer, startTime, endTime);
		}
	}

	endTime[src] = timer++;
}


void isPossibleToFind(int n, vector<pair<int, int>> &edgeList, int q, vector<vector<int>> &queries) {
	// Convert edge list to adj list
	vector<int> adjList[n];
	for (int i = 0; i < edgeList.size(); i++) {
		adjList[edgeList[i].first].push_back(edgeList[i].second);
	}

	vector<bool> vis(n, false);
	vector<int> startTime(n, 0);
	vector<int> endTime(n, 0);
	int timer = 0;

	// Store the start time and end time of the nodes
	dfsTimeIt(0, adjList, vis, timer, startTime, endTime);

	for (int i = 0; i < queries.size(); i++) {
		int dir = queries[i][0], dest = queries[i][1], src = queries[i][2];

		if (dir == 0) {
			if (startTime[src] > startTime[dest] and endTime[src] < endTime[dest])
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		} else {
			if (startTime[dest] > startTime[src] and endTime[dest] < endTime[src])
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	// cout<<"Test"<<endl;
	return;
}


int isPalindrome(int A) {
	if (A < 0)
		return 0;

	long long int dummy = A;
	long long int n = A;

	long long int start = 1;
	long long int end = 10;
	int i = 0, j = 0;


	// Count the power of 10 required
	while (dummy) {
		j++;
		start *= 10;
		dummy /= 10;
	}
	start /= 10;

	long long int startKeLie = n;
	long long int endKeLie = n;

	while (i < j) {
		int lastDig = endKeLie % 10;
		endKeLie /= 10;

		int firstDig = startKeLie / start;
		startKeLie %= start;
		start /= 10;

		// cout << firstDig << " " << lastDig << endl;
		if (firstDig != lastDig)
			return 0;
		i++; j--;
	}

	return 1;
}


vector<long long> factorial(int n, int mod) {
	vector<long long> res(n + 1, 0);
	res[0] = 1;
	res[1] = 1;

	for (int i = 2; i <= n; i++) {
		res[i] = (res[i - 1] * i) % mod;
	}

	return res;
}


int findRank(string A) {
	// Permutation of any number is n!.
	int mod = 1000003;
	int n = A.size();

	vector<long long> fact = factorial(n, mod);

	string sortedStr = A;
	sort(sortedStr.begin(), sortedStr.end());

	int firstUnmatchedIdx = 0;
	while (firstUnmatchedIdx < n and A[firstUnmatchedIdx] == sortedStr[firstUnmatchedIdx])
		firstUnmatchedIdx++;

	if (firstUnmatchedIdx == n)
		return 1;

	unordered_map<char, int> idxQuickAccess;
	for (int i = 0; i < n; i++)
		idxQuickAccess[sortedStr[i]] = i;

	int res = 0;
	deb(firstUnmatchedIdx);
	for (int i = firstUnmatchedIdx; i < n; i++) {
		if (A[i] != sortedStr[i]) {
			int valueHere = (fact[n - i - 1] * idxQuickAccess[A[i]]) % mod;
			res += valueHere % mod;
			// cout << i << " " << res << endl;
			deb2(fact[n - i - 1], idxQuickAccess[A[i]]);
		}
	}

	return res;
}


int solve(int A, vector<int> &B) {
	int n = A;
	int sumAll = 0;
	for (int i = 0; i < n; i++)
		sumAll += B[i];
	int sumEach = sumAll / 3;

	if (sumAll % 3 != 0 or B.size() < 3)
		return 0;

	int oneThirdCount = 0;
	int oneThirdSum = sumEach;
	int twoThirdSum = 2 * sumEach;
	int count = 0;

	int currSum = 0;
	for (int i = 0; i < n - 1; i++) {
		currSum += B[i];
		if (currSum == twoThirdSum)
			count += oneThirdCount;
		if (currSum == oneThirdSum)
			oneThirdCount++;
	}

	return count;
}


int uniquePaths(int A, int B) {
	return (1 << ((A - 1) * (B - 1)));
}

string convert(string A, int B) {
	string res = "";
	int n = A.size();

	for (int i = 0; i < B; i++) {
		for (int j = i; j < n; j += (B + 1))
			res += A[j];
		cout << res << endl;
	}

	return res;
}

string mult2(string s) {
	reverse(s.begin(), s.end());
	int carry = 0;

	vector<int> nums;
	for (int i = 0; i < s.size(); i++) {
		nums.push_back(s[i] - '0');
	}

	for (int i = 0; i < nums.size(); i++) {
		int here = nums[i] * 2 + carry;
		carry = here / 10;
		nums[i] = here % 10;
	}

	while (carry) {
		nums.push_back(carry % 10);
		carry /= 10;
	}

	reverse(nums.begin(), nums.end());
	string res = "";
	for (int i = 0; i < nums.size(); i++) {
		res += (nums[i] + '0');
	}

	// deb(res);

	return res;
}

int power(string A) {
	string res = "1";

	while (res < A) {
		if (res == A)
			return 1;
		// cout << res << " ";
		res = mult2(res);
	}

	return 1;
}

int solve(int A) {
	// cout << A << endl;
	bool odd = true;
	int curr = 0;

	for (int i = 1; i <= A; i++) {
		curr++;

		if (((i) & (i - 1)) == 0) {
			curr >>= 1;
			odd = !odd;
		}
	}

	cout << curr << " " << odd << endl;
	return 0;
}


int convertToInt(string binary) {
	if (binary.size() == 1)
		return binary[0] - '0';

	int ans = 0;
	for (int i = 0; i < binary.size(); i++) {
		ans *= 2;
		ans += binary[i] - '0';
	}

	return ans;
}


void findTheGray(int n, vector<string> &res) {
	// Base Case -
	if (n == 2) {
		res.push_back("00");
		res.push_back("01");
		res.push_back("11");
		res.push_back("10");
		return;
	}

	// Recursive Case -
	findTheGray(n - 1, res);
	vector<string> temp;

	for (int i = 0; i < res.size(); i++) {
		temp.push_back('0' + res[i]);
	}
	for (int i = res.size() - 1; i >= 0; i--) {
		temp.push_back('1' + res[i]);
	}

	res = temp;
	return;
}

vector<int> grayCode(int A) {
	if (A == 0) {
		return {0};
	}

	if (A == 1) {
		return {0, 1};
	}

	if (A == 2) {
		return {0, 1, 3, 2};
	}

	vector<string> res;
	vector<int> ans;

	findTheGray(A, res);

	for (int i = 0; i < res.size(); i++) {
		ans.push_back(convertToInt(res[i]));
	}

	return ans;
}


class CustomStack {
private:
	int maxSize;
	vector<int> st;
	int top;

public:
	CustomStack(int size) {
		maxSize = size;
		top = -1;
		st = vector<int> (size);
	}

	void push(int x) {
		st[++top] = x;
	}

	int pop() {
		return st[top--];
	}

	int peek() {
		return st[top];
	}

	bool isEmpty() {
		return top == -1;
	}

	bool isFull() {
		return top == maxSize - 1;
	}
};

int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	CustomStack c(10);
	cout << c.isEmpty() << endl;
	c.push(12);
	c.push(14);
	c.push(15);

	cout << c.peek() << endl;
	cout << c.pop() << endl;
	cout << c.peek() << endl;

	return 0;
}