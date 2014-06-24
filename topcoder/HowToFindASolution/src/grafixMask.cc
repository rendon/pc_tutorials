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
const int MAX_R = 400;
const int MAX_C = 600;
// }}}

class grafixMask
{
public:
	vector <int> sortedAreas(vector <string> rectangles)
	{
        memset(G, false, sizeof G);
        for (unsigned i = 0; i < rectangles.size(); i++) {
            string tokens[4];
            int pos = 0;
            for (unsigned j = 0; j < rectangles[i].length(); j++) {
                if (rectangles[i][j] == ' ')
                    pos++;
                else
                    tokens[pos] += rectangles[i][j];
            }

            int x0 = atoi(tokens[0].c_str());
            int y0 = atoi(tokens[1].c_str());
            int x1 = atoi(tokens[2].c_str());
            int y1 = atoi(tokens[3].c_str());

            //printf("%d %d %d %d\n", x0, y0, x1, y1);
            for (int a = x0; a <= x1; a++)
                for (int b = y0; b <= y1; b++)
                    G[a][b] = true;
        }

        vector<int> areas;
        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};
        for (int i = 0; i < MAX_R; i++) {
            for (int j = 0; j < MAX_C; j++) {
                if (G[i][j]) continue;
                int A = 0;
                stack< pair<int, int> > S;
                S.push(make_pair(i, j));
                //printf("i = %d j = %d\n", i, j);
                while (!S.empty()) {
                    pair<int, int> top = S.top();
                    S.pop();
                    int r = top.first;
                    int c = top.second;
                    if (G[r][c])
                        continue;
                    A++;    
                    G[r][c] = true;
                    for (int k = 0; k < 4; k++) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        if (nr < 0 || nr >= MAX_R || nc < 0 || nc >= MAX_C)
                            continue;
                        S.push(make_pair(nr, nc));
                    }
                }

                //printf("area = %d\n", A);
                areas.push_back(A);
            }
        }

        sort(areas.begin(), areas.end());
        return areas;
	}

private:
    bool G[MAX_R+5][MAX_C+5];
};

