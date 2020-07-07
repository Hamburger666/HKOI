#include <iostream>
#include <unordered_set>
#include <chrono>
#include <thread>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N, D;
pll dest;
unordered_set<ll> path;
char graph[1000][1000];

ll ep(ll x, ll y) {
    return x * (N+1) + y;
}

ll ep(pll p) {
    return ep(p.first, p.second);
}

pll dp(ll n) {
    pll p;
    p.first = n / (N+1);
    p.second = n % (N+1);
    return p;
}

ll dtd(ll x, ll y) {
    return abs(dest.first - x) + abs(dest.second - y);
}

ll dtd(pll p) {
    return dtd(p.first, p.second);
}

int main() {
    cin >> N >> D;
    if ((N + 1) / 2 % 2 == 0) {
        dest = make_pair(0, N-1);
    } else {
        dest = make_pair(N-1, N-1);
    }
    if (D < dtd(make_pair(0, 0))) {
        dest = make_pair(0, N-1);
    }
    pll c;
    c.first = 0; 
    c.second = 0;
    ll stepC = 0;
    bool dirUp = true;
    bool justTurned = false;
    while (!(D - 1 <=dtd(c) + stepC && dtd(c) + stepC <= D+1)) {
        if (dirUp && c.first < N-1) {
            c.first++;
        } else if (!dirUp && c.first > 0) {
            c.first--;
        } else if (justTurned) {
            c.second++;
            justTurned = false;
            dirUp = !dirUp;
        } else {
            c.second++;
            justTurned = true;
                        
        }
        stepC++;
        path.insert(ep(c));
    }
    while (c.second != dest.second) {
        if (c.second < dest.second) {
            c.second++;
        } else {
            c.second--;
        }
        path.insert(ep(c));
    }
    while (c.first != dest.first) {
        if (c.first < dest.first) {
            c.first++;
        } else {
            c.first--;
        }
        path.insert(ep(c));
    }
    forn(x, N) {
        forn(y, N) {
            if (path.find(ep(x, y)) != path.end()) {
                graph[x][y] = '.';
            } else {
                graph[x][y] = '#';
            }
        }
    }
    graph[0][0] = 'E';
    graph[dest.first][dest.second] = 'S';
    forn(x, N) {
        forn(y, N) {
            cout << graph[x][y];
        }
        cout << endl;
    }
}
