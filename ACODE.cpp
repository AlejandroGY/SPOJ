#include <bits/stdc++.h>

int n;
constexpr int MAX = 5002;
std::string cad;
uint64_t memo[MAX];

uint64_t solve(int i) {
	if (i == n) {
		return 1;
	}
	if (cad[i] == '0') {
		return 0;
	}
	
	if (memo[i]) {
		return memo[i];
	}
	
	memo[i] = solve(i + 1);
	if (i < n - 1 && cad[i] == '1') {
		memo[i] += solve(i + 2);
	} else if (i < n - 1 && cad[i] == '2' && cad[i + 1] <= '6') {
		memo[i] += solve(i + 2);
	}
	return memo[i];
}

int main( ) {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	while (std::cin >> cad) {
		if (cad == "0") break;
		n = cad.size( );
		std::fill(memo, memo + MAX, 0);
		std::cout << solve(0) << '\n';
	}
}
