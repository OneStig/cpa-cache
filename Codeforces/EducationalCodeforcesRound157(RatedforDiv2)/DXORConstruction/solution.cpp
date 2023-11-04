#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n - 1);

	for (int i = 0; i < n - 1; i++) {
		cin >> a[i];
	}

	int start = 4;
	cout << start << " ";
	for (int i = 0; i < n - 1; i++) {
		start = start ^ a[i];
		cout << start << " ";
	}

	cout << endl;
}
