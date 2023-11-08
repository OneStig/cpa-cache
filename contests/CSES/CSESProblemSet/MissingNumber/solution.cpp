#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int main() {
	int n;
	cin >> n;

	unordered_set<int> fnd;

	for (int i = 1; i < n; i++) {
		int cur;
		cin >> cur;

		fnd.insert(cur);
	}

	for (int i = 1; i<= n; i++) {
		if (fnd.find(i) == fnd.end()) {
			cout << i << endl;
			break;
		}
	}
}
