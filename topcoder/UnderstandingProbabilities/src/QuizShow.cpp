#include <bits/stdc++.h>
using namespace std;

class QuizShow {
    public:
    int wager(vector<int> scores, int wager1, int wager2)
    {
        double total = 8;
        double prob = 0;
        int myWager = 0;
        for (int w = 0; w <= scores[0]; w++) {
            double favorable = 0;
            for (int a = -1; a <= 1; a++) {
                if (a == 0) { continue; }
                for (int b = -1; b <= 1; b++) {
                    if (b == 0) { continue; }
                    for (int c = -1; c <= 1; c++) {
                        if (c == 0) { continue; }
                        int s0 = w * a + scores[0];
                        int s1 = wager1 * b + scores[1];
                        int s2 = wager2 * c + scores[2];
                        if (s0 > s1 && s0 > s2) {
                            favorable++;
                        }
                    }
                }
            }

            if (favorable / total > prob) {
                prob = favorable / total;
                myWager = w;
            }
        }

        return myWager;
    }
};
