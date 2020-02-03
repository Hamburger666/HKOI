#include <iostream>
#include <limits>
#include <stdexcept>
#include <queue>
#define forn(i, n) for (long long i = 0; i < n; i++)
#define form(i, n) for (long long i = 1; i <= n; i++)
using namespace std;


struct icon {
    long long r, c, v;
    bool d;
};
struct cell {
    long long r, c;
};
struct cell2 {
    long long r1, r2, c1, c2;
};
struct in {
    long long i;
    bool d;
};

// white = true, black = false
bool wallPapers[100][80][80]; long long wallPapers_count = 0;
icon icons[6400]; long long icons_count = 0;
icon iconsD[2][6400]; long long iconsD_count[2] = {0};
long long cumCost[2][6401];
cell iconsTo[2][6400];

long long N, R, C;
long long K;

deque<cell2> st;

bool comp(icon a, icon b) {
    return (a.v > b.v);
}

int main() {
    // ---- START loading data ------
    cin >> N >> R >> C;

    forn(i, N) {
        long long r, c; char d; long long v;
        cin >> r >> c >> d >> v;
        r--;
        c--;
        icons[icons_count].c = c;
        icons[icons_count].r = r;
        icons[icons_count].d = (d == 'W');
        icons[icons_count].v = v;
        icons_count++;
    }

    cin >> K;
    forn(i, K) {
        forn(r, R) forn(c, C) {
            char b;
            cin >> b;
            wallPapers[wallPapers_count][r][c] = (b == 'W');
        }
        wallPapers_count++;
    }
    // ---- DONE loading data -----

    if (N == R * C) {
        long long maxCost_cost = 0, maxCost_wallPapaper;
        forn(i, wallPapers_count) {
            long long cost = 0;
            forn(j, N) {
                icon c = icons[j];
                if (c.d != wallPapers[i][c.r][c.c]) {
                    cost += c.v;
                }
            }
            if (cost >= maxCost_cost) {
                maxCost_cost = cost;
                maxCost_wallPapaper = i;
            }
        }
        cout << maxCost_cost << " " << maxCost_wallPapaper + 1 << " " << 0 << endl;
    } else {

        forn(i, icons_count) {
            iconsD[icons[i].d][iconsD_count[icons[i].d]].c = icons[i].c;
            iconsD[icons[i].d][iconsD_count[icons[i].d]].r = icons[i].r;
            iconsD[icons[i].d][iconsD_count[icons[i].d]].d = icons[i].d;
            iconsD[icons[i].d][iconsD_count[icons[i].d]].v = icons[i].v;
            iconsD_count[icons[i].d]++;
        }

        sort(iconsD[0], iconsD[0]+iconsD_count[0], comp);
        sort(iconsD[1], iconsD[1]+iconsD_count[1], comp);

        forn(d, 2) {
            long long sum = 0;
            forn(i, iconsD_count[d]) {
                cumCost[d][i] = sum;
                sum += iconsD[d][i].v;
            }
            cumCost[d][iconsD_count[d]] = sum;
        }

        long long maxCost_cost = 0, maxCost_wallPapaper;
        forn(i, wallPapers_count) {
            long long dC[2] = {0};
            forn(r, R) forn(c, C) {
                dC[wallPapers[i][r][c]]++;
            }
            long long cost = 0;
            forn(d, 2) {
                cost += cumCost[d][min(iconsD_count[d], dC[!d])];
            }
            if (cost >= maxCost_cost) {
                maxCost_cost = cost;
                maxCost_wallPapaper = i;
            }
        }
        
        int cost_m = 0;
        forn(b, 2) {
            forn(i, iconsD_count[b]) {
                icon ce = iconsD[b][i];
                if (ce.d != wallPapers[maxCost_wallPapaper][ce.r][ce.c]) {
                    cost_m += ce.v;
                }
            }
        }

        bool map[80][80] = {0};
        forn(i, N) {
            icon ce = icons[i];
            map[ce.r][ce.c] = true;
        }

        deque<cell> freeSpace[2];
        forn(r, R) forn(c, C) {
            if (!map[r][c]) {
                cell ce; ce.r = r; ce.c = c;
                bool d = wallPapers[maxCost_wallPapaper][r][c];
                freeSpace[d].push_back(ce);
            }
        }

        long long dC[2] = {0};
        forn(r, R) forn(c, C) {
            dC[wallPapers[maxCost_wallPapaper][r][c]]++;
        }
        bool d = 0;
        int i[2] = {0};
        int ib[2];
        forn(d, 2) {
            ib[d] = iconsD_count[d] -1;
        }
        while (cost_m != maxCost_cost) {
            while (!freeSpace[d].empty()) {
                cell to = freeSpace[d].front();

                if (i[!d] < iconsD_count[!d]) {
                    icon ce = iconsD[!d][i[!d]];
                    if (ce.d == wallPapers[maxCost_wallPapaper][ce.r][ce.c]) {
                        cell2 ce2; ce2.r1 = ce.r; ce2.c1 = ce.c; ce2.r2 = to.r; ce2.c2 = to.c;
                        cell newEmpty; newEmpty.r = ce.r; newEmpty.c = ce.c;
                        freeSpace[!d].push_back(newEmpty);
                        st.push_back(ce2);
                        freeSpace[d].pop_front();
                        cost_m += ce.v;
                    }
                    i[!d]++;
                } else if (ib[d] >= dC[!d]) {
                    icon ce = iconsD[d][ib[d]];
                    if (ce.d != wallPapers[maxCost_wallPapaper][ce.r][ce.c]) {
                        cell2 ce2; ce2.r1 = ce.r; ce2.c1 = ce.c; ce2.r2 = to.r; ce2.c2 = to.c;
                        cell newEmpty; newEmpty.r = ce.r; newEmpty.c = ce.c;
                        freeSpace[!d].push_back(newEmpty);
                        freeSpace[d].pop_front();
                        st.push_back(ce2);
                        cost_m -= ce.v;

                    }
                    ib[d]--;
                } else {
                    break;
                }
            }
            d = !d;
        }

        cout << maxCost_cost << " " << maxCost_wallPapaper + 1 << " " << st.size() << endl;

        forn(i, st.size()) {
            cout << st[i].r1 + 1 << " " << st[i].c1 + 1 << " " << st[i].r2 + 1 << " " << st[i].c2 + 1<< endl;
        }

    }
}