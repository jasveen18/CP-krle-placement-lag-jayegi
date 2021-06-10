#define ll long long
ll fastModExp(ll a, ll b, ll mod) {
	ll res = 1;

	while (b) {
		if (b & 1) {
			res = (res * a) % mod;
		}

		a = (a * a) % mod;
		b = b >> 1;
	}

	return res;
}