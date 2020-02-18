#include <iostream>
#include <unordered_set>
#include <climits>
#include <algorithm>
#include <string>
#define forn(i,n) for (long long i =0; i < n; i++)
using namespace std;
typedef long long ll;

struct d {
    bool d = false;
    string dm = "DEBUG PRINT: ";
    void printl(string name, ll *l, ll n) {if(d) {
        cout << dm << name << ": ";
        forn(i, n) {
            cout << l[i] <<" ";
        } 
        cout << endl;
    }}
    void println(string s) { if(d){
        cout << dm << s << endl;
    }}
    void printll(string s, ll n){if(d) {
        cout << dm << s << ": " << n << endl;
    }}
};

struct xy {
    ll x, y;
};
ll N, M, K;
xy a[2000]; ll ax[2000][2000], axc[2000] = {0};
ll cx[2000], cy[2000], cxc = 0, cyc = 0;
d d;

int main() {
    cin >> N >> M >> K;
    forn(i, K) {
        cin >> a[i].x;
        a[i].x--;
        cin >> a[i].y;
        a[i].y--;
    }
    unordered_set<ll> changeY, changeX;
    forn(i, K) {
        changeY.insert(a[i].y);
        changeX.insert(a[i].x);
    }
    for(ll y : changeY) {
        cy[cyc++] = y;
    }
    for(ll x : changeX) {
        cx[cxc++] = x;
    }
    d.printl("cy", cy, cyc);
    d.printl("cx", cx, cxc);
    sort(cy, cy+cyc);
    sort(cx, cx+cxc);
    ll i = 0;
    forn(xi, cxc) {
        d.printll("a[i].x", a[i].x);
        d.printll("cx[xi]", cx[xi]);
        while(a[i].x == cx[xi]) {
            ax[xi][axc[xi]] = a[i].y;
            axc[xi]++;
            i++;
        }
        d.printll("i for organise", i);
        d.printll("xi for organise", xi);
    }
    

    d.printl("ax[1]", ax[1], axc[1]);
    ll maxCost = 0;
    forn(yi, cyc) {
        ll cost = 0;
        ll xiBegin = 0;
        forn(xiEnd, cxc) {
            forn(yii, axc[xiEnd]) {
                if (cy[yi] <= ax[xiEnd][yii] && ax[xiEnd][yii]<cy[yi]+M) {
                    cost++;
                }
            }
            while(cx[xiBegin] < cx[xiEnd] - M + 1) {
                forn(yii, axc[xiBegin]) {
                    if (cy[yi] <= ax[xiBegin][yii] && ax[xiBegin][yii] < cy[yi] + M) {
                        cost--;
                    }
                }
                xiBegin++;
            }
            if (cost > maxCost) maxCost = cost;
            d.println("--------");
            d.printll("xiBegin", xiBegin);
            d.printll("xiEnd", xiEnd);
            d.println("--------");
        }
    }
    cout << maxCost << endl;
}