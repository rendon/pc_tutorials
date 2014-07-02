#include <bits/stdc++.h>
using namespace std;
const int MAX = 1005;
double dp[MAX][11];
bool defined[MAX][11];
int T;
class NestedRandomness {
public:
    double f(int n, int nest)
    {
        if (n == 0 && nest > 0) { return 0; }
        if (nest == 0) {
            return n == T; 
        }

        double &ans = dp[n][nest];
        if (defined[n][nest])  {
            return ans;
        }

        ans = 0;
        for  (int i = 0; i < n; i++) {
            ans += f(i, nest - 1) / n;
        }

        defined[n][nest] = true;
        return ans;
    }

    double probability(int N, int nestings, int target)
    {
        T = target;
        memset(defined, false, sizeof defined);
        return f(N, nestings);
    }
};
