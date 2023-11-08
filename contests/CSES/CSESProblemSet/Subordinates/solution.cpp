#include <bits/stdc++.h>

using namespace std;

vector<int> subs[200001];
vector<int> ans;

void dfs(int x) {
	for (int i = 0; i < subs[x].size(); i++) {
		dfs(subs[x][i]);
		ans[x] += 1 + ans[subs[x][i]];
	}
}

int main() {
	int n;
	cin >> n;

	ans.resize(n + 1);

	for (int i = 2; i <= n; i++) {
		int sup;
		cin >> sup;

		subs[sup].push_back(i);
	}

	dfs(1);

	for (int i = 1; i <= n; i++) {
		if (i != 1) {
			cout << " ";
		}
		cout << ans[i];
	}

	cout << endl;
}
