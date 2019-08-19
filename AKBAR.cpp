#include <bits/stdc++.h>

struct solve {
   long long pos, dist, soldado;
   solve(long long pos, long long dist, long long soldado)
   : pos(pos), dist(dist), soldado(soldado) {
   }
};

int main( ) {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(nullptr), std::cout.tie(nullptr);

   long long t;
   std::cin >> t;
   while (t--) {
      long long n, r, m;
      std::cin >> n >> r >> m;

      std::vector<long long> adj[n + 1];
      for (long long i = 0; i < r; ++i) {
         long long a, b;
         std::cin >> a >> b;
         adj[a].push_back(b);
         adj[b].push_back(a);
      }

      int res = n;
      std::queue<solve> cola;
      std::vector<long long> memo(n + 1, 0);
      for (long long i = 0; i < m; ++i) {
         long long k, s;
         std::cin >> k >> s;
         cola.push(solve(k, s, k));
         memo[k] = k;
         res -= 1;
      }

      bool continua = true;
      do {
         auto act = cola.front( );
         cola.pop( );

         if (act.dist > 0) {
            for (auto sig : adj[act.pos]) {
               if (!memo[sig]) {
                  memo[sig] = act.soldado;
                  res -= 1;
                  cola.push(solve(sig, act.dist - 1, act.soldado));
               } else if (memo[sig] != act.soldado) {
                  continua = false;
                  break;
               }
            }
         }
         if (!continua) break;
      } while (!cola.empty( ));
      std::cout << ((continua && res == 0) ? "Yes\n" : "No\n");
   }
}
