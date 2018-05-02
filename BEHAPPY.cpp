#include <bits/stdc++.h>

int m, n, res;
std::array<int, 2> arr[102];

void solve(int i, int c) {
	if (i == m) {
		if (c == 0) {
			++res;
		}
		return;
	}

	for (int j = arr[i][0]; j <= c && j <= arr[i][1]; ++j) {
		solve(i + 1, c - j);
	}
}

int main( ) {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> m >> n) {
		if (m == 0 && n == 0) {
			break;
		}

		for (int i = 0; i < m; ++i) {
			std::cin >> arr[i][0] >> arr[i][1];
		}

		res = 0;
		solve(0, n);
		std::cout << res << "\n";
	}
}