#include <bits/stdc++.h>
using namespace std;

double dp[10][10][105];
bool defined[10][10][105];
class ChessKnight {
public:
    double f(int x, int y, int n)
    {
        if (n == 0) {
            return 1;
        }

        double &ans = dp[x][y][n];
        if (defined[x][y][n]) {
            return ans;
        }

        ans = 0;
        int dx[] = {-2, -2, -1, +1, +2, +2, +1, -1};
        int dy[] = {-1, +1, +2, +2, +1, -1, -2, -2};
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx > 0 && nx <= 8 && ny > 0 && ny <= 8) {
                ans += f(nx, ny, n - 1);
            }
        }

        defined[x][y][n] = true;
        ans /= 8;
        return ans;
    }

    double probability(int x, int y, int n)
    {
        memset(defined, false, sizeof defined);
        return f(x, y, n);
    }
};

//region Test
// CUT begin
const string COLOR_OFF  = "\e[0m";
const string GREEN      = "\e[0;32m";
const string RED        = "\e[0;31m";
const string BOLD_WHITE = "\e[1;37m";

ifstream data(".ChessKnight.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool double_equal(const double &a, const double &b) { return b==b && a==a && fabs(b - a) <= 1e-9 * max(1.0, fabs(a) ); }

bool do_test(int x, int y, int n, double __expected) {
    time_t startClock = clock();
    ChessKnight *instance = new ChessKnight();
    double __result = instance->probability(x, y, n);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_equal(__expected, __result)) {
        cout << GREEN << "PASSED!" << COLOR_OFF << " (" << elapsed << " seconds)" << endl;
        cout << "------------------------------------------------------------" << endl;
        return true;
    }
    else {
        cout << RED << "FAILED!" << COLOR_OFF << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        cout << "------------------------------------------------------------" << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int x;
        from_stream(x);
        int y;
        from_stream(y);
        int n;
        from_stream(n);
        next_line();
        double __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << BOLD_WHITE << "  Testcase #" << cases - 1 << COLOR_OFF << " ... ";
        if ( do_test(x, y, n, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << GREEN << "PASS: " << passed;
        if (passed < cases)
            cout << RED << "\tFAIL: " << cases - passed;
        cout << COLOR_OFF << endl;

        int T = time(NULL) - 1404339404;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 450 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "ChessKnight (450 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
//endregion
