#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; i++)
#define forRange(i, n, m) for (int i = n; i < m; i++)
using namespace std;

int N, M, L;
int C[100000], D[100000], Dp[100000], DMarker[100000], D_size;
bool P[100000], Pp[100000]; int Q[100000], Qp[100000],
T[100000], H[100000], B[100000];
vector<int> channelSwitch[86400], programAfter[86400];
int householdSwitch_size, householdSwitchTime[100001], channelAfter[100001], channelBefore[100001],
programInChannel[100000], channelViewerCount[100000], programWatchTime[100000];
 
int main() {
    cin >> N >> M >> L;

    forn(i, N) {
        cin >> C[i];
        DMarker[i] = D_size; 
        forn(j, C[i]) cin >> D[D_size++];
    }

    forn(i, M) {
        cin >> P[i] >> Q[i];
        Q[i]--;
        Pp[i] = P[i];
        Qp[i] = Q[i];
    }
    forn(i, L) {
        cin >> T[i] >> H[i] >> B[i];
        H[i]--;
        B[i]--;
    }
    int i = L - 1;
    while (T[i] == 86400) L--;

    
    forn(channel, N) {
        int time = 0;
        forn(program, C[channel]) {
            int programSerial = DMarker[channel] + program;
            Dp[programSerial] = time;
            time += D[programSerial];
        }
    }

    forn(channel, N) {
        int time = 0;
        forn(program, C[channel]) {
            int programSerial = DMarker[channel] + program;
            channelSwitch[time].push_back(channel);
            programAfter[time].push_back(program);
            time += D[programSerial];
        }
    }

    forn(i, L) {
        int time = T[i];
        int household = H[i];
        int button = B[i];
        if (Pp[household]) {
            householdSwitchTime[householdSwitch_size] = time;
            channelBefore[householdSwitch_size] = Qp[household];
            if (button == -1) Pp[household] = false;   
            else              Qp[household] = button;
            if (Pp[household]) channelAfter[householdSwitch_size] = Qp[household];
            else               channelAfter[householdSwitch_size] = -1;
            householdSwitch_size++;
        } else {
            if (button == -1) {
                Pp[household] = true;
                householdSwitchTime[householdSwitch_size] = time;
                channelBefore[householdSwitch_size] = -1;
                channelAfter[householdSwitch_size] = Qp[household];
                householdSwitch_size++;
            }
        }
    }

    householdSwitchTime[householdSwitch_size] = 86400;
    householdSwitch_size++;

    forn(channel, N) {
        programInChannel[channel] = 0;
        channelViewerCount[channel] = 0;
    }

    forn(household, M) {
        if (P[household]) {
            int channel = Q[household];
            channelViewerCount[channel]++;
        }
    }

    int householdSwitch_i = 0;
    while (householdSwitchTime[householdSwitch_i] == 0) {
        if (channelBefore[householdSwitch_i] != -1) channelViewerCount[channelBefore[householdSwitch_i]]--;
        if (channelAfter[i] != -1)  channelViewerCount[channelAfter[householdSwitch_i]]++;
        householdSwitch_i++;
    }

    forRange(time, 1, 86400) {
        while (householdSwitchTime[householdSwitch_i] == time) {
            if (channelBefore[householdSwitch_i] != -1) {
                int channel = channelBefore[householdSwitch_i];
                int program = programInChannel[channel];
                int programSerial = DMarker[channel] + program;
                programWatchTime[programSerial] += time - Dp[programSerial];
                channelViewerCount[channel]--;
            }
            if (channelAfter[householdSwitch_i] != -1) {
                int channel = channelAfter[householdSwitch_i];
                int program = programInChannel[channel];
                int programSerial = DMarker[channel] + program;
                programWatchTime[programSerial] -= time - Dp[programSerial];
                channelViewerCount[channel]++;
            }
            householdSwitch_i++;
        }
        forn(event, channelSwitch[time].size()) {
            int channel = channelSwitch[time][event];
            int program = programAfter[time][event] - 1;
            int programSerial = DMarker[channel] + program;
            programWatchTime[programSerial] += channelViewerCount[channel] * D[programSerial];
            programInChannel[channelSwitch[time][event]] = programAfter[time][event];
        }
    }

    forn(channel, N) {
        forn(program, C[channel]) {
            int programSerial = DMarker[channel] + program;
            cout << (double) programWatchTime[programSerial] / D[program] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
