#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
  int T;
  cin >> T;

  while(T--) {
    vector<string> board(3);
    for(int i = 0; i < 3; i++)
      cin >> board[i];

    int nX = 0, nO = 0;
    int nHorizontal = 0, nVertical = 0;
    bool bError = false;
    char winner = '\0';

    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        if(board[i][j] == 'O') nO++;
        if(board[i][j] == 'X') nX++;
      }

      if(board[i] == "OOO" || board[i] == "XXX") {
        if(nHorizontal) {bError=true; break; }
        nHorizontal = i+1;

        if(nVertical && winner != board[i][0]) { bError=true; break; }
        winner = board[i][0];
      }

      char verticalArr[] = {board[0][i], board[1][i], board[2][i], '\0'}; 
      string verticalOrder(verticalArr);
      if(verticalOrder == "OOO" || verticalOrder == "XXX") {
        if(nVertical) { bError=true; break; }
        nVertical = i+1;
        if(nHorizontal && winner != board[0][i]) { bError=true; break; }
        winner = board[0][i];
      }
    }

    if(nO > nX || nX - nO > 1)
      bError = true;

    bool bDiagonal = (board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
                     (board[0][2] == board[1][1] && board[1][1] == board[2][0]) &&
                     (board[1][1] == 'O' || board[1][1] == 'X');
    if(!nHorizontal && !nVertical && bDiagonal)
      winner = board[1][1];

    if(bDiagonal && (nHorizontal == 1 || nHorizontal == 3 || nVertical == 1 || nVertical == 3)) {
      bError = true;
    }

    if(nHorizontal && nVertical && bDiagonal) bError = true;
    if(winner == 'X' && nO == nX)
      {bError = true;  }
    if(winner == 'O' && nX != nO)
      {bError = true; }

    cout << (bError ? "no" : "yes") << endl;
  }
  return 0;
}
