#include <bits/stdc++.h>
using namespace std;

class BirthdayOdds {
    public:
    int minPeople(int minOdds, int daysInYear)
    {
        double goal = 1 - minOdds / 100.0;
        double prob = 1;
        int count = 0;
        double r = daysInYear;
        while (prob > goal) {
            prob *= (r / daysInYear);
            r--;
            count++;
        }

        return count;
    }
};
