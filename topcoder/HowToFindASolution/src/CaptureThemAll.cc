// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

const double EPS = 1e-9;
const int INF = 1 << 30;
const int MAX = 1000;
// }}}
struct State {
    int row, col, status, length;
    State() { }
    State(int r, int c, int s, int l)
    {
        row = r;
        col = c;
        status = s;
        length = l;
    }
};

class CaptureThemAll
{
public:
	int fastKnight(string knight, string rook, string queen)
	{
        int rc = rook[0] - 'a';
        int rr = rook[1] - '1';
        int qc = queen[0] - 'a';
        int qr = queen[1] - '1';
        int kc = knight[0] - 'a';
        int kr = knight[1] - '1';
        int dr[] = {-2, -2, -1, +1, +2, +2, +1, -1};
        int dc[] = {-1, +1, +2, +2, +1, -1, -2, -2};
        memset(visited, false, sizeof visited);
        queue<State> Q;
        Q.push(State(kr, kc, 3, 0));
        int ans = -1;
        while (!Q.empty()) {
            State front = Q.front();
            Q.pop();
            int r = front.row;
            int c = front.col;
            int s = front.status;
            int l = front.length;
            if (visited[r][c][s])
                continue;
            visited[r][c][s] = true;

            if (r == rr && c == rc && (s & 1))
                s ^= 1;

            if (r == qr && c == qc && (s & 2))
                s ^= 2;

            if (s == 0) {
                ans = l;
                break; 
            }

            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nr >= 8 || nc < 0 || nc >= 8)
                    continue;
                Q.push(State(nr, nc, s, l + 1));
            }
        }

        return ans;
	}

private:
    bool visited[8][8][4];
};

