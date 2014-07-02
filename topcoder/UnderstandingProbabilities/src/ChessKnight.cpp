#include <bits/stdc++.h>
using namespace std;

double dp[10][10][105];
bool defined[10][10][105];
class ChessKnight {
public:
    double f(int x, int y, int n)
    {
        if (n == 0) {
            return 1;
        }

        double &ans = dp[x][y][n];
        if (defined[x][y][n]) {
            return ans;
        }

        ans = 0;
        int dx[] = {-2, -2, -1, +1, +2, +2, +1, -1};
        int dy[] = {-1, +1, +2, +2, +1, -1, -2, -2};
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx > 0 && nx <= 8 && ny > 0 && ny <= 8) {
                ans += f(nx, ny, n - 1);
            }
        }

        defined[x][y][n] = true;
        ans /= 8;
        return ans;
    }

    double probability(int x, int y, int n)
    {
        memset(defined, false, sizeof defined);
        return f(x, y, n);
    }
};
