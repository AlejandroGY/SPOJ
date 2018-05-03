#include <bits/stdc++.h>

int main( ) {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	int v[n];
	for(int i = 0; i < n; ++i) {
		std::cin >> v[i];
	}

	int k;
	std::cin >> k;
	std::multiset<int> ms;
	std::multiset<int>::iterator it[n];

	for (int i = 0; i < n; ++i) {
		if (i >= k) {
			auto ans = ms.end( );
			std::cout << *(--ans) << " ";
			ms.erase(it[i - k]);
			it[i] = ms.insert(v[i]);
		} else {
			it[i] = ms.insert(v[i]);
		}
	}
	
	auto ans = ms.end( );
	std::cout << *(--ans) << "\n";
}