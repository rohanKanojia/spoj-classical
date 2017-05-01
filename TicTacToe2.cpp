#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkHorizontal(vector<string>& board, char op) {
  for(int i = 0; i < 3; i++)
    if(board[i][0] == op && board[i][1] == op && board[i][2] == op)
      return true;
  return false;
}

bool checkVertical(vector<string>& board, char op) {
  for(int i = 0; i < 3; i++)
    if(board[0][i] == op && board[1][i] == op && board[2][i] == op)
      return true;
  return false;
}

bool checkDiagonal(vector<string>& board, char op) {
  bool bDiagonal = (board[0][0] == op && board[1][1] == op && board[2][2] == op) ||
                   (board[0][2] == op && board[1][1] == op && board[2][0] == op);
  return bDiagonal;
}

int main() {
  while(true) {
    char aCell;
    string aLine;
    vector<string> board(3);
    cin >> aLine;
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        board[i].push_back(aLine[i*3 + j]);
      }
    }

    if(aLine == "end") break;

    int nX = 0, nO = 0;
    bool bError = false, bXWin = false, bOWin = false;

    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        if(board[i][j] == 'O') nO++;
        if(board[i][j] == 'X') { nX++; continue; }
      }
    }
    
    if(nO > nX)
      bError = true;
    if((nX-nO) > 1)
      bError = true;
    bXWin = (checkVertical(board, 'X') || checkHorizontal(board, 'X') || 
            checkDiagonal(board, 'X'));
    bOWin = (checkVertical(board, 'O') || checkHorizontal(board, 'O') ||
            checkDiagonal(board, 'O'));

    if(bXWin) {
      if(nX-nO != 1)
        bError = true;
    }
    if(bOWin) {
      if(nX-nO != 0)
        bError = true;
    }
    if(bXWin && bOWin)
      bError = true;

    if(bXWin == false && bOWin == false) {
      if(nX+nO != 9)
        bError = true;
    }
    cout << (bError ? "invalid" : "valid") << endl;
  }
  return 0;
}
