// Doesn't work, time to give up
#include <iostream>
using namespace std;

int r, c, n;
int rawMap[2000][2000];
int accessMap[2000][2000];
int accessMapTo[2000][2000];
int accessMapFrom[2000][2000];

void debugPrint() {
    for (int row = 0; row < r; row++) {
        for (int col = 0; col < c; col++) {
            if (accessMap[row][col]) {
                cout << "+";
            } else {
                cout << "-";
            }
        }
        cout << endl;
    }
    cout << endl;

    for (int row = 0; row < r; row++) {
        for (int col = 0; col < c; col++) {
            if (rawMap[row][col]) {
                cout << "+";
            } else {
                cout << "-";
            }
        }
        cout << endl;
    }
    cout << endl;

    for (int row = 0; row < r; row++) {
        for (int col = 0; col < c; col++) {
            if (accessMapTo[row][col]) {
                cout << "+";
            } else {
                cout << "-";
            }
        }
        cout << endl;
    }
    cout << endl;

    for (int row = 0; row < r; row++) {
        for (int col = 0; col < c; col++) {
            if (accessMapFrom[row][col]) {
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
    // initialise --------

    // ----- load -------
    cin >> r >> c >>n;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            rawMap[i][j] = true;
            accessMap[i][j] = true;
            accessMapTo[i][j] = true;
            accessMapFrom[i][j] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        int row, column;
        cin >> row >> column;
        rawMap[row-1][column-1] = false;
    }

    // draw maps -------
    for (int i = 1; i <= r + c - 3; i++) {
        int rowi;
        int coli;
        if (i <= r-1) {
            rowi = i;
        } else {
            rowi = r-1;
        }
        coli = i - rowi;
        bool one, two;
        if (rowi-1 < 0) {
            one = false;
        } else {
            one = accessMapTo[rowi - 1][coli];
        }
        if (coli-1 < 0) {
            two = false;
        } else {
            two = accessMapTo[rowi][coli-1];
        }
        while (rowi >= 0 && coli <= c-1) {
            accessMapTo[rowi][coli] = (one || two) && rawMap[rowi][coli];
            coli++;
            rowi--;
        }
    }

    for (int i = r + c - 3; i >= 1; i--) {
        int rowi;
        int coli;
        if (i <= r - 1) {
            rowi = i;
        } else {
            rowi = r-1;
        }
        coli = i - rowi;
        bool one, two;
        if (rowi + 1 > r-1) {
            one = false;
        } else {
            one = accessMapFrom[rowi+1][coli];
        }
        if (coli + 1 > c-1) {
            two = false;
        } else {
            two = accessMapFrom[rowi][coli+1];
        }
        while (rowi >= 0 && coli <= c-1) {
            accessMapFrom[rowi][coli] = (one || two) && rawMap[rowi][coli];
            coli++;
            rowi--;
        }
    }

    for (int row = 0; row < r; row++) {
        for(int col = 0; col < c; col++) {
            accessMap[row][col] = accessMapFrom[row][col] && accessMapTo[row][col];
        }
    }


    int totalFalseSquareCount = 0;
    for (int row = 0; row < r; row++) {
        for (int col = 0; col < c; col++) {
            accessMap[row][col] = accessMapFrom[row][col] && accessMapTo[row][col];
            if (!accessMap[row][col]) {
                totalFalseSquareCount++;
            }
        }
    }
    // --------- end draw map ------------
    debugPrint();
    
    if (totalFalseSquareCount == r * c - 2) {
        cout << 0 << endl;
        return 0;
    }


    for (int i = 1; i <= r + c - 3; i++) {
        int rowi;
        int coli;
        rowi = min(i, r - 1);
        coli = i - rowi;
        bool appeared = false;
        bool appearedTwice = false;
        int coord[2];
        while(rowi >= 0 && coli <= c - 1) {
            if (accessMap[rowi][coli]) {
                if (appeared) {
                    appearedTwice = true;
                    break;
                } else {
                    appeared = true;
                    coord[0] = rowi;
                    coord[1] = coli;
                }
            }
            rowi--;
            coli++;
        }
        if (appeared && !appearedTwice) {
            cout << 1 << endl;
            cout << coord[0] + 1 << " " << coord[1] + 1 << endl;
            return 0;
        }
    }
    
    if (c == 1) {
        cout << 1 << endl;
        cout << "2 1" << endl;
        return 0;
    }
    if (r == 1) {
        cout << 1 << endl;
        cout << "1 2" << endl;
        return 0;
    }

    cout << 2 << endl;
    cout << "1 2" << endl;
    cout << "2 1" << endl;
    return 0;
}