#include <iostream>
#include <string>
#include <stdexcept>
#define forn(i,n) for (long long i = 0; i < n; i++)
#define form(i,n) for (long long i = 1; i <= n; i++)
using namespace std;
typedef long long ll;

ll N; bool path[1000][1000]; ll pathC = 0; ll rawPath[1000][1000];

struct xy {
    ll x, y;
};
struct d {
    bool d = false;
    string dm = "DEBUG PRINT: ";
    void printll(string name, ll n) { if(d) {
        cout << dm << name <<": "<<n << endl;
    }}
    void println(string s) {if(d) {
        cout << dm << s << endl;
    }}
    void printPath() {if(d){
        cout << dm << "------" << endl;
        forn(y, N) {
            ll yc = N - y - 1;
            string s(N, '+');
            forn(x, N) {
                s[x] = (path[x][yc] ? 'x' : '.');
            }
            cout << s << endl;
        }
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

    forn(y, N) {
        forn(x, N) {
            if (path[x][y]) pathC++;
        }
    }
    forn(x, N) forn(y, N) rawPath[x][y] = path[x][y];

    bool bestTurn[1000][1000];
    bool bestO;
    ll bestU;
    ll bestMonsterC = LONG_MAX;
    bool success = false;
    forn(u, 4) {
        d.printll("u", u);
        if (u==0) {
            forn(x, N) forn(y, N) path[x][y] = rawPath[x][y];
        } else if (u == 1) {
            forn(x, N) forn(y, N) {
                ll xp = N - y - 1;
                ll yp = x;
                path[xp][yp] = rawPath[x][y];
            }
        } else if (u == 2) {
            forn(x, N) forn(y, N) {
                ll xp = N - x - 1;
                ll yp = N - y - 1;
                path[xp][yp] = rawPath[x][y];
            }
        } else if (u == 3) {
            forn(x, N) forn(y, N) {
                ll xp = y;
                ll yp = N - x - 1;
                path[xp][yp] = rawPath[x][y];
            }
        }
        d.printPath();
        ll x = 0;
        while(!path[x][0] && x < N) x++;
        if (x == N) {
            continue;
        } 
        forn(o, 2) { 
            ll passedC = 0;
            bool turn[1000][1000] = {0}; ll monsterC = 0;
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
            if (passedC == pathC && good && monsterC < bestMonsterC) {
                success = true;
                bestO = o;
                bestU = u;
                bestMonsterC = monsterC;
                if (u == 0) {
                    forn(y, N) forn(x,N) bestTurn[x][y] = turn[x][y];
                } else if (u == 1) {
                    forn(x, N) forn(y, N) {
                        ll xp = y;
                        ll yp = N - x - 1;
                        bestTurn[xp][yp] = turn[x][y];
                    }
                } else if (u == 2) {
                    forn(x, N) forn(y, N) {
                        ll xp = N - x - 1;
                        ll yp = N - y - 1;
                        bestTurn[xp][yp] = turn[x][y];
                    }
                } else if (u == 3) {
                    forn(x, N) forn(y, N) {
                        ll xp = N - y - 1;
                        ll yp = x;
                        bestTurn[xp][yp] = turn[x][y];
                    }
                }
            }
        }
    }

    if (success) {
        if (bestU == 1 || bestU == 3) {
            bestO = !bestO;
        } 
        forn(y, N) {
            ll yc = N - y - 1;
            string s(N, '+');
            forn(x, N) {
                s[x] = (bestTurn[x][yc] ? (bestO ? '\\' : '/' ) : '.');
            }
            cout << s << endl;
        }
    } else {
        cout << "Impossible" << endl;
        return 0;
    }

}
