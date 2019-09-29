#include<bits/stdc++.h>

std::string reconstruye(std::string& s, std::string& t, int m, int n) {
   int longitud[m + 1][n + 1];
   for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= n; ++j) {
         if (i == 0 || j == 0) {
            longitud[i][j] = 0;
         } else if (s[i - 1] == t[j - 1]) {
            longitud[i][j] = longitud[i - 1][j - 1] + 1;
         } else {
            longitud[i][j] = std::max(longitud[i - 1][j], longitud[i][j - 1]);
         }
      }
   }

   int i = m, j = n;
   int tam = longitud[m][n];
   std::string solucion = "";
   while (i > 0 && j > 0) {
      if (s[i - 1] == t[j - 1]) {
         solucion += s[i - 1];
         i -= 1, j -= 1;
      } else if (longitud[i - 1][j] > longitud[i][j - 1]) {
         i -= 1;
      } else {
         j -= 1;
      }
   }
   std::reverse(solucion.begin( ), solucion.end( ));
   return solucion;
}

int main( ) {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(nullptr), std::cout.tie(nullptr);

   std::string s, t;
   while (std::cin >> s >> t) {
      std::string lcs = reconstruye(s, t, s.size( ), t.size( ));
      std::string res = "";
      int t1 = s.size( ), t2 = t.size( ), t3 = lcs.size( );
      int i1 = 0, i2 = 0, i3 = 0;
      while (i1 < t1 || i2 < t2 || i3 < t3) {
         if (s[i1] == lcs[i3] && t[i2] == lcs[i3]) {
            res += lcs[i3];
            i1++, i2++, i3++;
         } else if (s[i1] != lcs[i3]) {
            res += s[i1++];
         } else if (t[i2] != lcs[i3]) {
            res += t[i2++];
         }
      }
      while (i1 < t1) res += s[i1++];
      while (i2 < t2) res += t[i2++];
      std::cout << res << "\n";
   }
}
