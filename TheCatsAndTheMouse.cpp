#include <iostream>
#include <cmath>
using namespace std;

int main() {
  long long ROWS, COLS;
  cin >> ROWS >> COLS;

  long long T;
  cin >> T;
  while(T--) {
    long long mR, mC, c1R, c1C, c2R, c2C;
    bool bPossible = false;
    cin >> mR >> mC >> c1R >> c1C >> c2R >> c2C;

    mR--; mC--; c1R--; c1C--; c2R--; c2C--;


    if((mR <= c1R && mR <= c2R) || (mR >= c1R && mR >= c2R) ||
       (mC >= c1C && mC >= c2C) || (mC <= c1C && mC <= c2C)) {
      bPossible = true;
    }
    else {
      long long mTop = mR, mBottom = ROWS-1-mR, mLeft = COLS-1-mC, mRight = mC;
      long long cTop, cBottom, cLeft, cRight;
      cTop  = std::min(c1R + abs(mC-c1C), c2R + abs(mC-c2C));
      cLeft = std::min(abs(mR-c1R)+ abs(COLS-1-c1C),  abs(mR-c2R) + abs(COLS-1-c2C));
      cBottom = std::min(abs(ROWS-1-c1R)+abs(mC-c1C), abs(ROWS-1-c2R)+abs(mC-c2C));
      cRight = std::min(abs(mR-c1R)+c1C, abs(mR-c2R)+c2C);

      bPossible = (mTop < cTop || mBottom < cBottom || mLeft < cLeft || mRight < cRight);
    }
    cout << (bPossible ? "YES" : "NO") << endl;
  }
  return 0;
}
