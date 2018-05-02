#include <bits/stdc++.h>

std::map<uint64_t, uint64_t> memo;

uint64_t solve(uint64_t n) {
	if (n < 12) {
		return n;
	}
	if (memo[n]) {
		return memo[n];
	}
	return memo[n] = solve(n / 2) + solve(n / 3) + solve(n / 4);
}

int main( ) {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	uint64_t n;
	while (std::cin >> n) {
		std::cout << solve(n) << "\n";
	}
}