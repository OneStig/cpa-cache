#include <bits/stdc++.h>

using namespace std;

vector<int> adj[(int)(1e5 + 1)];

void dfs(int x, int par, int ply, vector<int> &dist) {
	dist[x] = ply;

	for (int i = 0; i < adj[x].size(); i++) {
		if (adj[x][i] != par) {
			dfs(adj[x][i], x, ply + 1, dist);
		}
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;

		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}

	vector<int> d1(n), d2(n);

	dfs(0, -1, 0, d1);

	int startA = max_element(d1.begin(), d1.end()) - d1.begin();

	dfs(startA, -1, 0, d1);

	int startB = max_element(d1.begin(), d1.end()) - d1.begin();

	dfs(startB, -1, 0, d2);

	for (int i = 0; i < n; i++) {
		d1[i] = max(d1[i], d2[i]);
	}

	sort(d1.begin(), d1.end());

	int ans;
	for (int k = 1; k <= n; k++) {
		if (k != 1) {
			cout << " ";
		}

		if (k > n) {
			cout << n;
			continue;
		}

		while (ans < n -1 && d1[ans] < k) {
			ans++;
		}
		
		cout << (1 + n - ans) << endl;
	}
}
