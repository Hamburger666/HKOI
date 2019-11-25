//https://judge.hkoi.org/task/S191

#include <iostream>
using namespace std;

bool rawMap[2001][2001];
bool accessMapTo[2001][2001];
bool accessMapFrom[2001][2001];
bool accessMap[2001][2001];
int r, c, n;

void load() {
    cin >> r >> c >> n;
    for (int i = 0; i < 2001; i++) {
        for (int j  = 0; j < 2001; j++) {
            rawMap[i][j] = false;
            accessMap[i][j] = false;
            accessMapFrom[i][j] = false;
            accessMapTo[i][j] = false;
        }
    }
    for (int ri = 0; ri < r; ri++) {
        for (int ci = 0; ci < c; ci++) {
            rawMap[ri][ci] = true;
            accessMap[ri][ci] = true;
            accessMapTo[ri][ci] = true;
            accessMapFrom[ri][ci] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << i << endl;
        int row, col;
        cin >> row >> col;
        cout << row << " " << col << endl;
        rawMap[row - 1][col - 1] = false;
    }
}


int main() {
    load();
    for (int i = 1; i <= r + c - 3; i++) {
        int rowi = i;
        int coli = 0;
        while(rowi >= 0) {
            accessMapTo[rowi][coli] = (accessMapTo[max(0, rowi-1)][coli] || accessMapTo[rowi][max(0, coli - 1)]) 
                    && rawMap[rowi][coli];
            rowi--;
            coli++;
        }
        int j = r + c - 2 - i;
        int rowj = j;
        int colj = j - rowj;
        while (rowj >= 0) {
            accessMapFrom[rowj][colj] = (accessMapFrom[rowj+1][colj] || accessMapFrom[rowj][colj + 1])
                    && rawMap[rowj][colj];
            rowj--;
            colj++;
        }
    }

    int blockSquareCount = 0;
    for (int row = 0; row < r; row++) {
        for (int col = 0; col < c; col++) {
            accessMap[row][col] = accessMapFrom[row][col] && accessMapTo[row][col];
            if (!accessMap[row][col]) {
                blockSquareCount++;
            }
        }
    }
    
    if (blockSquareCount == r * c - 2) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= r + c - 3; i++) {
        bool existTrue = false;
        bool existMoreTrue = false;
        int trueCoord[2];
        int rowi = i;
        int coli = 0;
        while(rowi >= 0 && coli <= c - 1) {
            if (accessMap[rowi][coli]) {
                if (existTrue) {
                    existMoreTrue = true;
                    break;
                } else {
                    existTrue = true;
                    trueCoord[0] = rowi;
                    trueCoord[1] = coli;
                }
            }
            rowi--;
            coli++;
        }
        if (existTrue && !existMoreTrue) {
            cout << 1 << endl;
            cout << trueCoord[0] + 1 << " " << trueCoord[1] + 1 << endl;
            return 0;
        }
    }
    cout << 2 << endl;
    cout << r << " " << c - 1 << endl;
    cout << r - 1 << " " << c << endl;
    return 0;
}

