#include <iostream>
using namespace std;

int R, C, N;
bool map0[2001][2001];
bool map1[2001][2001];
bool map2[2001][2001];
bool mapCombined[2001][2001];

bool oneThing = false;
int oneThingCoord[2];

bool quit = false;

void init() {
    for (int i = 0; i < 2001; i++) {
        for (int k = 0; k < 2001; k++) {
            map0[i][k] = true;
            map1[i][k] = true;
            map2[i][k] = true;
            mapCombined[i][k] = true;
        }
    }
}

void load() {
    cin >> R >> C >> N;
    for (int i = 0; i < N; i++) {
        int r, c;
        cin >> r >> c;
        map0[r-1][c-1] = false;
    }
}

void drawMap1() {
    for (int i = 1; i <= R+C-3; i++) {
        int r, c;
        r = min(R-1, i);
        c = i - r;
        while(r >= 0 && c <= C-1) {
            map1[r][c] = ((r-1 >= 0 && map1[r-1][c]) || (c-1 >= 0 && map1[r][c-1])) && map0[r][c];  //might be buggy here
            r--;
            c++;
        }
    }
}

void drawMap2() {
    for (int i = R+C-3; i >= 1; i--) {
        int r, c;
        r = min(R-1, i);
        c = i - r;
        while(r >= 0 && c <= C-1) {
            map2[r][c] = ((r+1 <= R-1 && map2[r+1][c]) || (c+1 <= C-1 && map2[r][c+1])) && map0[r][c];
            r--;
            c++;
        }
    }
}

void combineMap() {
    int falseCount = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if(map1[r][c] && map2[r][c]) {
                mapCombined[r][c] = true;
            } else {
                mapCombined[r][c] = false;
                falseCount++;
            }
        }
    }
    if (falseCount == R*C-2) {
        cout << 0 << endl;
        quit = true;
        return;
    }
}

void findDiagonal() {
    for (int i = 1; i <= R+C-3; i++) {
        int r, c;
        r = min(R-1, i);
        c = i-r;
        bool hasOne = false;
        bool hasTwo = false;
        int oneCoord[2];
        while (r >= 0 && c <= C-1) {
            if (mapCombined[r][c]) {
                if (hasOne) {
                    hasTwo = true;
                    break;
                } else {
                    hasOne = true;
                    oneCoord[0] = r;
                    oneCoord[1] = c;
                }
            }
            c++;
            r--;
        }
        if (hasOne && !hasTwo) {
            oneThing = true;
            oneThingCoord[0] = oneCoord[0];
            oneThingCoord[1] = oneCoord[1];
            return;
        }
    }
}

void printMaps() {
    cout << "map0:" << endl;
    for (int r = R-1; r >= 0; r--) {
        for (int c = 0; c < C; c++) {
            if (map0[r][c]) {
                cout << "+";
            } else {
                cout << "-";
            }
        }
        cout << endl;
    }
    cout << endl;

    cout << "map1:" << endl;
    for (int r = R-1; r >= 0; r--) {
        for (int c = 0; c < C; c++) {
            if (map1[r][c]) {
                cout << "+";
            } else {
                cout << "-";
            }
        }
        cout << endl;
    }
    cout << endl;

    cout << "map2:" << endl;
    for (int r = R-1; r >= 0; r--) {
        for (int c = 0; c < C; c++) {
            if (map2[r][c]) {
                cout << "+";
            } else {
                cout << "-";
            }
        }
        cout << endl;
    }
    cout << endl;

    cout << "mapCombined:" << endl;
    for (int r = R-1; r >= 0; r--) {
        for (int c = 0; c < C; c++) {
            if (mapCombined[r][c]) {
                cout << "+";
            } else {
                cout << "-";
            }
        }
        cout << endl;
    }
    cout << endl;


}

int main() {
    init();
    load();
    drawMap1();
    drawMap2();
    combineMap();
    // printMaps();
    if (quit) return 0;
    findDiagonal();
    if (oneThing) {
        cout << 1 << endl;
        cout << oneThingCoord[0]+1 << " " << oneThingCoord[1]+1 << endl;
    } else {
        cout << 2 << endl;
        cout << "1 2" << endl << "2 1" << endl;
    }
}