#include <bits/stdc++.h>

constexpr int MAX = 250002;

int arr[MAX];
int tree[4 * MAX];
int res[MAX];
int pos[MAX];

void build(int ini, int fin, int nodo) {
	if (ini == fin) {
		tree[nodo] = 1;
		return;
	}
	int mid = ini + (fin - ini) / 2;
	int left = (2 * nodo) + 1;
	int right = (2 * nodo) + 2;
	build(ini, mid, left);
	build(mid + 1, fin, right);
	tree[nodo] = tree[left] + tree[right];
}

int query(int ini, int fin, int nodo, int val) {
	if (ini == fin) {
		return ini;
	}
	int mid = ini + (fin - ini) / 2;
	int left = (2 * nodo) + 1;
	int right = (2 * nodo) + 2;
	if (val <= tree[left]) {
		return query(ini, mid, left, val);
	} else {
		return query(mid + 1, fin, right, val - tree[left]);
	}
}

void update(int ini, int fin, int nodo, int idx) {
	if (ini == fin) {
		tree[nodo] = 0;
		return;
	}
	int mid = ini + (fin - ini) / 2;
	int left = (2 * nodo) + 1;
	int right = (2 * nodo) + 2;
	if (idx <= mid) {
		update(ini, mid, left, idx);
	} else {
		update(mid + 1, fin, right, idx);
	}
	tree[nodo] = tree[left] + tree[right];
}

int main( ) {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::iota(pos, pos + MAX, 1);

	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		for (int i = 0; i < n; ++i) {
			std::cin >> arr[i];
		}
		build(0, n - 1, 0);
		for (int i = n - 1; i >= 0; --i) {
			int idx = query(0, n - 1, 0, i + 1 - arr[i]);
			res[i] = idx;
			update(0, n - 1, 0, idx);
		}
		for (int i = 0; i < n; ++i) {
			std::cout << pos[res[i]] << " ";
		}
		std::cout << "\n";
	}
}