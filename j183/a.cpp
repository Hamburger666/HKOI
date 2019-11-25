// https://judge.hkoi.org/task/J183
// very convoluted code. just restart

#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;

long long R, C, K, Sr, Sc, Er, Ec, rd, cd;
bool flippedR, flippedC;
long long rOverShoot, rUnderShoot, rUnderShootSegment, rUnderShootSteps, rOverShootSteps, rTotalSteps,
    cOverShoot, cUnderShoot, cUnderShootSegment, cUnderShootSteps, cOverShootSteps, cTotalSteps;
bool rOverShootBefore_possible, rOverShootAfter_possible, rOverShootMiddle_possible, 
    cOverShootBefore_possible, cOverShootAfter_possible, cOverShootMiddle_possible;
int rStrategy, cStrategy;
const int overShootBefore = 1;
const int overShootAfter = 2;
const int overShootMiddle = 3;
const int underShoot = 4;
const int justRight = 5;

void load() {
    cin >> R >> C >> K >> Sr >> Sc >> Er >> Ec;
    Sr--;
    Sc--;
    Er--;
    Ec--;
}

void processLoad() {
    if (Sr < Er) {
        rd = Er - Sr;
        flippedR = false;
    } else {
        rd = Sr - Er;
        flippedR = true;
    }
    if (Sc < Ec) {
        cd = Ec - Sc;
        flippedC = false;
    } else {
        cd = Sc - Ec;
        flippedC = true;
    }
}

void printInput() {
    printf("R = %lld, C = %lld, K = %lld, Sr = %lld, Sc = %lld, Er = %lld, Ec = %lld, rd = %lld, cd = %lld \n", R, C, K, Sr, Sc, Er, Ec, rd, cd);
}

void printResult() {
    cout << cTotalSteps + rTotalSteps << endl;
    if (rStrategy == justRight) {
        string directionWord;
        if (flippedR) {
            directionWord = "up";
        } else {
            directionWord = "down";
        }
        cout << directionWord << " " << K * rUnderShootSegment << endl;
    } else if (rStrategy == overShootBefore) {
        string firstDirectionWord;
        string secondDirectionWord;
        if (flippedR) {
            firstDirectionWord = "down";
            secondDirectionWord = "up";
        } else {
            firstDirectionWord = "up";
            secondDirectionWord = "down";
        }
        for (int i = 0; i < rOverShootSteps; i++) {
            cout << firstDirectionWord << " 1" << endl;
        }
        cout << secondDirectionWord << " " << K * (rUnderShootSegment + 1) << endl;
    } else if (rStrategy == overShootAfter) {
        string firstDirectionWord;
        string secondDirectionWord;
        if (flippedR) {
            firstDirectionWord = "up";
            secondDirectionWord = "down";
        } else {
            firstDirectionWord = "down";
            secondDirectionWord = "up";
        }
        cout << firstDirectionWord << " " << K * (rUnderShootSegment + 1) << endl;
        for (int i = 0; i < rOverShootSteps; i++) {
            cout << firstDirectionWord << " 1" << endl;
        }
    } else if (rStrategy == overShootMiddle) {
        string goDirectionWord, returnDirectionWord;
        if (flippedR) {
            goDirectionWord = "up";
            returnDirectionWord = "down";
        } else {
            goDirectionWord = "down";
            returnDirectionWord = "up";
        }
        cout << goDirectionWord << K;
        for (int i = 0; i < rOverShootSteps; i++) {
            cout << returnDirectionWord << " 1" << endl;
        }
        cout << goDirectionWord << " " << K * rUnderShootSegment << endl;
    } else if (rStrategy == underShoot) {
        string directionWord;
        if (flippedR) {
            directionWord = "up";
        } else {
            directionWord = "down";
        }
        if (rUnderShootSegment != 0) {
            cout << directionWord << " " << K * (rUnderShootSegment) << endl;
        }
        for (int i = 0; i < rUnderShootSteps; i++) {
            cout << directionWord << " 1" << endl;
        }
    } else {
        throw runtime_error("");
    }

    // print c move
    if (cStrategy == justRight) {
        string directionWord;
        if (flippedC) {
            directionWord = "left";
        } else {
            directionWord = "right";
        }
        cout << directionWord << " " << K * cUnderShootSegment << endl;

    } else if (cStrategy == overShootBefore) {
        string firstDirectionWord;
        string secondDirectionWord;
        if (flippedC) {
            firstDirectionWord = "right";
            secondDirectionWord = "left";
        } else {
            firstDirectionWord = "left";
            secondDirectionWord = "right";
        }
        for (int i = 0; i < cOverShootSteps; i++) {
            cout << firstDirectionWord << " 1" << endl;
        }
        cout << secondDirectionWord << " " << K * (cUnderShootSegment + 1) << endl;
    } else if (cStrategy == overShootAfter) {
        string firstDirectionWord;
        string secondDirectionWord;
        if (flippedR) {
            firstDirectionWord = "left";
            secondDirectionWord = "right";
        } else {
            firstDirectionWord = "right";
            secondDirectionWord = "left";
        }
        for (int i = 0; i < cUnderShootSegment + 1; i++) {
            cout << firstDirectionWord << " " << K << endl;
        }
        cout << firstDirectionWord << " " << K * (cUnderShootSegment + 1) << endl;
    } else if (cStrategy == overShootMiddle) {
        string goDirectionWord, returnDirectionWord;
        if (flippedR) {
            goDirectionWord = "right";
            returnDirectionWord = "left";
        } else {
            goDirectionWord = "left";
            returnDirectionWord = "right";
        }
        cout << goDirectionWord << K << endl;
        for (int i = 0; i < cOverShootSteps; i++) {
            cout << returnDirectionWord << " 1" << endl;
        }
        cout << goDirectionWord << " " << K * cUnderShootSegment << endl;
    } else if (cStrategy == underShoot) {
        string directionWord;
        if (flippedC) {
            directionWord = "right";
        } else {
            directionWord = "left";
        }
        if (cUnderShootSegment != 0) {
            cout << directionWord << " " << K * (cUnderShootSegment) << endl;
        }
        for (int i = 0; i < cUnderShootSteps; i++) {
            cout << directionWord << " 1" << endl;
        }
    }
    else {
        throw runtime_error("");
    }
    exit(0);
}

