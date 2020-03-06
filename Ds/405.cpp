#include <iostream>
#include <stdexcept>
#define forn(i,n) for(long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll R, C;
bool maze[20][20];
bool traveled[20][20];
char path[400]; ll pc;
struct rc {
    ll r, c;
};
rc make_rc(ll r, ll c) {
    rc p;
    p.r = r;
    p.c = c;
    return p;
}
bool move(rc p) {
    if (p.r == R-1 && p.c == C-1) {
        fprintf(stderr, "%lld, %lld\n", p.r, p.c);
        return true;
    } else if (traveled[p.r][p.c] || !maze[p.r][p.c] || p.r == R || p.c == C) {
        return false;
    } else{
        traveled[p.r][p.c] = true;
        if (move(make_rc(p.r + 1, p.c))) {
            path[pc++] = 'S';
            fprintf(stderr, "%lld, %lld\n", p.r, p.c);
            return true;
        } else if (move(make_rc(p.r, p.c + 1))) {
            path[pc++] = 'E';
            fprintf(stderr, "%lld, %lld\n", p.r, p.c);
            return true;
        } else {
            return false;
        }
    }

}

int main() {
    cin >> R >> C;
    forn(r, R) {
        string line;
        cin >> line;
        forn(c, C) {
            maze[r][c] = (line[c] == '.');
        }
    }

    forn(r, R) {
        forn(c, C) {
            cerr << maze[r][c];
        }
        cerr << endl;
    }

    cerr << move(make_rc(0, 0)) << endl;

    forn(i, pc) {
        cout << path[pc-i-1];
    }
    cout << endl;
}