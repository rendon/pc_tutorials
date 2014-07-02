#include <bits/stdc++.h>
using namespace std;

class PipeCuts {
    public:
    double probability(vector<int> W, int L) {
        sort(W.begin(), W.end());
        int n = W.size();
        double total = n * (n - 1) / 2;
        double favorable = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((W[i] > L) || (W[j] - W[i] > L) || (100 - W[j] > L)) {
                    favorable++;
                }
            }
        }

        return favorable / total;
    }
};
