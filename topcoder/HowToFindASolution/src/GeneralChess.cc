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
const int MAX = 10000;
// }}}

class GeneralChess
{
public:
    pair<int, int> to_pair(string str)
    {
        int C[2] = {0, 0};
        int pos = 0;
        int sign = 1;
        for (unsigned i = 0; i < str.length(); i++) {
            if (str[i] == ',') {
                C[pos] *= sign;
                pos++;
                sign = 1;
            } else {
                if (str[i] == '-')
                    sign *= -1;
                else
                    C[pos] = C[pos] * 10 + str[i] - '0';
            }
        }

        C[1] *= sign;
        return make_pair(C[0], C[1]);
    }

    string to_s(pair<int, int> sol)
    {
        char buff[30];
        sprintf(buff, "%d,%d", sol.first, sol.second);
        return string(buff);
    }

	vector <string> attackPositions(vector <string> pieces)
	{
        set< pair<int, int> > S;
        map< pair<int, int>, bool> G;
        int dr[] = {-2, -2, -1, +1, 2, 2, +1, -1}; 
        int dc[] = {-1, +1, +2, +2, 1, -1,-2, -2};
        for (string p : pieces) {
            pair<int, int> point = to_pair(p);
            //printf("point = <%d, %d>\n", point.first, point.second);
            G[point] = true;
            int r = point.first;
            int c = point.second;
            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                //if (nr < -MAX || nr > MAX || nc < -MAX || nc > MAX)
                    //continue;
                //printf(">> %d %d\n", nr, nc);
                S.insert(make_pair(nr, nc));
            }
        }

        vector< pair<int, int> > solutions;
        for (auto it : S) {
            if (G.count(it) == 1)
                continue;
            int r = it.first;
            int c = it.second;
            unsigned t = 0;
            for (int i = 0; i < 8; i++) {
                pair<int, int> p;
                p.first = r + dr[i];
                p.second = c + dc[i];
                if (G.count(p) == 1)
                    t++;
            }

            if (t == pieces.size())
                solutions.push_back(it);
        }

        sort(solutions.begin(), solutions.end());

        vector<string> ans;
        for (auto sol : solutions) {
            ans.push_back(to_s(sol));
        }

        return ans;
	}
};

