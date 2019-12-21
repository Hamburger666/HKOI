#include <iostream>
#include <string>
#include <stdexcept>
#include <stdexcept>
#include <climits>
#define forn(i, n) for (long long i = 0; i < n; i++) 
using namespace std;

long long rawScores[3][3], D, W, matchOutcome[3][3], calcedScores[3][3];
string names[3];
bool matchOutcome_isFilled[3][3];
// in rawSocres, [0][x] is the total points, [1][x] is the win, [2][x] is the loss
// in matchOutcome, [X][Y] is the result of x in X x - y Y.

/* A note on data structure:
    I used list and indexes whenever possible to reduce code duplication because that
    means I can use the indicies to loop through similar commands.

    A brief explanation on the variables:
        Indicies are widely used for the teams. Generally, 0 is team alpha, 1 is beta, 2 is gamma. 
        rawScores: the data directely input from the problem. 
            rawScores[0][X] is the total points for team X, i.e. P_X. e.g. rawScores [0][1] is P_B.
            rawScores[1][X] is the number of goals scored for team X.
            rawScores[2][X] is the number of goals conceded of team X.
        matchOutcome: one possible outcome as calculated using the input data. This variable is
        modified once every main iteration and is used to check whether the outcome 
        would produce the same points as those given in the input data.
            matchOutcome[X][Y] is the points team X scored against Y. 
        matchOutcome_isFilled: whether a cell in matchOutcome is already calculated for a given
        iteration. Used for a recursive algorithm. 
        calculatedScores: the scores calculated using matchOutcome. If the outcome is correct, 
        this should be identical with rawScores.
*/

// reset the variable for a new iteration
void resetMatchOutcome() {
    forn(i, 3) forn(k, 3) {
        matchOutcome_isFilled[i][k] = false;
        calcedScores[i][k] = 0;
    }
    forn(i, 3) matchOutcome_isFilled[i][i] = true;
    matchOutcome_isFilled[0][1] = true;
}

// load the input data
void load() {
    cin >> W >> D;
    forn(i, 3) forn(k, 3) cin >> rawScores[k][i];
    resetMatchOutcome();
    names[0] = "Alpha";
    names[1] = "Beta";
    names[2] = "Gamma";
}

// given any index that is circular, return the equivalent index that is within 3.
long long circleIndex(long long i) {
    i = i % 3;
    if (i < 0) {
        i += 3;
    }
    return i;
}

// given two teams, return the team that is not the two teams.
long long theOther(long long x, long long y) {
    forn(i, 3) if (i != x && i != y) return i;
    throw runtime_error("");
}

// a recursive algorithm to calculate matchOutcome
void propergate(long long x, long long y) {
    long long otherIndex = theOther(x, y);
    if (!matchOutcome_isFilled[x][otherIndex]) { // if the other team x played against is not already calculated
        // calculate
        matchOutcome[x][otherIndex] = rawScores[1][x] - matchOutcome[x][y];
        matchOutcome_isFilled[x][otherIndex] = true;
        // recurse
        propergate(x, otherIndex);
    }
    if (!matchOutcome_isFilled[otherIndex][y]) { // if the other team y played against is not already calculated
        // calculate
        matchOutcome[otherIndex][y] = rawScores[2][y] - matchOutcome[x][y];
        matchOutcome_isFilled[otherIndex][y] = true;
        //recurse
        propergate(otherIndex, y);
    }
}

// check if the sum of the outcomes matches the input data. That is, can the input data be correctly reconstructed
// with matchOutcome. The sum should not match only if the input data is impossible. So it is used once at the start
// to check if the given input is possible. 
void checkSum() {
    forn(x, 3) {
        forn(k, 2) {
            calcedScores[1][x] += matchOutcome[x][circleIndex(x + k + 1)];
            calcedScores[2][x] += matchOutcome[circleIndex(x + k +1)][x];
        }
    }
    forn(x, 3) {
        forn(i, 2) {
            if (calcedScores[i+1][x] != rawScores[i+1][x]) {
                cout << "Impossible" << endl;
                exit(0);
            }
        }
    }
}

// check if the goals scored are all positive numbers. 
bool isPositive() {
    forn(x, 3) forn(k, 2) if (matchOutcome[x][circleIndex(x + k + 1)] < 0) return false;
    return true;
}

// returns if there is any need to continue finding the next outcome.
bool isInLimit() {
    // checks if any numbers of the group that continues to go down as new outcomes are being calculated.
    // They always reduce therefore if any of them falls below 0, there is no need to continue. 
    forn(x, 3) {
        long long y = circleIndex(x - 1);
        if (matchOutcome[x][y] < 0) return false;
    }
    // checks if all numbers in the first group are all bigger than the second group. If so, there is no need 
    // to continue. 
    bool heatDeath = true;
    forn(x, 3) {
        long long y = circleIndex(x + 1);
        if (matchOutcome[y][x] >= matchOutcome[x][y]) heatDeath = false;
    }
    return !heatDeath;
}

// this is the only thing that doesn't work
// supposed to find the number to add in order to skip the outcomes that give the same result as the previous one
long long nextJump() {
    long long smallest = LONG_MAX;
    forn(x, 3) {
        long long y = circleIndex(x + 1);
        long long diff = matchOutcome[y][x] - matchOutcome[x][y];
        if (diff < 0) continue;
        if (diff < smallest) smallest = diff;
    }
    if (smallest == LONG_MAX) {
        throw runtime_error("");
    }
    smallest = smallest / 2;
    return ((smallest ? smallest : 1));
}
// -----------------

// print the outcome using matchOutcome variable
void printOutcome() {
    forn(x, 3) {
        long long y = circleIndex(x+1);
        printf("%s %lld - %lld %s\n", names[x].c_str(), matchOutcome[x][y], matchOutcome[y][x], names[y].c_str());
    }
    exit(0);
}

int main() {
    load();
    // start with one of the outcome, use checkSum() to check if the input data is possible
    matchOutcome[0][1] = -1;
    propergate(0, 1);
    checkSum();

    // this is the main loop. It iterates through all the possible outcomes and check if they match the input. 
    while (isInLimit()) {
        /* puesdocode for the main loop:
            find the next outcome to test against by using the recursive function propergate
            if the one of the goals scored is negative, continue.
            check if the outcome matches with the input:
                if so print the outcome and exit the program
            if all possible outcomes are checked, i.e. the main loop exits,
                the input is impossible. 
        */ 
        resetMatchOutcome();
        matchOutcome[0][1] += nextJump();
        propergate(0, 1);
        if (!isPositive()) continue;
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