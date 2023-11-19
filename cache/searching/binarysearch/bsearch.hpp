int n, x;
int array[1];

///begin
int l = 0, r = n - 1;
while (l <= r) {
	int k = (r + l) / 2;

	if (array[k] == x) {
		// x is at position k
	}

	if (array[k] > x)
		r = k - 1;
	else
		l = k + 1;
}
