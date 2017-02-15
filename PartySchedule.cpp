#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long knapSackDP(vector<long long>& wt, vector<long long>& val, long long W, long long N, long long& minCost) {
  vector<vector<long long> > table(N+1, vector<long long>(W+1, 0));
  vector<vector<bool> > keepTable(N+1, vector<bool>(W+1, false));
  
  /* i : possible items, j : possible capacities of knapsack */
  for(long long i = 1; i < N+1; i++) {
    for(long long j = 1; j < W+1; j++) {
      if(wt[i-1] > j) {
        table[i][j] = table[i-1][j];
        keepTable[i][j] = false;
      }
      else {
        // maximum of the possibilities :
        // 1. if we don't pick current element
        // 2. if we pick the current element
        table[i][j] = std::max(table[i-1][j], val[i-1] + table[i-1][j - wt[i-1]]);
        keepTable[i][j] = true;
      }
    }
  }
  
  // finding minimum cost :
  minCost = W;
  while(table[N][minCost] == table[N][W]) minCost--;


  minCost = minCost + 1; // since array index starts from 0
  return table[N][W];
}

int main() {
  while(1) {
    long long W, K, maxFun, minCost;
    vector<long long> wt, val;
    cin >> W >> K;
    if(W == 0 && K == 0) break;

    for(long long i = 0; i < K; i++) {
      long long tmp1, tmp2;
      cin >> tmp1 >> tmp2;
      wt.push_back(tmp1);
      val.push_back(tmp2);
    }
    maxFun = knapSackDP(wt, val, W, K, minCost);

    cout << minCost << " " << maxFun << endl;
  }
  return 0;
}
