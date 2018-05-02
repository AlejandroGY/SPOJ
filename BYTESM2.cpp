#include <bits/stdc++.h>

int main( ) {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t;
	std::cin >> t;

	while (t--) {
		int n, m;
		std::cin >> n >> m;

		int mat[n][m];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				std::cin >> mat[i][j];
			}
		}

		for (int i = n - 2; i >= 0; --i) {
			for (int j = 0; j < m; ++j) {
				if (j == 0) {
					mat[i][j] += std::max(mat[i + 1][j], mat[i + 1][j + 1]);
				} else if (j == m - 1) {
					mat[i][j] += std::max(mat[i + 1][j], mat[i + 1][j - 1]);
				} else {
					mat[i][j] += std::max({ mat[i + 1][j], mat[i + 1][j - 1], mat[i + 1][j + 1] });
				}
			}
		}
		std::cout << *std::max_element(&mat[0][0], &mat[0][m]) << "\n";
	}
}