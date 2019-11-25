// https://judge.hkoi.org/task/J182
// trace the board in a zig zag pattern, if there is a paint in the cell, break the rope and start a new one at the next avaliable cell.

#include <iostream>
using namespace std;

int R, C, N;
int map[300][300];
int ropes[900000][2];
int ropes_length;
int ropesStartingPoints[900000];
int ropesStartingPoints_length;

const int stone = 1;
const int free_ = 2;

void init() {
    for (int r = 0; r < 300; r++) {
        for (int c = 0; c < 300; c++) {
            map[r][c] = free_;
        }
    }
    ropes_length = 0;
    ropesStartingPoints_length = 0;
}

void load() {
    cin >> R >> C >> N;
    for (int i = 0; i < N; i++) {
        int r, c;
        cin >> r >> c;
        map[r - 1][c - 1] = stone;
    }
}

void specialCase() {
    if (C == 1) {
        int tracerR = 0;
        bool newRope = true;
        while (tracerR < R) { 
            if (map[tracerR][0] == stone) {
                newRope = true;
            } else {
                if (newRope) {
                    // record the rope starting point
                    ropesStartingPoints[ropesStartingPoints_length] = ropes_length;
                    ropesStartingPoints_length++;
                    newRope = false;
                }
                ropes[ropes_length][0] = tracerR;
                ropes[ropes_length][1] = 0;
                ropes_length++;
            }
            tracerR++;
        }
        ropesStartingPoints[ropesStartingPoints_length] = ropes_length; 

        cout << ropesStartingPoints_length << endl;
        for (int ropeI = 0; ropeI < ropesStartingPoints_length; ropeI++) {
            cout << ropesStartingPoints[ropeI + 1] - ropesStartingPoints[ropeI] << endl;
            for (int ropeCellI = ropesStartingPoints[ropeI]; ropeCellI < ropesStartingPoints[ropeI + 1]; ropeCellI++) {
                cout << ropes[ropeCellI][0] + 1 << " " << ropes[ropeCellI][1] + 1 << endl;
            }
        }
        exit(0);
    }
}

int main() {
    init();
    load();
    specialCase();
    int tracerR = 0;
    int tracerC = 0;
    bool newRope = true;
    const bool positive = true;
    const bool negative = false; 
    bool direction = positive;
    bool justTurned = true;
    while (tracerR < R && tracerC < C) {
        if (map[tracerR][tracerC] == stone) {
            newRope = true;
        } else {
            if (newRope) {
                // record the rope starting point
                ropesStartingPoints[ropesStartingPoints_length] = ropes_length;
                ropesStartingPoints_length++;
                newRope = false;
            }
            ropes[ropes_length][0] = tracerR;
            ropes[ropes_length][1] = tracerC;
            ropes_length++;
        }
        // move tracer
        if (!justTurned && (tracerC == C-1 || tracerC == 0)) {
            tracerR++;
            direction = !direction;
            justTurned = true;
        } else {
            if (direction == positive) {
                tracerC++;
            } else {
                tracerC--;
            }
            justTurned = false;
        }
    }

    ropesStartingPoints[ropesStartingPoints_length] = ropes_length; 

    cout << ropesStartingPoints_length << endl;
    for (int ropeI = 0; ropeI < ropesStartingPoints_length; ropeI++) {
        cout << ropesStartingPoints[ropeI + 1] - ropesStartingPoints[ropeI] << endl;
        for (int ropeCellI = ropesStartingPoints[ropeI]; ropeCellI < ropesStartingPoints[ropeI + 1]; ropeCellI++) {
            cout << ropes[ropeCellI][0] + 1 << " " << ropes[ropeCellI][1] + 1 << endl;
        }
    }
}