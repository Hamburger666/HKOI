// excceded time limit meaning death first is not efficient
#include <iostream>
using namespace std;

const int stone = 1;
const int visited = 2;

int R, C, N;
int map[2001][2001] = {0};
int secondVisit[2001][2001] = {0};
bool oneCell = false;
int oneCellCoordinate[2];

// right and then up
bool move1(int r, int c) {
    if (r == R - 1 && c == C - 1) {
        return true;
    }
    if (map[r][c] == stone || map[r][c] == visited) {
        return false;
    }
    map[r][c] = visited;
    if (move1(r, c+1) || move1(r+1, c)) {
        return true;
    } else {
        return false;
    }
}

// up and then right
bool move2(int r, int c) {
    if (r == R-1 && c == C-1) {
        return true;
    }
    if (map[r][c] == visited) {
        oneCell = true;
        oneCellCoordinate[0] = r;
        oneCellCoordinate[1] = c;
    }
    if (map[r][c] == stone) {
        return false;
    }
    map[r][c] = stone;
    if (move2(r+1, c) || move2(r, c+1)) {
        return true;
    } else {
        return false;
    }}

void printMap() {
    for (int i = R; i >= 0; i--) {
        for (int j = 0; j < C+1; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> R >> C >> N;
    for (int i = 0; i < N; i++) {
        int r, c;
        cin >> r >> c;
        map[r-1][c-1] = stone;
    }
    for (int i = 0; i < R; i++) {
        map[i][C] = stone;
    }
    for (int i = 0; i < C; i++) {
        map[R][i] = stone;
    }
    if (move1(0, 0)) {
        map[0][0] = 0;
        if (move2(0, 0)) {
            if (oneCell) {
                cout << 1 << endl;
                cout << oneCellCoordinate[0]+1 << " " << oneCellCoordinate[1]+1 << endl;
            } else {
                cout << "2" << endl;
                cout << "1 2" << endl;
                cout << "2 1" << endl;
            }
        } else {
            cout << "your program is fucked up" << endl;
        }
    } else {
        cout << 0 << endl;
    }
}