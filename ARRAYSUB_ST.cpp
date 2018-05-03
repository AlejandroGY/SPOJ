#include <bits/stdc++.h>

constexpr int MAX = 100010;

int n, k, ti, tj;
int v[MAX];
int ST[4 * MAX];

void build(int ini, int fin, int nodo) {
	if (ini == fin) {
		ST[nodo] = v[ini];
		return;
	}

	int mid = ini + (fin - ini) / 2;
	int left = (2 * nodo) + 1;
	int right = (2 * nodo) + 2;

	build(ini, mid, left);
	build(mid + 1, fin, right);
	ST[nodo] = std::max(ST[left], ST[right]);
}

int query(int ini, int fin, int nodo) {
	if (tj < ini || fin < ti) {
		return -(1 << 20);
	}

	if (ti <= ini && fin <= tj) {
		return ST[nodo];
	}

	int mid = ini + (fin - ini) / 2;
	int left = (2 * nodo) + 1;
	int right = (2 * nodo) + 2;

	int q1 = query(ini, mid, left);
	int q2 = query(mid + 1, fin, right);
	return std::max(q1, q2);
}

int main( ) {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> n;
	for(int i = 0; i < n; ++i) {
		std::cin >> v[i];
	}
	build(0, n - 1, 0);

	std::cin >> k;
	for (int i = 0; i <= n - k; ++i) {
		ti = i, tj = i + k - 1;
		std::cout << query(0, n - 1, 0) << " ";
	}
}