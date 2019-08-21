#include <bits/stdc++.h>

struct solve {
   int x, y, d;
   solve(int x, int y, int d)
   : x(x), y(y), d(d){
   }
};

int bfs(std::pair<int, int> ini, std::pair<int, int> fin) {
   std::pair<int, int> lista[] = {
      { -2, -1 }, { -1, -2 },
      { -1,  2 }, { -2,  1 },
      {  1, -2 }, {  2, -1 },
      {  2,  1 }, {  1,  2 }
   };

   std::queue<solve> cola;
   cola.push(solve(ini.first, ini.second, 0));

   do {
      auto act = cola.front( );
      cola.pop( );

      if (act.x == fin.first && act.y == fin.second) {
         return act.d;
      }

      for (auto v : lista) {
         int dx = v.first + act.x;
         int dy = v.second + act.y;

         if (dx >= 0 && dx <= 7 && dy >= 0 && dy <= 7) {
            cola.push(solve(dx, dy, act.d + 1));
         }
      }
   } while (!cola.empty( ));
}

int main( ) {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(nullptr), std::cout.tie(nullptr);

   int t;
   std::cin >> t;
   while (t--) {
      std::string a, b;
      std::cin >> a >> b;

      std::pair<int, int> ini = { a[0] - 'a', a[1] - '1' };
      std::pair<int, int> fin = { b[0] - 'a', b[1] - '1' };
      std::cout << bfs(ini, fin) << "\n";
   }
}
