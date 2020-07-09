#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll X, Y, C;
string DIRS;
bool grid[1002][1002]; // {true is wall, false is free}
vector<ll> points[2][1002]; // {x, y}
vector<ll> p;

ll bs(bool xy, ll f, ll s, ll left, ll right) { // xy is the value that moves
    if (left + 1 >= right) {
        return left;
    }
    ll mid = (left + right) / 2;
    if (s < points[!xy][f][mid]) {
        return bs(xy, f, s, left, mid);
    } else {
        return bs(xy, f, s, mid, right);
    }
}

ll bs(bool xy, ll f, ll s) {
    return bs(xy, f, s, 0, points[!xy][f].size());
}

ll bss(bool xy, ll f, ll s, ll dir) {
    ll c = bs(xy, f, s);
    return points[!xy][f][c + dir];
}

pll dd(char d) { // {values that moves, is moving to positive}
    pll re;
    if (d == 'N') {
        re.first = 0;
        re.second = 0;
    } else if (d == 'S') {
        re.first = 0;
        re.second = 1;
    } else if (d == 'E') {
        re.first = 1;
        re.second = 1;
    } else if (d == 'W') {
        re.first = 1;
        re.second = 0;
    }
    return re;
}

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> X >> Y >> C;
    forn(x, X) {
        string s;
        cin >> s;
        forn(y, Y) {
            grid[x+1][y+1] = (s[y] == '#');
        }
    }
    p.resize(2);
    cin >> p[0] >> p[1];
    cin >> DIRS;
    forn(x, X+2) {
        grid[x][0] = true;
        grid[x][Y+1] = true;
    }
    forn(y, Y+2) {
        grid[0][y] = true;
        grid[X + 1][y] = true;
    }
    forn(x, X+2) {
        forn(y, Y+2) {
            if (grid[x][y]) {
                points[0][x].push_back(y);
                points[1][y].push_back(x);
            }
        }
    }
    ll c = 0;
    forn(i, C) {
        pll dir = dd(DIRS[i]);
        ll change = abs(bss(dir.first, p[!dir.first], p[dir.first], dir.second) - p[dir.first]) - 1;
        c += change;
        p[dir.first] += (change) * (dir.second ? 1 : -1);
    }
    cout << c << endl;
}