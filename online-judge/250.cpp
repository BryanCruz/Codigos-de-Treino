#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

#define MAX 55

#define DEFINITIVE_INF 50000
#define RELATIVE_INF 4999

#define R 0
#define D 1
#define L 2
#define U 3


typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int n_col, n_lin;
int start_col, start_lin;
int final_col, final_lin;

int grid[MAX][MAX][4];
char start_dir_name[10];

void calc_pd() {
    for (int i = 1; i < n_lin; i++) {
        for (int j = 1; j < n_col; j++) {
            if (grid[i][j][0] == DEFINITIVE_INF || grid[i][j][0] == 0)continue;

            int d_right = grid[i][j][R];
            int d_left = grid[i][j][L];
            int d_down = grid[i][j][D];
            int d_up = grid[i][j][U];

            for (int d = 1; grid[i][j-d][0] != DEFINITIVE_INF && d <= 3; d++) {
                d_left = min(d_left, grid[i][j-d][L]);
            }
            for (int d = 1; grid[i-d][j][0] != DEFINITIVE_INF && d <= 3; d++) {
                d_up = min(d_up, grid[i-d][j][U]);
            }
            for (int d = 1; grid[i][j+d][0] != DEFINITIVE_INF && d <= 3; d++) {
                d_right = min(d_right, grid[i][j+d][R]);
            }
            for (int d = 1; grid[i+d][j][0] != DEFINITIVE_INF && d <= 3; d++) {
                d_down = min(d_down, grid[i+d][j][D]);
            }

            grid[i][j][L] = 1+min(d_left, min(d_right+2, min(d_down+1, d_up+1)));
            grid[i][j][R] = 1+min(d_left+2, min(d_right, min(d_down+1, d_up+1)));
            grid[i][j][U] = 1+min(d_left+1, min(d_right+1, min(d_down+2, d_up)));
            grid[i][j][D] = 1+min(d_left+1, min(d_right+1, min(d_down, d_up+2)));
        }
    }
}

int main (void) {
    ios_base::sync_with_stdio(false);

    while(scanf("%d %d", &n_lin, &n_col) != EOF && n_lin != 0 && n_col != 0) {
        memset(grid, 0, sizeof grid);

        for (int i = 1; i <= n_lin; i++) {
            for (int j = 1; j <= n_col; j++) {
                scanf("%d", &grid[i][j][0]);
            }
        }

        for (int i = 0; i <= n_lin; i++) {
            for (int j = 0; j <= n_col; j++) {
                if (grid[i][j][0] == 1) {
                    for (int k = 0; k < 4; k++) {
                        grid[i][j][k] = DEFINITIVE_INF;

                        if (i-1 >= 0)
                            grid[i-1][j][k] = DEFINITIVE_INF;

                        if (j-1 >= 0)
                            grid[i][j-1][k] = DEFINITIVE_INF;

                        if(i-1 >= 0 && j-1 >= 0)
                            grid[i-1][j-1][k] = DEFINITIVE_INF;
                    }
                } else if (i == 0 || i == n_lin ||  j == n_col || j == 0) {
                    for (int k = 0; k < 4; k++) {
                        grid[i][j][k] = DEFINITIVE_INF;
                    }
                } else {
                    for (int k = 0; k < 4; k++) {
                        grid[i][j][k] = RELATIVE_INF;
                    }
                }
            }
        }

        scanf("%d %d %d %d %s", &start_lin, &start_col, &final_lin, &final_col, start_dir_name);


        if(grid[final_lin][final_col][0] != DEFINITIVE_INF) {
            for (int i = 0; i < 4; i++) {
                    grid[final_lin][final_col][i] = 0;
            }
        }

        for (int t = 0; t < 51; t++) {
            calc_pd();
        }

        char dir_c = start_dir_name[0];
        int direction = dir_c == 'n' ? U : (dir_c == 's' ? D : (dir_c == 'w' ? L : R));
        int r = grid[start_lin][start_col][direction];
        printf("%d\n", r > n_lin + n_col ? -1 : r);
    }

    return 0;
}

