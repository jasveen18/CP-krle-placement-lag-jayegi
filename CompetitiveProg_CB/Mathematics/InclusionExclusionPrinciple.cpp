/******************************************
We have to get the count of numbers < 1000 divisible by 2, 3, and 5.

We will use inclusion principal -
|A union B union C| = |A| + |B| + |C| - |A u B| - |A u C| - |B u C| + |A u B u C|
Here A - numbers divisible by 2, B - by 3, C - by 5.

Inclusion principle follows this trend - for even length "-ve", for odd length "+ve"
******************************************/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{

  // Compute the subsets of the prime numbers given.
  vector<ll> primes {2, 3, 5, 7, 11, 13, 17, 19};

  // Test Cases
  ll t; cin >> t;
  while (t--) {

    // Take the input.
    ll n;
    cin >> n;
    ll ans = 0;

    // Count of subsets
    ll subsets = (1 << 8) - 1;

    // Iterating over all the subsets
    for (ll i = 1; i <= subsets; i++) {

      // Denominator
      ll denom = 1ll;
      // To check if the number of setbits is even or odd for inclusion or exclusion.
      ll setBits = __builtin_popcount(i);

      // Making the denominator
      for (ll j = 0; j <= 7; j++) {
        if (i & (1 << j)) {
          denom = denom * primes[j];
        }
      }

      // Include or Exclude?
      if (setBits & 1) {
        ans += n / denom;
      }
      else {
        ans -= n / denom;
      }
    }

    cout << ans << endl;
  }

  return 0;
}