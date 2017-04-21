#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long getScribes(vector<long long>& books, long long nPages);
void printScribesBooks(vector<long long>& books, long long curIdx, long long nScribes, long long K);

int main() {
  long long T;
  cin >> T;

  while(T--) {
    long long N, K, sumP = 0;
    cin >> N >> K;

    vector<long long> books(N);
    for(long long i = 0; i < N; i++) {
      cin >> books[i];
      sumP += books[i];
    }

    long long start = 0, end = sumP;
    while(start < end) {
      long long mid = (start + end)/2;
      if(getScribes(books, mid) <= K)
        end = mid;
      else
        start = mid+1; 
    }
    printScribesBooks(books, N-1, end, K);
    cout << endl;
  }
  return 0;
}

long long getScribes(vector<long long>& books, long long nPages) {
  long long nScribes = 1, curSum = 0;
  for(long long i = 0; i < books.size(); i++) {
    if(books[i] > nPages) {
      nScribes = INT_MAX;
      break;
    }
    if(curSum + books[i] > nPages) {
      nScribes++;
      curSum = 0;
    }
    curSum += books[i];
  }
  return nScribes;
}

void printScribesBooks(vector<long long>& books, long long curIdx, long long nScribes, long long K) {
  long long curSum = 0, i;
  for( i = curIdx; i >= 0; i--) {
    if(curSum + books[i] > nScribes || i+1 == K-1) {
      printScribesBooks(books, i, nScribes, K-1);
      break;
    }
    curSum += books[i];
  }

  if(i >= 0)
    cout << "/ ";
  for(i = i+1; i <= curIdx; i++)
    cout << books[i] << " ";
}
