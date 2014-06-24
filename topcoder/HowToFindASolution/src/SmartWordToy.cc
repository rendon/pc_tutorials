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
#include <unordered_map>
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
    char a, b, c, d;
    int length;
    State()
    {
    }

    State(char aa, char bb, char cc, char dd, int l)
    {
        a = aa;
        b = bb;
        c = cc;
        d = dd;
        length = l;
    }
};

class SmartWordToy
{
public:
    inline char prev(char c)
    {
        return (c - 'a' + 26 - 1) % 26 + 'a';
    }

    inline char next(char c)
    {
        return (c - 'a' + 1) % 26 + 'a';
    }

    inline bool isValid(char a, char b, char c, char d)
    {
        string k = "";
        k += a;
        k += b;
        k += c;
        k += d;
        return F.count(k) == 0;
    }

	int minPresses(string start, string finish, vector <string> forbid)
	{
        memset(visited, false, sizeof visited);
        for (unsigned i = 0; i < forbid.size(); i++) {
            string tokens[4];
            int pos = 0;
            for (unsigned j = 0; j < forbid[i].length(); j++) {
                if (forbid[i][j] == ' ')
                    pos++;
                else
                    tokens[pos] += forbid[i][j];
            }

            for (unsigned a = 0; a < tokens[0].length(); a++) {
                for (unsigned b = 0; b < tokens[1].length(); b++) {
                    for (unsigned c = 0; c < tokens[2].length(); c++) {
                        for (unsigned d = 0; d < tokens[3].length(); d++) {
                            string s = "";
                            s += tokens[0][a];
                            s += tokens[1][b];
                            s += tokens[2][c];
                            s += tokens[3][d];
                            F[s] = true;
                        }
                    }
                }
            }
        }

        int ans = -1;
        queue<State> Q;
        Q.push(State(start[0], start[1], start[2], start[3], 0));
        while (!Q.empty()) {
            State front = Q.front();
            Q.pop();

            char a = front.a;
            char b = front.b;
            char c = front.c;
            char d = front.d;
            int l = front.length;
            if (visited[a-'a'][b-'a'][c-'a'][d-'a'])
                continue;
            if (!isValid(a, b, c, d)) {
                //printf("%c %c %c %c\n", a, b, c, d);
                continue;
            }

            visited[a-'a'][b-'a'][c-'a'][d-'a'] = true;

            if (a == finish[0] && b == finish[1] &&
                c == finish[2] && d == finish[3]) {
                ans = l;
                break;
            }
                
            Q.push(State(prev(a), b, c, d, l + 1));
            Q.push(State(next(a), b, c, d, l + 1));
            Q.push(State(a, prev(b), c, d, l + 1));
            Q.push(State(a, next(b), c, d, l + 1));
            Q.push(State(a, b, prev(c), d, l + 1));
            Q.push(State(a, b, next(c), d, l + 1));
            Q.push(State(a, b, c, prev(d), l + 1));
            Q.push(State(a, b, c, next(d), l + 1));
        }

        return ans;
	}

private:
    unordered_map<string, bool> F;
    bool visited[26][26][26][26];
};

