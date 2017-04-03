#include <cstdio>
using namespace std;

#define SIZE 1001
char arr[SIZE][SIZE];
int isVisited[SIZE][SIZE];

void bfs(int i, int j, int& nGroup, int ROWS, int COLS) {
  if(i >= 0 && j >= 0 && i < ROWS && j < COLS) { 
    if(!isVisited[i][j]) {
      isVisited[i][j] = nGroup;

      if(arr[i][j] == 'S')         bfs(i+1, j, nGroup, ROWS, COLS);
      else if(arr[i][j] == 'N')    bfs(i-1, j, nGroup, ROWS, COLS);
      else if(arr[i][j] == 'E')    bfs(i, j+1, nGroup, ROWS, COLS);
      else if(arr[i][j] == 'W')    bfs(i, j-1, nGroup, ROWS, COLS);
      isVisited[i][j] = nGroup;
    }
    else
      nGroup = isVisited[i][j];
  }
}

int main() {
  int ROWS, COLS;
  scanf("%d%d", &ROWS, &COLS);

  for(int i = 0; i < ROWS; i++)
    scanf("%s", &arr[i]);

  int ans = 0, prev = 0;
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      if(!isVisited[i][j]) {
        ans = prev + 1;
        bfs(i, j, ans, ROWS, COLS);
        if(prev < ans) // if any new group found
          prev++;
      }
    }
  }
  printf("%d\n", prev);
  
  return 0;
}
