#include <iostream>
#include <string>
#include <stdexcept>
#define forn(i,n) for (long long i = 0; i < n; i++)
#define form(i,n) for (long long i = 1; i <= n; i++)
using namespace std;
typedef long long ll;

ll N; bool path[1000][1000]; ll pathC = 0;
struct xy {
    ll x, y;
};
struct d {
    bool d = true;
    string dm = "DEBUG PRINT: ";
    void printll(string name, ll n) { if(d) {
        cout << dm << name <<": "<<n << endl;
    }}
    void println(string s) {if(d) {
        cout << dm << s << endl;
    }}
};
d d;
bool containsUp(xy a) {
    a.y++;
    if (a.y==N) {
        return true;
    } else {
        return (path[a.x][a.y]);
    }
}

bool containsLeft(xy a) {
    a.x--;
    if (a.x == -1) {
        return true;
    } else {
        return (path[a.x][a.y]);
    }
}

bool containsRight(xy a) {
    a.x++;
    if(a.x == N) {
        return true;
    } else {
        return (path[a.x][a.y]);
    }
}

int main() {
    d.println("alive -1");
    cin >> N;
    forn(y, N) {
        ll yc = N - y - 1;
        string s;
        cin >> s;
        forn(x, N) {
            char c = s[x];
            path[x][yc] = (c=='#');
        }
    }

    d.println("alive 0");
    forn(y, N) {
        forn(x, N) {
            if (path[x][y]) pathC++;
        }
    }

    ll oldPath[1000][1000];
    forn(x, N) forn(y, N) oldPath[x][y] = path[x][y];

    bool bestTurnO[1000][1000];
    bool bestOO;
    ll bestU;
    bool successO = false;
    ll bestMonsterCO = LONG_MAX;

    forn(u, 4) {
        d.println("alive 1");
        forn(x, N) forn(y, N) path[x][y] = oldPath[x][y];
        if (u==0) {
            forn(x, N) forn(y, N) path[x][y] = oldPath[x][y]; 
        } else if (u == 1) {
            forn(x, N) forn(y, N) {
                ll yp = x;
                ll xp = N - 1 - y;
                path[xp][yp] = oldPath[x][y];
            }
        } else if (u == 2) {
            forn(x, N) forn(y, N) {
                ll yp = N - 1 - y;
                ll xp = N - 1 - x;
                path[xp][yp] = oldPath[x][y];
            }
        } else if (u ==3) {
            forn(x, N) forn(y, N) {
                ll yp = N - 1 - x;
                ll xp = y;
                path[xp][yp] = oldPath[x][y];
            }
        }
        ll x = 0;
        ll sideOk;
        while(!path[x][0] && x < N) x++;
        sideOk = (x != N);
        bool bestTurn[1000][1000];
        ll bestMosterC = LONG_MAX;
        bool bestO;
        bool success = false;
        d.println("alive 2");
        if (sideOk) forn(o, 2) { 
            ll passedC = 0;
            ll monsterC = 0;
            bool turn[1000][1000] = {0};
            xy at;
            bool up = true;
            bool good = true;
            forn(_,N) {
                ll i;
                if(o) {
                    i = N-1-_;
                } else {
                    i = _;
                }
                if (path[i][0]) {
                    at.x = i;
                    break;
                }
            }
            d.printll("start x", at.x);
            d.println(o ? "left" : "right");
            at.y = 0;
            d.println("alive 3");
            while(0<=at.x && at.x < N && 0<=at.y && at.y < N) {
                if (up) {
                    if (at.y != N-1 && containsUp(at)) {
                        at.y++;
                    } else if ((o ? at.x != 0 : at.x != N-1) && (o ? containsLeft(at) : containsRight(at))) {
                        monsterC++;
                        turn[at.x][at.y] = true;
                        if (o) at.x--;
                        else at.x++;
                        up = false;
                    } else if (containsUp(at)) {
                        at.y++;
                    } else if (o ? containsLeft(at) : containsRight(at)) {
                        monsterC++;
                        turn[at.x][at.y] = true;
                        if (o) at.x--;
                        else at.x++;
                        up = false;
                    } else {
                        // throw runtime_error("");
                        good = false;
                        break;
                    }
                } else {
                    if ((o ? at.x != 0 : at.x != N-1) && (o ? containsLeft(at) : containsRight(at))) {
                        if (o) at.x--;
                        else at.x++;
                        d.println("1");
                    } else if (at.y != N-1 && containsUp(at)) {
                        monsterC++;
                        turn[at.x][at.y] = true;
                        at.y++;
                        up = true;
                        d.println("2");
                    } else if (o ? containsLeft(at) : containsRight(at)) {
                        if (o) at.x--;
                        else at.x++;
                        d.println("3");
                    } else if (containsUp(at)) {
                        monsterC++;
                        turn[at.x][at.y] = true;
                        at.y++;
                        up = true;
                        d.println("4");
                    } else {
                        // throw runtime_error("");
                        good = false;
                        d.println("5");
                        break;
                    }
                }
                passedC++;
            }
            if (passedC == pathC && good && monsterC < bestMosterC) {
                success = true;
                bestO = o;
                if (u==0) {
                    forn(x, N) forn(y, N) bestTurn[x][y] = turn[x][y]; 
                } else if (u == 1) {
                    forn(xp, N) forn(yp, N) {
                        ll x = yp;
                        ll y = N - 1 - xp;
                        bestTurn[xp][yp] = turn[x][y];
                    }
                } else if (u == 2) {
                    forn(xp, N) forn(yp, N) {
                        ll y = N - 1 - yp;
                        ll x = N - 1 - xp;
                        bestTurn[xp][yp] = turn[x][y];
                    }
                } else if (u ==3) {
                    forn(xp, N) forn(yp, N) {
                        ll x = N - 1 - yp;
                        ll y = xp;
                        bestTurn[xp][yp] = turn[x][y];
                    }
                }
            }
        }
        d.println("alive 4");
        if (success && bestMosterC < bestMonsterCO) {
            forn(x, N) forn(y, N) bestTurnO[x][y] = bestTurn[x][y];
            bestOO = bestO;
            bestU = u;
            successO = true;
        }
    }

    if (successO) {
        if (bestU == 1 || bestU == 3) {
            bestOO = !bestOO;
        } 
        forn(y, N) {
            ll yc = N - y - 1;
            string s(N, '+');
            forn(x, N) {
                s[x] = (bestTurnO[x][yc] ? (bestOO ? '\\' : '/' ) : '.');
            }
            cout << s << endl;
        }
    } else {
        cout << "Impossible" << endl;
        return 0;
    }

}
