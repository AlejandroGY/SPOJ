#include <bits/stdc++.h>

class fenwick_tree {
public:
	fenwick_tree(long long n)
	: mem_(n + 1) {
	}

	void actualiza(long long i, long long v) {
		for (++i; i < mem_.size( ); i += (i & -i)) {
			mem_[i] += v;
		}
	}

	long long cuenta(long long i) {
		long long res = 0;
		for (i += 1; i != 0; i -= (i & -i)) {
			res += mem_[i];
		}
		return res;
	}

private:
	std::vector<long long> mem_;
};

int main( ) {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	long long n;
	std::cin >> n;

	fenwick_tree arbol(n + 2);

	for (long long i = 1; i <= n; ++i) {
		long long t;
		std::cin >> t;
		arbol.actualiza(i, t);
	}

	long long m;
	std::cin >> m;
	for (long long i = 0; i < m; ++i) {
		char op;
		std::cin >> op;

		if (op == 'q') {
			long long ini, fin;
			std::cin >> ini >> fin;
			std::cout << arbol.cuenta(fin) - arbol.cuenta(ini - 1) << "\n";
		} else {
			long long idx, val;
			std::cin >> idx >> val;
			arbol.actualiza(idx, val);
		}
	}
}