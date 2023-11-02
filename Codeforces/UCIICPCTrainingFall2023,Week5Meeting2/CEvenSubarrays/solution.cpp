#include <bits/stdc++.h>

using namespace std;

int bsums[32][200005];

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < 32; i++) {
			bsums[i][0] = 0;
		}	

		for (int i = 1; i <= n; i++) {
			int cur;
			cin >> cur;

			for (int p = 0; p < 32; p++) {
				bsums[p][i] = cur % 2;
				cur = cur >> 1;

				bsums[p][i] += bsums[p][i - 1];
			}
		}
	}
}
