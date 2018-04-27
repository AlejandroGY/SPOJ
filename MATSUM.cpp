#include <bits/stdc++.h>

struct FenwickTree2D {
	std::vector<std::vector<int>> a;
	int n, m;

	FenwickTree2D(int n, int m)
	: n(n), m(m), a(n, std::vector<int>(m)) {
	}

	void update(int x, int y, int val) {
		int y1;
		while (x < n) {
			y1 = y;
			while (y1 < m) {
				a[x][y1] += val;
				y1 |= y1 + 1;
			}
			x |= x + 1;
		}
	}

	int get(int x, int y) {
		int res = 0;
		int y1;
		while (x >= 0) {
			y1 = y;
			while (y1 >= 0) {
				res += a[x][y1];
				y1 = (y1 & (y1 + 1)) - 1;
			}
			x = (x & (x + 1)) - 1;
		}
		return res;

	}

	int get(int x1, int y1, int x2, int y2) {
		int res = get(x2, y2);
		res -= get(x1 - 1, y2);
		res -= get(x2, y1 - 1);
		res += get(x1 - 1, y1 - 1);
		return res;
	}
};

int main( ) {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int cases;
	std::cin >> cases;
	for (int ti = 0; ti < cases; ++ti) {
		if (ti > 0) {
			std::cout << "\n";
		}

		int n;
		std::cin >> n;
		FenwickTree2D arbol(n + 1, n + 1);

		std::string op;
		std::cin >> op;
		while (op != "END") {
			
			if (op == "SUM") {
				int x1, y1, x2, y2;
				std::cin >> x1 >> y1 >> x2 >> y2;
				std::cout << arbol.get(x1, y1, x2, y2) << "\n";
			} else if (op == "SET") {
				int x, y, num;
				std::cin >> x >> y >> num;			
				arbol.update(x, y, -arbol.get(x, y, x, y));
				arbol.update(x, y, num);
			}
			std::cin >> op;
		}
	}
}
