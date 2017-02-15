#include <stack>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

long long largestRectangle(vector<long long>& histograms, long long N);
void popElementAndCheck(stack<long long>& st, long long i, long long& maxAr, vector<long long>& histograms);

int main() {
  while(1) {
    long long N;
    cin >> N;
    if(N == 0) break;

    vector<long long> histograms(N);
    for(long long i = 0; i < N; i++)
      cin >> histograms[i];

    cout << largestRectangle(histograms, N) << endl;
  }
  
  return 0;
}

long long largestRectangle(vector<long long>& histograms, long long N) {
  long long maxAr = INT_MIN, i = 0;
  stack<long long> st;

  while(i < N) {
    if(st.empty() || histograms[i] >= histograms[st.top()])
      st.push(i++);
    else 
      popElementAndCheck(st, i, maxAr, histograms);
  }

  while(!st.empty()) {
    popElementAndCheck(st, i, maxAr, histograms);
  }
  return maxAr;
}

void popElementAndCheck(stack<long long>& st, long long i, long long& maxAr, vector<long long>& histograms) {
  long long leftEnd = st.top();
  st.pop();
  long long length = st.empty() ? i : (i-1 - st.top());
  maxAr = std::max(maxAr, length * histograms[leftEnd]);
}
