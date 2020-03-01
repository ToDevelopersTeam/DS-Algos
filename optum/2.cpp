#include <climits>
#include <cstdio>
#include <cstring>
#include<bits/stdc++.h>

using namespace std;
const int max_value = 200000;

int max (int x, int y) {
  return x > y ? x : y;
}

int min (int x, int y) {
  return x < y ? x : y;
}

int sum (int a[], int start, int end) {
  int res = 0;

  for (int i = start; i <= end; ++i) res += a[i];

  return res;
}

int k_partitioning(int k, int n, int deps[]) {
  int res = max_value;
    int l_min = 0;
    for(int r_min = l_min; r_min < n; ++r_min) {
      int min_sum = sum (deps, l_min, r_min);

      int dp[k][n];
      for (int s = 0; s < k; ++s) {
        for (int q = 0; q < n; ++q) {
          dp[s][q] = max_value;
        }
      }

      dp[0][r_min-l_min] = min_sum;

      for(int p = 1; p < k; ++p) {
        for(int l_max = r_min; l_max < n; ++l_max) {
          for(int r_max = l_max; r_max < n; ++r_max) {
            int max_sum = sum(deps, l_max+1, r_max);

            if (max_sum >= min_sum) {
              dp[p][r_max] = min(dp[p][r_max], max(dp[p-1][l_max], max_sum));
            }

          }
        }
      }

      if (dp[k-1][n-1] == max_value) continue;

      res = min (res, dp[k-1][n-1] - min_sum);
    }
    int tmp[n];
    for (int i = 0; i < n; ++i) {
      int new_idx = i + n - 1;
      tmp[new_idx % n] = deps[i];
    }

    for(int i = 0; i < n; ++i) deps[i] = tmp[i];

  return res;
}

int main(int argc, char* argv[]) {
  int n;
  cin>>n;

  int deps[n];
  for (int i = 0; i < n; ++i) {
    cin>>deps[i];
  }

  cout<<k_partitioning(4, n, deps);

  return 0;
}