void specialCase() {
    if (K == 1) {
        cStrategy = justRight;
        rStrategy = justRight;
        rUnderShootSegment = 1;
        cUnderShootSegment = 1;
        printResult();
    }
}

int main() {
    load();
    processLoad();
    // printInput();
    rUnderShootSegment = rd / K;
    if (rd % K == 0) {
        rStrategy = justRight;
        rTotalSteps = 1;
    } else {
        rOverShootSteps = (rUnderShootSegment + 1) * K - rd;
        rUnderShootSteps = rd - (rUnderShootSegment * K);
        if (flippedR) {
            rOverShootBefore_possible = (Er + rOverShootSteps < R);
            rOverShootAfter_possible = (Sr - rOverShootSteps >= 0);
            rOverShootMiddle_possible = (rUnderShootSegment >= 1);
        } else {
            rOverShootBefore_possible = (Sr - rOverShootSteps >= 0);
            rOverShootAfter_possible = (Er + rOverShootSteps < R);
            rOverShootMiddle_possible = (rUnderShootSegment >= 1);
        }
        if (rOverShootBefore_possible || rOverShootAfter_possible) {
            long long rUnderShootTotalSteps = 1 + rUnderShootSteps;
            long long rOverShootTotalSteps = 1 + rOverShootSteps;
            if (rUnderShootTotalSteps <= rOverShootTotalSteps) {
                rStrategy = underShoot;
                rTotalSteps = rUnderShootTotalSteps;
            } else {
                if (rOverShootBefore_possible) {
                    rStrategy = overShootBefore;
                } else if (rOverShootAfter_possible) {
                    rStrategy = overShootAfter;
                } else {
                    throw runtime_error("");
                }
                rTotalSteps = rOverShootSteps;
            }
        } else if (rOverShootMiddle_possible) {
            long long rUnderShootTotalSteps = 1 + rUnderShootSteps;
            long long rOverShootTotalSteps = 2 + rOverShootSteps;
            if (rUnderShootTotalSteps <= rOverShootTotalSteps) {
                rStrategy = underShoot;
                rTotalSteps = rUnderShootTotalSteps;
            } else {
                rStrategy = overShootMiddle;
                rTotalSteps = rOverShootSteps;
            }
        } else {
            rStrategy = underShoot;
            rTotalSteps = rUnderShootSegment + rUnderShootSteps;
        }
    }

    cUnderShootSegment = cd / K;
    if (cd % K == 0) {
        cStrategy = justRight;
        cTotalSteps = 1;
    } else {
        cOverShootSteps = (cUnderShootSegment + 1) * K - rd;
        cUnderShootSteps = cd - (cUnderShootSegment * K);
        if (flippedC) {
            cOverShootBefore_possible = (Ec + cOverShootSteps < R);
            cOverShootAfter_possible = (Sc - cOverShootSteps >= 0);
            cOverShootMiddle_possible = (cUnderShootSegment >= 1);
        } else {
            cOverShootBefore_possible = (Sc - cOverShootSteps >= 0);
            cOverShootAfter_possible = (Ec + cOverShootSteps < R);
            cOverShootMiddle_possible = (cUnderShootSegment >= 1);
        }
        if (cOverShootBefore_possible || cOverShootAfter_possible) {
            long long cUnderShootTotalSteps = 1 + cUnderShootSteps;
            long long cOverShootTotalSteps =  1 + cOverShootSteps;
            if (cUnderShootTotalSteps <= cOverShootTotalSteps) {
                cStrategy = underShoot;
                cTotalSteps = cUnderShootTotalSteps;
            } else {
                if (cOverShootBefore_possible) {
                    cStrategy = overShootBefore;
                } else if (cOverShootAfter_possible) {
                    cStrategy = overShootAfter;
                } else {
                    throw runtime_error("");
                }
                cTotalSteps = cOverShootSteps;
            }
        } else if(overShootMiddle) {
            long long cUnderShootTotalSteps = 1 + cUnderShootSteps;
            long long cOverShootTotalSteps =  2 + cOverShootSteps;
            if (cUnderShootTotalSteps <= cOverShootTotalSteps) {
                cStrategy = underShoot;
                cTotalSteps = cUnderShootTotalSteps;
            } else {
                cStrategy = overShootMiddle;
                cTotalSteps = cOverShootSteps;
            }
        } else {
            cStrategy = underShoot;
            cTotalSteps = cUnderShootSegment + cUnderShootSteps;
        }
    }
    // printf("rS = %d, cS = %d\n", rStrategy, cStrategy);
    printResult();
}