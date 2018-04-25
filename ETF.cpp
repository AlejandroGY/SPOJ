#include <bits/stdc++.h>
#define end '\n'

long long phi(long long n) {
	long long res = n;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
			}
			res -= res / i;
		}
	}
	if (n > 1) {
		res -= res / n;
	}
	return res;
}

int main( ) {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t;
	std::cin >> t;

	while (t--) {
		long long n;
		std::cin >> n;
		std::cout << phi(n) << end;
	}
}