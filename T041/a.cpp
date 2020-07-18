// I give up. So annoying
#include <iostream>
#include <queue>
#include <stdexcept>
#include <string>
#define forn(i, n) for (long long i = 0; i < n; i++)
#define INF 40000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll P;
pll A, B;
char board[100][100];
char K;
ll dists[100][100][4];
pair<pll, ll> prevP[100][100][4];
priority_queue<pair<ll, pair<pll, ll> > > toFinalize; // {-dist, {{point}, u}}

ll nextU(ll u) {
    u++;
    if (u >= 4) {
        u -= 4;
    }
    return u;
}

pll moveP(pll p, ll u) {
    if (u == 0) {
        p.first++;
    } else if (u == 1) {
        p.second++;
    } else if (u == 2) {
        p.first--;
    } else if (u == 3) {
        p.second--;
    } else {
        throw runtime_error("");
    }
    return p;
}

bool inBound(pll p) {
    return (
        0 <= p.first &&
        0 <= p.second &&
        p.first < P &&
        p.second < P
    );
}

ll getDist(pll p, ll u) {
    return dists[p.first][p.second][u];
}

void setDist(pll p, ll u, ll v) {
    dists[p.first][p.second][u] = v;
}

void setPrev(pll p, ll u, pll pr, ll ur) {
    prevP[p.first][p.second][u] = make_pair(pr, ur);
}

int main() {
    cin >> P;
    forn(y, P) {
        string s;
        cin >> s;
        forn(x, P) {
            board[x][y] = s[x];
            if (s[x] == 'A') {
                A.first = x;
                A.second = y;
            }
            if (s[x] == 'B') {
                B.first = x;
                B.second = y;
            }
        }
    }
    forn(y, P) {
        forn(x, P) {
            cout << board[x][y];
        }
        cout << endl;
    }
    cin >> K;
    forn(x, P) forn(y, P) forn(u, 4) {
        dists[x][y][u] = INF;
    }
    ll startU;
    if (K == 'E') {
        startU = 0;
    } else if (K == 'S') {
        startU = 1;
    } else if (K == 'W') {
        startU = 2;
    } else if (K == 'N') {
        startU = 3;
    } else {
        throw runtime_error("");
    }
    dists[B.first][B.second][startU] = 0;
    toFinalize.push(make_pair(0ll, make_pair(B, startU)));
    while (!toFinalize.empty()) {
        cout << "c2" << endl;
        ll dist = -toFinalize.top().first;
        pll p = toFinalize.top().second.first;
        ll u = toFinalize.top().second.second;
        toFinalize.pop();
        if (getDist(p, u) == dist) {
            pll pm = moveP(p, u);
            if (inBound(pm) && board[pm.first][pm.second] != '1' && getDist(pm, u) > getDist(p, u) + 1) {
                setDist(pm, u, getDist(p, u) + 1);
                toFinalize.push(make_pair(-getDist(pm, u), make_pair(pm, u)));
                setPrev(pm, u, p, u);
            }
            if (getDist(p, nextU(u)) > getDist(p, u) + 1) {
                setDist(p, nextU(u),  getDist(p, u) + 1);
                toFinalize.push(make_pair(-getDist(p, nextU(u)), make_pair(p, nextU(u))));
                setPrev(p, nextU(u), p, u);
            }
        }
    }
    forn(y, P) {
        forn(x, P) {
            cout << "(";
            forn(u, 4) {
                cout << dists[x][y][u] << " ";
            }   
            cout << ")";
        }
        cout << endl;
    }
    ll minD = INF;
    ll minDU;
    forn(u, 4) {
        if (getDist(A, u) < minD) {
            minD = getDist(A, u);
            minDU = u;
        }
    }
    cout << minD << endl;
    vector<char> moves; 
    pll p = B;
    ll u = minDU;
    while(p != A || u != startU) {
        cout << p.first << " " << p.second << " " << u << endl;
        pair<pll, ll> t = prevP[p.first][p.second][u];
        if (t.first != p) {
            moves.push_back('M');
        } 
        if (t.second != u) {
            moves.push_back('T');
        }
        p = t.first;
        u = t.second;
    }
    for (ll i = moves.size() - 1; i >= 0; i--) {
        cout << moves[i];
    }
    cout << endl;
}