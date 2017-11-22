#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
    int nT;
    scanf("%d", &nT);

    while(nT--) {
        int nRows, nCols;
        scanf("%d%d", &nRows, &nCols);
        
        std::vector<std::vector<int> > grid(nRows, std::vector<int>(nCols, 0));
        for(int i = 0; i < nRows; i++) {
            for(int j = 0; j < nCols; j++)
                scanf("%d", &grid[i][j]);
        }

        grid[nRows-1][nCols-1] = 1;
        for(int i = nCols-2; i >= 0; i--) {
            grid[nRows-1][i] = grid[nRows-1][i+1] - grid[nRows-1][i];
            if(grid[nRows-1][i] <= 0)
                grid[nRows-1][i] = 1;
        }
        for(int i = nRows-2; i >= 0; i--) {
            grid[i][nCols-1] = grid[i+1][nCols-1] - grid[i][nCols-1];
            if(grid[i][nCols-1] <= 0)
                grid[i][nCols-1] = 1;
        }

        for(int i = nRows-2; i >= 0; i--) {
            for(int j = nCols-2; j >= 0; j--) {
                grid[i][j] = std::min(grid[i+1][j], grid[i][j+1]) - grid[i][j];
                if(grid[i][j] <= 0)
                    grid[i][j] = 1;
            }
        }

        printf("%d\n", grid[0][0]);
    }
    return 0;
}
