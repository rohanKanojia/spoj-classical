#include <iostream>
#include <climits>
#include <vector>
using namespace std;

long long dp[10000];               
long long getMinimumPrice(vector<long long>& price, vector<long long>& weight, long long W);

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long wtEmptyPig, wtFilledPig, nCoins, ans;
    vector<long long> weight, price;
    cin >> wtEmptyPig >> wtFilledPig;
    cin >> nCoins;
    for(long long i = 0; i < nCoins; i++) {
      long long a, b;
      cin >> a >> b;
      price.push_back(a);
      weight.push_back(b);
    }
    
    ans = getMinimumPrice(price, weight, wtFilledPig-wtEmptyPig); 
    if(ans == -1) {
      cout << "This is impossible." << endl;
    }
    else {
      cout << "The minimum amount of money in the piggy-bank is "<< ans << "." << endl;
    }
  }
}

long long getMinimumPrice(vector<long long>& price, vector<long long>& weight, long long W) {
  dp[0] = 0;
  for(long long i = 1; i <= W; i++) {
    dp[i] = -1;
    for(long long j = 0; j < weight.size(); j++) {
      if(i >= weight[j] && dp[i-weight[j]] != -1) {
        if(dp[i] == -1)
          dp[i] = price[j] + dp[i - weight[j]];
        else
          dp[i] = std::min(dp[i], price[j] + dp[i-weight[j]]);
      }
    }
  }

  return dp[W]; 
}
