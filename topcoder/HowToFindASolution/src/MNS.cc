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

class MNS
{
public:
    int factorial(int n)
    {
        int f = 1;
        for (int i = 2; i <= n; i++)
            f *= i;
        return f;
    }

	int combos(vector <int> N)
	{
        int I[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        int S[6];
        int ans = 0;
        do {
            S[0] = N[I[0]] + N[I[1]] + N[I[2]];
            S[1] = N[I[3]] + N[I[4]] + N[I[5]];
            S[2] = N[I[6]] + N[I[7]] + N[I[8]];
            S[3] = N[I[0]] + N[I[3]] + N[I[6]];
            S[4] = N[I[1]] + N[I[4]] + N[I[7]];
            S[5] = N[I[2]] + N[I[5]] + N[I[8]];
            sort(S, S + 6);
            //printf("%d %d\n", S[0], S[5]);
            if (S[0] == S[5])
                ans++;
        } while (next_permutation(I, I + 9));

        int O[10] = {0};
        for (unsigned i = 0; i < N.size(); i++)
            O[N[i]]++;

        int f = 1;
        for (int i = 0; i < 10; i++)
            if (O[i] > 0)
                f *= factorial(O[i]);

        return ans / f;
	}
};

