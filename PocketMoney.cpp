#include <iostream>
#include <string>
#include <climits>
#include <vector>
using namespace std;

long long process(long long a, long long b, char op) { return op == '*' ? a*b : a+b; }

pair<long long, long long> findChainResult(vector<long long>& operands, vector<char>& operators) {
  pair<long long, long long> ans;
  vector<vector<long long> > dp_min(operands.size()+1, vector<long long>(operands.size()+1, INT_MAX));
  vector<vector<long long> > dp_max(operands.size()+1, vector<long long>(operands.size()+1, INT_MIN));

  for(long long i = 0; i < operands.size(); i++)
    dp_min[i][i] = dp_max[i][i] = operands[i];

  for(long long L = 2; L <= operands.size(); L++) {
    for(long long start = 0; start < operands.size()-L+1; start++) {
      long long end = start+L-1;
      
      for(long long k = start; k < end; k++) {
        dp_min[start][end] = std::min(dp_min[start][end],
                               process(dp_min[start][k], dp_min[k+1][end], operators[k]));
        
        dp_max[start][end] = std::max(dp_max[start][end],
                               process(dp_max[start][k], dp_max[k+1][end], operators[k]));
      }
    }
  }

  ans.first  = dp_max[0][operands.size()-1];
  ans.second = dp_min[0][operands.size()-1];
  return ans;
}

int main() {
  long long T;
  cin >> T;

  while(T--) {
    string expr;
    cin >> expr;
    vector<char> operators;
    vector<long long> operands;
    for(long long i = 0; i < expr.length(); i++) {
      if(i%2 == 0) operands.push_back(expr[i]-'0');
      else         operators.push_back(expr[i]);
    }

    pair<long long, long long> ans = findChainResult(operands, operators);
    cout << ans.first << " " << ans.second << endl;
  }
  return 0;
}
