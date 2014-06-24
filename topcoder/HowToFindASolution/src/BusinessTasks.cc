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

class BusinessTasks
{
public:
	string getTask(vector <string> list, int n)
	{
        int size = list.size();
        int pos = 0;
        while (size > 1) {
            pos = (pos + n - 1) % size;
            for (int i = pos; i + 1 < size; i++)
                list[i] = list[i+1];
            size--;
        }

        return list[0];
	}
};

