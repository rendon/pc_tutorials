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

struct Country {
    string name;
    int gold, silver, bronze;
    Country()
    {
        gold = 0;
        silver = 0;
        bronze = 0;
    }

    bool operator<(const Country &b) const
    {
        if (gold != b.gold) return gold > b.gold;
        if (silver != b.silver) return silver > b.silver;
        if (bronze != b.bronze) return bronze > b.bronze;
        return name < b.name;
    }
};

class MedalTable
{
public:
    string to_s(int num)
    {
        char buff[15];
        sprintf(buff, "%d", num);
        return string(buff);
    }

	vector <string> generate(vector <string> results)
	{
        map<string, Country> M;
        for (unsigned i = 0; i < results.size(); i++) {
            string tokens[3];
            int pos = 0;
            for (unsigned j = 0; j < results[i].length(); j++) {
                if (results[i][j] == ' ')
                    pos++;
                else
                    tokens[pos] += results[i][j];
            }

            M[tokens[0]].name = tokens[0];
            M[tokens[0]].gold++;

            M[tokens[1]].name = tokens[1];
            M[tokens[1]].silver++;

            M[tokens[2]].name = tokens[2];
            M[tokens[2]].bronze++;
        }

        Country C[55];
        int pos = 0;
        for (auto key : M) {
            C[pos].name = key.second.name;
            C[pos].gold = key.second.gold;
            C[pos].silver = key.second.silver;
            C[pos].bronze = key.second.bronze;
            pos++;
        }

        sort(C, C + pos);
        vector<string> positions;
        for (int i = 0; i < pos; i++) {
            string row = C[i].name + " " + to_s(C[i].gold) + " "
                       + to_s(C[i].silver) + " " + to_s(C[i].bronze);
            positions.push_back(row);
        }

        return positions;
	}
};

