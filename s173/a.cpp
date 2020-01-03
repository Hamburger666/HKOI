#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; i++) 
#define MN 200000
using namespace std;

int N, M;
vector<int> radars[MN];


unordered_map<int, int> changeList;


int main() {
    cin >> N >> M;
    forn(radarId, M) {
        int size;
        cin >> size;
        radars[radarId].resize(size);
        forn(i, size) {
            cin >> radars[radarId][i];
            radars[radarId][i]--;
        }
    }

    int radarId = 0, solvedNo = 0;

    while (radarId < M && solvedNo < N) {
        changeList.clear();
        forn(i, radars[radarId].size()) {
            int oldGroup = 
        }
        radarId++;
    }
    if (solvedNo == N) {
        cout << radarId << endl;
    } else {
        cout << "Impossible" << endl;
    }
}