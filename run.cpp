/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
* Ab m game m hu. *
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


void threeWayPartition(vector<int>& array, int a, int b) {
	int partitionIndex = 0;
	int pivotEl = a;
	int n = array.size();

	for (int i = 0; i < n; i++) {
		if (array[i] <= pivotEl) {
			swap(array[i], array[partitionIndex]);
			partitionIndex++;
		}
	}

	pivotEl = b;
	for (int i = partitionIndex; i < n; i++) {
		if (array[i] <= pivotEl) {
			swap(array[i], array[partitionIndex]);
			partitionIndex++;
		}
	}

	for (int i = 0; i < array.size(); i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	cout << array.size() << endl;
	return;
}


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--)
	{
		int N;
		cin >> N;

		vector<int> array(N);
		unordered_map<int, int> ump;

		for (int i = 0; i < N; i++) {
			cin >> array[i];
			ump[array[i]]++;
		}

		int a, b;
		cin >> a >> b;

		vector<int> original = array;

		int k1 = 0, k2 = 0, k3 = 0;
		int kk1 = 0; int kk2 = 0; int kk3 = 0;

		for (int i = 0; i < N; i++)
		{
			if (original[i] > b)
				k3++;
			else if (original[i] <= b and original[i] >= a)
				k2++;
			else if (original[i] < b)
				k1++;
		}

		threeWayPartition(array, a, b);

		for (int i = 0; i < k1; i++)
		{
			if (array[i] < b)
				kk1++;
		}

		for (int i = k1; i < k1 + k2; i++)
		{
			if (array[i] <= b and array[i] >= a)
				kk2++;

		}

		for (int i = k1 + k2; i < k1 + k2 + k3; i++)
		{
			if (array[i] > b)
				kk3++;
		}
		bool ok = 0;
		cout << k1 << " " << kk1 << endl;
		cout << k2 << " " << kk2 << endl;
		cout << k3 << " " << kk3 << endl;

		if (k1 == kk1 and k2 == kk2 and k3 == kk3)
			ok = 1;

		cout << "ok: " << ok << endl;
		for (int i = 0; i < array.size(); i++)
			ump[array[i]]--;

		for (int i = 0; i < array.size(); i++)
			if (ump[array[i]] != 0)
				ok = 0;

		if (ok)
			cout << 1 << endl;
		else
			cout << 0 << endl;

		sort(array.begin(), array.end());
		for (int i = 0; i < array.size(); i++) {
			cout << array[i] << " ";
		}
		cout << endl;


	}

	return 0;
}

