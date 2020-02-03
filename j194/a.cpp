#include <iostream>
#include <algorithm>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;


struct xy {
    long long row, col;
};

bool comp(xy a, xy b) {
    return (a.col < b.col);
}
xy v[1000];
xy tops[1000]; long long T;
long long edge;
long long N, K;
// (N - row - 1) == the col of the base
int main() {
    cin >> N >> K;
    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }
    forn(i, K) cin >> v[i].row >> v[i].col;
    forn(i, K) {
        v[i].row--;
        v[i].col--;
        v[i].row -= v[i].col;
    }
    sort(&v[0], &v[K], comp);
    edge = -2;
    T = 0;
    tops[0].row = 0;
    tops[0].col = 0;
    forn(i, K) {
        if (v[i].col > edge + 1) {
            tops[T].row = v[i].row;
            tops[T].col = v[i].col;
            edge = N - v[i].row - 1;
            T++;
        } else if (v[i].row < tops[T - 1].row) {
            tops[T - 1].row = v[i].row;
            edge = N - v[i].row - 1;
        }
    }

    long long area = 0;

    forn(i, T) {
        long long sideLength = N - tops[i].row - tops[i].col;
        area += sideLength * (sideLength + 1) / 2;
    }

    area -= K;
    cout << area << endl;
}