#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100001];

int m_depth = 0;
int deepest = 0;

void dfs(int x, int par, int ply, vector<int> &dist) {
	dist[x] = ply;

	if (ply > m_depth) {
		m_depth = ply;
		deepest = x;
	}

	for (int i = 0; i < adj[x].size(); i++) {
		if (adj[x][i] == par) {
			continue;
		}

		dfs(adj[x][i], x, ply + 1, dist);
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> a_depths(n + 1), b_depths(n + 1);

	dfs(1, -1, 0, a_depths);

	int end_a = deepest;
	m_depth = 0;

	dfs(end_a, -1, 0, a_depths);

	int end_b = deepest;

	dfs(end_b, -1, 0, b_depths);

	vector<int> mx_depths(n);

	for (int i = 1; i <= n; i++) {
		mx_depths[i - 1] = max(a_depths[i], b_depths[i]);
	}

	sort(mx_depths.begin(), mx_depths.end());
	
	int rem_ind = 0;
	for (int k = 1; k <= n; k++) {
		if (k != 1) {
			cout << " ";
		}

		if (k > m_depth) {
			cout << n;
			continue;
		}

		auto it = lower_bound(mx_depths.begin() + rem_ind, mx_depths.end(), k);

		if (it == mx_depths.end()) {
			cout << n;
			continue;
		}

		rem_ind = it - mx_depths.begin();

		cout << 1 + rem_ind;
	}
}
