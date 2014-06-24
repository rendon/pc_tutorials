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

class TallPeople
{
public:
    vector<int> split(string row)
    {
        vector<int> tokens;
        int num = 0;
        for (unsigned i = 0;  i < row.length(); i++) {
            if (row[i] == ' ') {
                tokens.push_back(num);
                num = 0;
            } else {
                num = num * 10 + (row[i] - '0');
            }
        }

        tokens.push_back(num);

        return tokens;
    }


	vector <int> getPeople(vector <string> people)
	{
        vector< vector<int> > M;
        for (unsigned i = 0; i < people.size(); i++)
            M.push_back(split(people[i]));

        vector<int> shorts;
        vector<int> talls;
        for (unsigned i = 0; i < M.size(); i++) {
            int minn = INF;
            for (unsigned j = 0; j < M[i].size(); j++)
                minn = min(minn, M[i][j]);

            shorts.push_back(minn);
        }

        for (unsigned i = 0; i < M[0].size(); i++) {
            int maxx = 0;
            for (unsigned j = 0; j < M.size(); j++)
                maxx = max(maxx, M[j][i]);
            talls.push_back(maxx);
        }

        int a = 0;
        for (unsigned i = 0; i < shorts.size(); i++)
            a = max(a, shorts[i]);

        int b = INF;
        for (unsigned i = 0; i < talls.size(); i++)
            b = min(b, talls[i]);

        vector<int> result;
        result.push_back(a);
        result.push_back(b);

        return result;
	}
};

