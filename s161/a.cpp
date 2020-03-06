#include <iostream>
#include <string>
#include <unordered_map>
#define forn(i,n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

struct rc {
    ll r, c;
};
struct d {
    bool d = false;
    string dm = "DEBUG PRINT: ";
    void println(string s) { if (d) {
        cout << dm << s << endl;
    }}
    void printll(string name, ll n) { if(d) {
        cout << dm << name << ": " << n << endl;
    }}
};
void move(rc& co, char c) {
    if (c == 'U') {
        co.r--;
    } else if (c == 'D') {
        co.r++;
    } else if (c == 'L') {
        co.c--;
    } else if (c == 'R') {
        co.c++;
    }
}

ll encode(rc co) {
    return co.r * 1000000000 + co.c;
}
ll N, K;
rc at;
string s;
unordered_map<ll, ll> visited;
d d;
int main() {
    cin >> N >> K;
    cin >> at.r; at.r--;
    cin >> at.c; at.c--;
    cin >> s;
    visited[encode(at)]--;
    forn(i, 1001) {
        if (!(0<=at.r && at.r < N && 0<=at.c && at.c<N)) {
            break;
        }
        long long i2 = 0;
        while(0<=at.r && at.r < N && 0<=at.c && at.c<N && i2 < K){
            visited[encode(at)]++;
            // d.printll("encoded", encode(at));
            // d.println(to_string(at.r) + " " + to_string(at.c));
            move(at, s[i2]);
            i2++;
        }
    }

    ll maxCost = 0;
    for (pair<ll, ll> it : visited) {
        // d.println("at " + to_string(it->first) + " value is " + to_string(it->second));
        maxCost = max(it.second, maxCost);
    } 

    cout << maxCost << endl;
}