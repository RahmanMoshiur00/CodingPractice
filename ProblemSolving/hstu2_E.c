#include <stdio.h>

void read_minesweeper(int, int);
void resolve_field(int, int, int, int);
void print_minesweeper(int, int, int);

int minesweeper[100][100];

int main() {
    int nRows, nCols, i, j, tc = 1;

    while (1) {
        scanf("%d %d", &nRows, &nCols);

        if (!nRows && !nCols) break;

        read_minesweeper(nRows, nCols);

        for (i = 0 ; i < nRows ; i++)
            for (j = 0 ; j < nCols ; j++)
                if (minesweeper[i][j] == -1)
                    resolve_field(i, j, nRows, nCols);

        if (tc > 1) printf("\n");
        print_minesweeper(nRows, nCols, tc++);

    }

    return 0;
}

void read_minesweeper(int nRows, int nCols) {
    int i, j;
    char line[100];

    for (i = 0 ; i < nRows ; i++) {
        scanf("%s", line);
        for (j = 0 ; j < nCols ; j++)
            if (line[j] == '*') minesweeper[i][j] = -1;
            else minesweeper[i][j] = 0;
    }

}

void resolve_field(int i, int j, int nRows, int nCols) {
    int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int k;

    for (k = 0 ; k < 8 ; k++) {
        if (i + dr[k] < 0 || i + dr[k] >= nRows || j + dc[k] < 0 || j + dc[k] >= nCols) continue;
        if (minesweeper[i + dr[k]][j + dc[k]] != -1)
            minesweeper[i + dr[k]][j + dc[k]] += 1;
    }
}

void print_minesweeper(int nRows, int nCols, int tc) {
    int i, j;

    printf("Field #%d:\n", tc++);
    for (i = 0 ; i < nRows ; i++) {
        for (j = 0 ; j < nCols ; j++)
            if (minesweeper[i][j] == -1) printf("*");
            else printf("%d", minesweeper[i][j]);
        printf("\n");
    }
}
