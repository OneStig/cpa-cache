#include <bits/stdc++.h>

using namespace std;


const int MOD = 1000000007;

int main() {
	int t;
	cin >> t;

	while (t--) {
		long long n;
		cin >> n;

		long long ans = (((n * (n + 1)) % MOD * (4 * n - 1))) % MOD * 337;
		ans %= MOD;
		
		cout << ans << endl;
	}
}

// 1: 1
// 2: 7
// 3: 22
// 4: 50
// 5: 95
// 6: 161
// 7: 252
//
//
// 
