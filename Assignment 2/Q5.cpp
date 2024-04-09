#include <iostream>
using namespace std;

   int solve(vector <int> v, int m){
      int n = v.size();
      vector<vector<int> > dp1(n + 1, vector<int>(m + 1));
      vector<vector<int> > dp2(n + 1, vector<int>(m + 1));
      for (int i = 0; i < n; i++) {
         for (int j = 0; j <= m; j++) {
            int x = v[i];
            if (j < m)
            dp2[i + 1][j + 1] = max(dp2[i + 1][j + 1], dp1[i]
            [j] + x);
            dp1[i + 1][j] = max({ dp1[i + 1][j], dp2[i][j],
            dp1[i][j] });
         }
      }
      return max(dp1[n][m], dp2[n][m]);
   }
   int maxSizeSlices(vector<int>& slices) {
      int n = slices.size();
      int ret = 0;
      ret = max(solve(vector<int>(slices.begin() + 1,
      slices.end()), n / 3), slices[0] + solve(vector<int>(slices.begin() +
      2, slices.end() - 1), n / 3 - 1));
      return ret;
   }

main(){
   vector<int> v = {1,2,3,4,5,6};
   cout << (maxSizeSlices(v));
}