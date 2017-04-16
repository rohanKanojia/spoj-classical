#include <iostream>
#include <algorithm>
using namespace std;

#define ROWS 1234
#define COLS 5678

int main() {
  int R[ROWS+1], C[COLS+1], cR[ROWS+1], cC[COLS+1], x, y;
  char op;
  for(int i = 0; i < ROWS+1; i++)
    R[i] = cR[i] = i;
  for(int i = 0; i < COLS+1; i++)
    C[i] = cC[i] = i;

  while(cin >> op) {
    switch(op) {
      case 'R':
        cin >> x >> y;
        std::swap(R[x], R[y]);
        cR[R[x]] = x;
        cR[R[y]] = y;
        break;
      case 'C':
        cin >> x >> y;
        std::swap(C[x], C[y]);
        cC[C[x]] = x;
        cC[C[y]] = y;
        break;
      case 'Q':
        cin >> x >> y;
        cout << (R[x]-1)*COLS + C[y] << endl;
        break;
      case 'W':
        cin >> x;
        int p = (x-1 + COLS) / COLS;
        int q = (x-1) % COLS + 1;
        cout << cR[p] << " " << cC[q] << endl;
    }
  }
  return 0;
}
