#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long K, L, M, maxVal = 0;
  cin >> K >> L >> M;
  vector<long long> moves = { 1, K, L };
  vector<long long> games(M);

  for(long long i = 0; i < M; i++) {
    cin >> games[i];
    maxVal = std::max(games[i], maxVal);
  }

  vector<bool> win(maxVal+1);
  win[0] = false; // if N is 0 first player loses

  for(long long i = 1; i <= maxVal; i++) {
    win[i] = (win[i-1] == false); // if a player is able to move to a losing
                                  // position, it is in winning position
    if(i >= K && win[i-K] == false)
      win[i] = true;
    if(i >= L && win[i-L] == false)
      win[i] = true;
  }

  for(long long i = 0; i < M; i++)
    cout << (win[games[i]] ? "A" : "B");
  cout << endl;
  return 0;
}
