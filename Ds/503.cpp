#include <iostream>
#include <fstream>
#define forn(i,n) for(long long i = 0; i < n; i++)
typedef long long ll;
using namespace std;

ofstream fout;
char o[12][27];
int main() {
    fout.open("chart.txt");
    forn(r, 12) forn(c, 27) {
        o[r][c] = ' ';
    }
    forn(r, 12) {
        o[r][0] = '|';
        o[r][26] = '|';
    }
    forn(c, 27) {
        o[0][c] = '-';
        o[11][c] = '-';
    }

    o[0][0] = '+';
    o[0][26] = '+';
    o[11][0] = '+';
    o[11][26] = '+';

    forn(i, 6) {
        ll d;
        cin >> d;
        forn(k, 3) {
            forn(h, d) {
                o[10-h][i*4+k+2] = '#';
            }
        }
    }

    forn(r, 12) {
        forn(c, 27) {
            fout << o[r][c];
        }
        fout << endl;
    }
    fout.close();
}