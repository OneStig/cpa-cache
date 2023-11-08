#include <bits/stdc++.h>

using namespace std;

int main() {
	string encrypt;
	cin >> encrypt;

	int mid = encrypt.size() / 2;

	int left = 0;
	int right = 0;

	for (int i = 0; i < mid; i++) {
		left += encrypt[i] - 'A';
		right += encrypt[mid + i] - 'A';
	}

	for (int i = 0; i < mid; i++) {
		encrypt[i] = (encrypt[i] - 'A' + left) % 26;
		encrypt[i + mid] = (encrypt[i + mid] - 'A' + right) % 26;
		encrypt[i] = ((encrypt[i] + encrypt[i + mid]) % 26) + 'A';
	}

	for (int i = 0; i < mid; i++) {
		cout << encrypt[i];
	}

	cout << endl;
}
