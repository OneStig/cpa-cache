#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<unordered_set<int> > prereqs(n + 1);
	vector<vector<int> > adj(n + 1);
	unordered_set<int> to_complete;

	for (int i = 1; i <= n; i++) {
		to_complete.insert(i);
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		prereqs[b].insert(a);
		to_complete.erase(b);
	}

	vector<int> ans;

	while (to_complete.size() != 0) {
		int cur = *to_complete.begin();
		to_complete.erase(cur);
		ans.push_back(cur);

		for (int i = 0; i < adj[cur].size(); i++) {
			prereqs[adj[cur][i]].erase(cur);

			if (prereqs[adj[cur][i]].size() == 0) {
				to_complete.insert(adj[cur][i]);
			}
		}
	}

	if (ans.size() < n) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		for (int i = 0; i < ans.size(); i++) {
			if (i != 0) {
				cout << " ";
			}

			cout << ans[i];
		}

		cout << endl;
	}
}
