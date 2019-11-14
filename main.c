#include <stdio.h>


int maze(char[8][8], int x, int y, int x2, int y2,int visited[8][8]);
int main() {
    char a[8][8] = {
            {'x', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'x', ' ', 'x', ' ', ' ', ' ', ' ', ' '},
            {'x', ' ', 'x', ' ', ' ', ' ', ' ', ' '},
            {'x', ' ', 'x', 'x', 'x', 'x', 'x', ' '},
            {'x', ' ', 'x', ' ', ' ', ' ', ' ', ' '},
            {'x', ' ', 'x', 'x', 'x', 'x', 'x', ' '},
            {'x', ' ', 'x', ' ', ' ', ' ', ' ', ' '},
            {'x', 'x', 'x', 'x', 'x', ' ', 'x', 'G'},
    };
    int visited[8][8] = {{0}};
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            visited[i][j] = -1;
        }
    }

    int solve = maze(a, 1, 0, -1, -1,visited);
    printf("Can solve %d", solve);
    return 0;
}

int maze(char a[8][8], int x, int y, int x2, int y2,int visited[8][8]) {
    printf("Trying %d,%d from %d,%d\n", x, y, x2, y2);
    if (x < 0 || x > 7)return -1;
    if (y < 0 || y > 7)return -1;
    if (a[y][x] == 'x')return -1;
    if (a[y][x] == 'G')return 1;

    int contains = visited[y][x] == 1 ? 1 : -1;

    if(contains == 1)return -1;
    visited[y][x] = 1;

    int l, r, d, u;

    l = x - 1 != x2 ? maze(a, x - 1, y, x, y,visited) : -1;
    r = x + 1 != x2 ? maze(a, x + 1, y, x, y,visited) : -1;
    d = y - 1 != y2 ? maze(a, x, y - 1, x, y,visited) : -1;
    u = y + 1 != y2 ? maze(a, x, y + 1, x, y,visited) : -1;

    if (l == 1 || r == 1 || d == 1 || u == 1)return 1;
    return -1;
}