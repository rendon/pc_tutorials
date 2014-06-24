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

class BridgeCrossing
{
public:
    void solve(int state, int turn, int cost)
    {
        if (state == 0) {
            min_cost = min(min_cost, cost);
        } else {
            if (turn == 0) {
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if ((state & (1 << i)) && (state & (1 << j))) {
                            int s = state;
                            s ^= (1 << i);
                            s ^= (1 << j);
                            solve(s, (turn + 1) % 2, cost + max(T[i], T[j]));
                        }
                    }
                }
            } else {
                for (int i = 0; i < n; i++) {
                    if (!(state & (1 << i))) {
                        solve(state ^ (1 << i), (turn + 1) % 2, cost + T[i]);
                    }
                }
            }
        }
    }

	int minTime(vector <int> times)
	{
        min_cost = INF;
        n = times.size();
        T = times;
        if (n == 1) {
            return times[0];
        } else {
            solve((1 << n) - 1, 0, 0);
            return min_cost;
        }
	}

private:
    vector<int> T;
    int min_cost;
    int n;
};

