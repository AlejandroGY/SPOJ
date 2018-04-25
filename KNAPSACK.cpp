#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

int main( ) {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int s, n;
	std::cin >> s >> n;

	std::vector<std::array<int, 2>> v(n + 1);
	for (int i = 0; i < n; ++i) {
		std::cin >> v[i][0] >> v[i][1];
	}

	int memo[2][s + 1];
	int* act = &memo[0][0];
	int* ant = &memo[1][0];
	for (int i = n; i >= 0; --i, std::swap(act, ant)) {
		for (int c = 0; c <= s; ++c) {
			if (i == n) {
				act[c] = 0;
			} else {
				int res = ant[c];
				if (v[i][0] <= c) {
					res = std::max(res, v[i][1] + ant[c - v[i][0]]);
				}
				act[c] = res;
			}
		}
	}
	std::cout << ant[s];
}