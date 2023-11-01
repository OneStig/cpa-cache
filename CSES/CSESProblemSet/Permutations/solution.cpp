#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << "1" << endl;
	}
	else if (n == 4) {
		cout << "2 4 1 3" << endl;
	}
	else if (n < 4) {

		cout << "NO SOLUTION" << endl;
	}
	else {
		cout << n;
		for (int i = n - 2; i >= 1; i -= 2) {
			cout << " " << i;
		}

		for (int i = n - 1; i >= 1; i-= 2) {
			cout << " " << i;
		}

		cout << endl;
	}
}
