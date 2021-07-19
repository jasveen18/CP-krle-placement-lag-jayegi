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

void insertAtBottom(stack<int> &st, int element) {
	if (st.empty()) {
		st.push(element);
		return;
	}

	int topEl = st.top(); st.pop();
	insertAtBottom(st, element);

	st.push(topEl);
	return;
}

void reverseStack(stack<int> &st) {
	if (st.empty())
		return;

	int topEl = st.top(); st.pop();
	reverseStack(st);

	insertAtBottom(st, topEl);
	return;
}


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// cout << endl << cntBits({1, 3, 5, 6});
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	while (st.empty() == false) {
		cout << st.top() << endl; st.pop();
	}

	cout << endl;

	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	reverseStack(st);

	while (st.empty() == false) {
		cout << st.top() << endl; st.pop();
	}

	return 0;
}