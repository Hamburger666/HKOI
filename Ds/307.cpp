#include <iostream>
#include <string>
#define forn(i,n) for(long long i = 0; i<n; i++)
using namespace std;
typedef long long ll;

char board[3][3];
int main() {
    bool filled = true;
    bool possible = false;
    forn(r, 3) {
        string s;
        cin >> s;
        forn(c, 3) {
            board[r][c] = s[c];
            if (s[c] == '.') filled = false;
        }
    }

    
    char winner = '.';
    bool hasWinner = false;
    if (!hasWinner) forn(r,3) {
        bool smallPossible = true;
        bool win = true;
        char start = board[r][0];
        forn(c, 3) {
            if (start != board[r][c]) {
                win = false;
                if (start != '.') {
                    smallPossible = false;
                }
            } 
        }
        if (win && start != '.') {
            winner = start;
            // cout << 1 << endl;
            hasWinner = true;
        }
        if (smallPossible) possible = true;
    }
    if (!hasWinner) forn(c, 3) {
        bool win = true;
        char start = board[0][c];
        bool smallPossible = true;        
        forn(r, 3) {
            if (start != board[r][c]) {
                win = false;

                if (start != '.') {
                    smallPossible = false;
                }
            }
        }
        if (win && start != '.') {
            winner = start;
            hasWinner = true;
        }
        if (smallPossible) possible = true;
    }

    if (!hasWinner) {
        char start = board[0][0];
        bool win = true;
        bool smallPossible = true;
        forn(o, 3) {

            if (start != board[o][o]) {
                win = false;
                if (start != '.') {
                    smallPossible = false;
                }
            }
        }
        if (win && start != '.') {
            winner = start;
            hasWinner = true;
        }
        if (smallPossible) possible = true;
    }

    if (!hasWinner) {
        char start = board[0][2];
        bool win = true;
        bool smallPossible = true;
        forn(o, 3) {

            if (start != board[o][2-o]) {
                win = false;
                if (start != '.') {
                    smallPossible = false;
                }
            }
        }
        if (win && start != '.') {
            winner = start;
            hasWinner = true;
        }
        if (smallPossible) possible = true;
    }
    fprintf(stderr, "hasWinner: %d, filled: %d, filled: %d\n", hasWinner, filled, possible);
    if (hasWinner || filled || !possible) {
        if (winner == '.') {
            cout << "Draw" << endl;
        } else {
            cout << winner << " " << "wins" << endl;
        }
    } else {
        cout << "Not ended" << endl;
    }
}