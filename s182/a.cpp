#include <iostream>
#include <limits.h>
#include <cmath>
#include 
#define forn(i, n) for (int i; i < n; i++)
using namespace std;

long long W, D, raw[3][3], trialState[3][3], groups[2][3], height;
bool trialState_filled[3][3], outcome[3][2][3];

int correntIndex(int index, int circumference) {
    while (index < 0) index += circumference;
    while (index >= circumference) index -= circumference;
    return index;
}

void load() {
    cin >> W;
    cin >> D;
    forn(team, 3) forn(property, 3) {
        cin >> raw[team][property];
    }
}

void clearTrialState() {
    forn(a, 3) forn(b, 3) trialState_filled[a][b] = false;
}

void checkSum() {
    forn(player, 3) {
        long long sum = 0;
        forn(i, 2) {
            sum += trialState[player][correntIndex(player+1+i, 3)];
        }
        if (sum != raw[player][1]) {
            cout << "Impossible" << endl;
            exit(0);
        }
        sum = 0;
        forn(i, 2) {
            sum += trialState[correntIndex(player+1+i, 3)][player];
        }
        if (sum != raw[player][2]) {
            cout << "Impossible" << endl;
            exit(0);
        }
    }
}

void init() {
    clearTrialState();
}

int theOther(int one, int two) {
    forn(i, 3) if (i != one && i != two) return i;
}

void populateAdjacent(int currentHome, int currentAway) {
    if(!trialState_filled[currentHome][theOther(currentHome, currentAway)]) {
        trialState_filled[currentHome][theOther(currentHome, currentAway)] = true;
        trialState[currentHome][theOther(currentHome, currentAway)] = raw[currentHome][1] - trialState[currentHome][currentAway];
        populateAdjacent(currentHome, theOther(currentHome, currentAway));
    }
    if(!trialState_filled[theOther(currentHome, currentAway)][currentAway]) {
        trialState_filled[theOther(currentHome, currentAway)][currentAway] = true;
        trialState[theOther(currentHome, currentAway)][currentAway] = raw[currentHome][2] - trialState[currentHome][currentAway];
        populateAdjacent(theOther(currentHome, currentAway), currentAway);
    }
}


int main() {
    load();
    init();
    trialState[0][1] = 0;
    trialState_filled[0][1] = true;
    populateAdjacent(0, 1);
    checkSum();
    // find outcome
    forn(player, 3) {
        if (raw[player][0] == 0) {
            forn(i, 2) {
                outcome[player][i][0] = true;
                outcome[player][i][1] = false;
                outcome[player][i][2] = false;
            }
        } 
        if (W == D) {
            if (raw[player][0] == W) {
                outcome[player][0][0] = false;
                outcome[player][0][1] = true;
                outcome[player][0][2] = true;
                outcome[player][1][0] = true;
                outcome[player][1][1] = false;
                outcome[player][1][2] = false;
            } else if (raw[player][0] == 2*W) {
                forn(i, 2) {
                    outcome[player][i][0] = false;
                    outcome[player][i][1] = true;
                    outcome[player][i][2] = true;
                }
            } else {
                throw runtime_error("");
            }
        } else {
            if (raw[player][0] == 0) {
                forn(i, 2) {
                    outcome[player][i][0] = true;
                    outcome[player][i][1] = false;
                    outcome[player][i][2] = false;
                }
            } else if (raw[player][0] == W) {
                outcome[player][i]
                // TODO
            }
        }
    }
    long long smallest[2];
    forn(groupNo, 2) {
        // load number in
        forn(itemNo, 3) {
            groups[groupNo][itemNo] = trialState[itemNo][correntIndex(itemNo + (groupNo? -1 : 1 ), 3)];
        }
        // calc offset
        smallest[groupNo] = LONG_MAX;
        forn(itemNo, 3) if (groups[groupNo][itemNo] < smallest[groupNo]) smallest[groupNo] = groups[groupNo][itemNo];
        forn(itemNo, 3) groups[groupNo][itemNo] -= smallest[groupNo];
    }
    height = smallest[0] + smallest[1];
}