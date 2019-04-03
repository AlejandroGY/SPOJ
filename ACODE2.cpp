#include <bits/stdc++.h>

int n;
std::string s;
long long memo[5001];

long long solve(int i) {
   if (i >= n) {
      return 1;
   }

   if (memo[i]) {
      return memo[i];
   }

   if (s[i] == '0') {
      return 0;
   }

   memo[i] = solve(i + 1);
   if (i < n - 1 && s[i] == '1') {
      memo[i] += solve(i + 2);
   }
   if (i < n - 1 && s[i] == '2' && s[i + 1] <= '6') {
      memo[i] += solve(i + 2);
   }
   return memo[i];
}

int main( ) {
   std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   std::cout.tie(0);

   std::cin >> s;
   while (s != "0") {
      std::fill(memo, memo + 5001, 0);
      n = s.size( );
      std::cout << solve(0) << "\n";

      std::cin >> s;
   }
}