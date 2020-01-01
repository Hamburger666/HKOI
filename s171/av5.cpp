#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; i++)
using namespace std;

int N, M, L;
int C[100000], D[100000], DMark[100000], D_size;
bool P[100000]; int Q[100000];
int T[100000], H[100000], B[100000];

int Ds[100000];
vector<int> channelChange[86401];

int programOnChannel[100000] = {0};
int channelViewCount[100000] = {0};
int programViewTime[100000] = {0};
bool householdOn[100000];
int householdChannel[100000];


int getProgramSerial(int channel, int program) {
    return DMark[channel] + program;
}

int main() {
    cin >> N >> M >> L;
    D_size = 0;
    forn(channel, N) {
        DMark[channel] = D_size;
        cin >> C[channel];
        forn(program, C[channel]) {
            cin >> D[D_size];
            D_size++;
        }
    }

    forn(household, M) {
        cin >> P[household] >> Q[household];
        Q[household]--;
    }

    forn(event, L) {
        cin >> T[event] >> H[event] >> B[event];
        H[event]--;
        B[event]--;
    }
    while(T[L-1] == 86400) {
        L--;
    }

    forn(channel, N) {
        int time = 0;
        forn(program, C[channel]) {
            int programSerial = getProgramSerial(channel, program);
            Ds[programSerial] = time;
            time += D[programSerial];
        }
    }

    forn(channel, N) {
        for (int program = 1; program < C[channel]; program++) {
            int programSerial = getProgramSerial(channel, program);
            channelChange[Ds[programSerial]].push_back(channel);
        }
        channelChange[86400].push_back(channel);
    }

    forn(household, M) {
        householdOn[household] = P[household];
        householdChannel[household] = Q[household];
        if (P[household]) {
            channelViewCount[Q[household]]++;
        }
    }
    
    int event = 0;
    forn(time, 86401) {
        forn(i, channelChange[time].size()) {
            int channel = channelChange[time][i];
            int beforeProgramSerial = getProgramSerial(channel, programOnChannel[channel]);
            programOnChannel[channel]++;
            programViewTime[beforeProgramSerial] += channelViewCount[channel] * D[beforeProgramSerial];
        }

        while (T[event] == time && event < L) {
            int household = H[event];
            int button = B[event];
            if (householdOn[household]) {
                int beforeChannel = householdChannel[household];
                int beforeProgram = programOnChannel[beforeChannel];
                int beforeProgramSerial = getProgramSerial(beforeChannel, beforeProgram);
                channelViewCount[beforeChannel]--;
                programViewTime[beforeProgramSerial] += time - Ds[beforeProgramSerial];
                if (B[event] == -1) {
                    householdOn[household] = false;
                } else {
                    int afterChannel = button;
                    int afterProgram = programOnChannel[afterProgram];
                    int afterProgramSerial = getProgramSerial(button, afterProgram);
                    channelViewCount[afterChannel]++;
                    householdChannel[household] = afterChannel;
                    programViewTime[afterProgramSerial] -= time - Ds[afterProgramSerial];
                }
            } else if (B[event] == -1) {
                int afterChannel = householdChannel[household];
                int afterProgram = programOnChannel[afterChannel];
                int afterProgramSerial = getProgramSerial(afterChannel, afterProgram);
                householdOn[H[event]] = true;
                channelViewCount[afterChannel]++;
                programViewTime[afterProgramSerial] -= time - Ds[afterProgramSerial];
            }
            event++;
        }
    }

    forn(channel, N) {
        forn(program, C[channel]) {
            int programSerial = getProgramSerial(channel, program);
            cout << (double) programViewTime[programSerial] / D[programSerial] << " ";
        }
        cout << endl;
    }
}