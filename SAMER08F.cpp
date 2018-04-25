#include <bits/stdc++.h>

int main( ) {
	std::ios_base::sync_with_stdio(0);

	long long n;
	while (std::cin >> n, n) {
		std::cout << n * (n + 1) * (2 * n + 1) / 6 << "\n";
	}
}