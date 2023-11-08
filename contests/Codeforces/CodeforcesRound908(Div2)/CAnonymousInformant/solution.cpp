#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

//unordered_set<int> adj[200001];
bool seen[200001];

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> b(n);

		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		//memset(adj, 0, sizeof(adj));

		//for (int i = 1; i <= n; i++) {
			//cin >> b[i];

			//if (b[i] <= n) {
				//if (i >= b[i]) {
					//adj[i %].insert(i - b[i])
				//}
				//else {
					//adj[i].insert(i + n - b[i])
				//}
			//}
		//}
		memset(seen, 0, sizeof(seen));
		
		int fail = 0;
		long long lp = n - 1;
		for (int i = 0; i < k; i++) {
			if (b[lp] > n) {
				fail = 1;
				break;
			}	

			if (seen[lp]) {
				break;
			}

			seen[lp] = 1;

			
			lp = lp - b[lp] + n;
			lp %= n;
		}

		cout << (fail ? "No" : "Yes") << endl;
	}
}
