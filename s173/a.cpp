#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; i++) 
#define MN 200000
using namespace std;

int N, M;
vector<int> radars[MN];


unordered_map<int, int> changeList;
unordered_set<int> groups[MN]; int groups_size = 0;
int groupOfCaves[MN] = {0};
bool solved[MN];


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

    if (N == 1) {
        cout << 0 << endl;
        exit(0);
    }

    forn(cave, N) {
        groups[0].insert(cave);
    }
    groups_size = 1;

    int radarId = 0, solvedNo = 0;
    while (radarId < M && solvedNo < N) {
        changeList.clear();
        forn(i, radars[radarId].size()) {
            int cave = radars[radarId][i];
            if (solved[cave]) {
                continue;
            }
            int oldGroup = groupOfCaves[cave];
            int newGroup;
            if (changeList.find(oldGroup) != changeList.end()) {
                newGroup = changeList[oldGroup];
            } else {
                newGroup = groups_size;
                changeList[oldGroup] = newGroup;
                groups_size++;
            }
            groups[oldGroup].erase(cave);
            groups[newGroup].insert(cave);
            groupOfCaves[cave] = newGroup;
        }
        for (pair<int, int> change : changeList) {
            int oldGroup = change.first;
            int newGroup = change.second;
            if (groups[oldGroup].size() == 1) {
                int cave = *groups[oldGroup].begin();
                solved[cave] = true;
                solvedNo++;
            }
            if (groups[newGroup].size() == 1) {
                int cave = *groups[newGroup].begin();
                solved[cave] = true;
                solvedNo++;
            }
        }
        radarId++;
    }
    if (solvedNo == N) {
        cout << radarId << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}