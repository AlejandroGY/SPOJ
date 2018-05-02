#include <bits/stdc++.h>

using ll = int64_t;
constexpr ll MAX = 30030;

struct node {
	ll *arr;
	ll tam;
};

ll n, m, last;
ll a, b, c;
ll v[MAX];
node ST[4 * MAX];

void merge(ll m[], ll left[], ll right[], ll ti, ll td) {
	ll i = 0, j = 0, k = 0;
	while (i < ti && j < td) {
		if (left[i] < right[j]) {
			m[k++] = left[i++];
		} else {
			m[k++] = right[j++];
		}
	}
	while (i < ti) {
		m[k++] = left[i++];
	}
	while (j < td) {
		m[k++] = right[j++];
	}
}

void build(ll ini, ll fin, ll nodo) {
	if (ini == fin) {
		ST[nodo].arr = new ll[1];
		ST[nodo].arr[0] = v[ini];
		ST[nodo].tam = 1;
		return;
	}
	
	ll mid = ini + (fin - ini) / 2;
	ll left = (2 * nodo) + 1;
	ll right = (2 * nodo) + 2;
	
	build(ini, mid, left);
	build(mid + 1, fin, right);
	
	ST[nodo].arr = new ll[ST[left].tam + ST[right].tam];
	ST[nodo].tam = ST[left].tam + ST[right].tam;
	merge(ST[nodo].arr, ST[left].arr, ST[right].arr, ST[left].tam, ST[right].tam);
}

ll query(ll ini, ll fin, ll nodo) {
	if (a > fin || b < ini) {
		return 0;
	}
	
	if (a <= ini && fin <= b) {
		auto it = std::upper_bound(ST[nodo].arr, ST[nodo].arr + ST[nodo].tam, c);
		return ST[nodo].arr + ST[nodo].tam - it;
	}
	
	ll mid = ini + (fin - ini) / 2;
	ll left = (2 * nodo) + 1;
	ll right = (2 * nodo) + 2;
	
	return query(ini, mid, left) + query(mid + 1, fin, right);
}

int main( ) {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> v[i];
	}
	
	build(0, n - 1, 0);
	
	std::cin >> m;
	for (int i = 0; i < m; ++i) {
		std::cin >> a >> b >> c;
		
		a ^= last;
		b ^= last;
		c ^= last;
		
		--a, --b;
		last = query(0, n - 1, 0);
		
		std::cout << last << "\n";
	}
}
