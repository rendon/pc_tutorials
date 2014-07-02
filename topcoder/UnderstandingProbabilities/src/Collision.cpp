#include <bits/stdc++.h>
using namespace std;

class Collision {
public:
    double probability(vector<int> A, int ids)
    {
        int n = A.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += A[i];
        }

        if (sum > ids) {
            return 0;
        }

        double p = 1;
        double r = ids;
        // Without memory = With replacement
        for (int i = 0; i < sum; i++) {
            p *= (r / ids);
            r--;
        }

        double q = 1;
        r = ids;
        // With memory = Without replacement
        for (int i = 0; i < n; i++) {
            double all = ids;
            for (int j = 0; j < A[i]; j++) {
                q *= r / all;
                r--;
                all--;
            }
        }
        return abs(p - q);
    }
};
