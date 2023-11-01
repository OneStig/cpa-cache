#include <bits/stdc++.h>

using namespace std;

int main() {
	string seq;
	cin >> seq;

	char last = '0';
	int cur = 1;
	int mx = 1;

	for (int i = 0; i < seq.size(); i++) {
		if (seq[i] == last) {
			cur++;
			mx = max(mx, cur);
		}
		else {
			last = seq[i];
			cur = 1;
		} 
	}

	cout << mx << endl;
}
