#include <iostream>
#include <string>
#include <stdexcept>
#include <stdexcept>
#include <climits>
#define forn(i, n) for (int i = 0; i < n; i++) 
using namespace std;

int rawScores[3][3], D, W, matchOutcome[3][3], calcedScores[3][3], group1[3], group2[3];
string names[3];
bool matchOutcome_isFilled[3][3];

void load() {
    cin >> W >> D;
    forn(i, 3) forn(k, 3) cin >> rawScores[k][i];
    names[0] = "Alpha";
    names[1] = "Beta";
    names[2] = "Gamma";
}

int circleIndex(int i) {
    i = i % 3;
    if (i < 0) {
        i += 3;
    }
    return i;
}

int theOther(int x, int y) {
    forn(i, 3) if (i != x && i != y) return i;
    throw runtime_error("");
}

// a recursive algorithm to calculate matchOutcome
void calculate() {
    matchOutcome[0][2] = rawScores[1][0] - matchOutcome[0][1];
    matchOutcome[1][2] = rawScores[2][2] - matchOutcome[0][2];
    matchOutcome[1][0] = rawScores[1][1] - matchOutcome[1][2];
    matchOutcome[2][0] = rawScores[2][0] - matchOutcome[1][0];
    matchOutcome[2][1] = rawScores[1][2] - matchOutcome[2][0];
}

bool isCorrect() {
    bool hasWrong = false;
    hasWrong = (matchOutcome[0][1] + matchOutcome[0][2] != rawScores[1][0]) || hasWrong;
    hasWrong = (matchOutcome[0][2] + matchOutcome[1][2] != rawScores[2][2]) || hasWrong;
    hasWrong = (matchOutcome[1][2] + matchOutcome[1][0] != rawScores[1][1]) || hasWrong;
    hasWrong = (matchOutcome[1][0] + matchOutcome[2][0] != rawScores[2][0]) || hasWrong;
    hasWrong = (matchOutcome[2][0] + matchOutcome[2][1] != rawScores[1][2]) || hasWrong;
    hasWrong = (matchOutcome[2][1] + matchOutcome[0][1] != rawScores[2][1]) || hasWrong;
    return !hasWrong;
}

void flattern() {
    group1[0] = matchOutcome[0][1];
    group1[1] = matchOutcome[1][2];
    group1[2] = matchOutcome[2][0];
    group2[0] = matchOutcome[0][2];
    group2[1] = matchOutcome[1][0];
    group2[2] = matchOutcome[2][1];
}

void checkSum() {
    if (matchOutcome[0][1] + matchOutcome[2][1] != rawScores[2][1]) {
        cout << "Impossible" << endl;
        exit(0);
    }
}


// print the outcome using matchOutcome variable
void printOutcome() {
    forn(x, 3) {
        int y = circleIndex(x+1);
        printf("%s %d - %d %s\n", names[x].c_str(), matchOutcome[x][y], matchOutcome[y][x], names[y].c_str());
    }
    exit(0);
}

int main() {
    load();
    // start with one of the outcome, use checkSum() to check if the input data is possible
    matchOutcome[0][1] = 0;
    calculate();
    checkSum();
    flattern();
    int lowerBound = 0;
    forn(i, 3) if (group1[i] < lowerBound) lowerBound = group1[i];
    lowerBound = -lowerBound;
    int upperBound = INT_MAX;
    forn(i, 3) if (group2[i] < upperBound) upperBound = group2[i];
    // printf("lowerBound: %d\nupperBound: %d\n", lowerBound, upperBound);

    for (int i = lowerBound; i <= upperBound; i++) {
        calcedScores[0][0] = 0;
        calcedScores[0][1] = 0;
        calcedScores[0][2] = 0;
        matchOutcome[0][1] = i;
        calculate();
        // if (matchOutcome[0][2] < 0) continue;
        // if (matchOutcome[1][0] < 0) continue;
        // if (matchOutcome[1][2] < 0) continue;
        // if (matchOutcome[2][0] < 0) continue;
        // if (matchOutcome[2][1] < 0) continue;
        forn(x, 3) {
            long long y = circleIndex(x+1);
            if (matchOutcome[x][y] == matchOutcome[y][x]) {
                calcedScores[0][x] += D;
                calcedScores[0][y] += D;
            } else if (matchOutcome[x][y] > matchOutcome[y][x]) {
                calcedScores[0][x] += W;
            } else {
                calcedScores[0][y] += W;
            }
        }
        bool isValidOutcome = true;
        forn(x, 3) {
            if (calcedScores[0][x] != rawScores[0][x]) {
                isValidOutcome = false;
                break;
            }
        }
        if (isValidOutcome) printOutcome();
    }

    cout << "Impossible" << endl;
    return 0;
}   