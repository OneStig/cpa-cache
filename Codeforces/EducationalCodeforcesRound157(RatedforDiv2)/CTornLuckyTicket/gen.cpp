#include <bits/stdc++.h>
#include <random>

using namespace std;

int generateRandomNumber() {
	std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(10001, 99999); // define the range 
												   //
    return distr(gen); // Generate a random number
}

int main() {
	cout << 200000 << endl;
 
	for (int i = 0; i < 200000; i++) {
		if (i != 0) {
			cout << " ";
		}
		cout << generateRandomNumber();
	}
	cout << endl;
}
