#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

bool checkReordered(vector<long long>& arr) {
  long long curElem = 1;
  bool bPossible = true;
  stack<long long> sideLane;

  for(long long i = 0; i < arr.size(); i++) {
    // check sidelane :
    while(!sideLane.empty() && sideLane.top() == curElem) {
      curElem++;
      sideLane.pop();
    }

    if(curElem == arr[i]) {
      curElem++;
    }
    else if(!sideLane.empty() && sideLane.top() < arr[i]) {
      bPossible = false;
      break;
    }
    else {
      sideLane.push(arr[i]);
    }
  }

  return bPossible;
}

int main() {
  long long N = 1;
  while(N != 0) { 
    cin >> N;
    if(N == 0) break;
    vector<long long> arr;
    for(long long i = 0; i < N; i++) {
      long long tmp;
      cin >> tmp;
      arr.push_back(tmp);
    }

    cout << (checkReordered(arr) ? "yes" : "no") << endl;
  }
  return 0;
}
