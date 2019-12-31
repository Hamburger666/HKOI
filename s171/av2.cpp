#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; i++) 
using namespace std;

int N, M, L,
C[100000], D[100000], CMark[100000], D_size;
bool P[100000]; int Q[100000],
T[100000], H[100000], B[100000];

int Ds[100000];
bool householdOn[100000]; int householdChannel[100000];
int householdSwitchChannel_size, householdSwitchChannelTime[100001], channelBefore[100001], channelAfter[100001];
vector<int> channelSwitchProgram[86400];
int programOnChannel[100000];
int channelViewerCount[100000],
programViewTime[100000];

int main() {
    D_size = 0;
    cin >> N >> M >> L;
    forn(channel, N) {
        cin >> C[channel];
        CMark[channel] = D_size;
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

    // DEBUG: check input
    forn(programSerial, D_size) {
        cout << D[programSerial] << " ";
    }
    cout << endl;
    forn(household, M) {
        printf("Pi = %d, Qi = %d\n", P[household], Q[household]);
    }
    // -----

    // remove redundant back end
    int i = L-1;
    while (T[i] == 84600) {
        i--;
        L--;
    }

    // calculate the cumulated time
    forn(channel, N) {
        int time = 0;
        forn(program, C[channel]) {
            int programSerial = CMark[channel] + program;
            Ds[programSerial] = time;
            time += D[programSerial];
        }
    }
        // DEBUG: check calc
    forn(programSerial, D_size) {
        cout << Ds[programSerial] << " ";
    }
    cout << endl;
    forn(channel, N) {
        forn(program, C[channel]) {
            int programSerial = CMark[channel] + program;
            cout << Ds[programSerial] << " ";
        }
    }
    cout << endl;
        // ------

    //------

    // recored household channel switch
    forn(household, M) {
        householdChannel[household] = Q[household];
    }

    householdSwitchChannel_size = 0;
    forn(event, L) {
        int time = T[event];
        int household = H[event];
        int button = B[event];
        if (householdOn[household]) {
            householdSwitchChannelTime[householdSwitchChannel_size] = time;
            channelBefore[householdSwitchChannel_size] = householdChannel[household];
            if (button == -1) {
                channelAfter[householdSwitchChannel_size] = -1;
                householdOn[household] = false;
            } else {
                channelAfter[householdSwitchChannel_size] = button;
                householdChannel[household] = button;
            }
            householdSwitchChannel_size++;
        } else {
            if (button == -1) {
                householdSwitchChannelTime[householdSwitchChannel_size] = time;
                channelBefore[householdSwitchChannel_size] = -1;
                channelAfter[householdSwitchChannel_size] = householdChannel[household];
                householdSwitchChannel_size++;
                householdOn[household] = true;
            }
        }
    }
        //add ceilling
    householdSwitchChannelTime[householdSwitchChannel_size] = 86400; 
    householdSwitchChannel_size++; 
        //------

        // DEBUG: check the recorded events
    forn(event, householdSwitchChannel_size) {
        cout << householdSwitchChannelTime[event] << " " << channelBefore[event] << " " << channelAfter[event] << endl;
    }
        // -----
    //-----

    // record channel program switch
    forn(channel, N) {
        forn(program, C[channel]) {
            int programSerial = CMark[channel] + program;
            int time = Ds[programSerial];
            channelSwitchProgram[time].push_back(channel);
        }
    }
    //-----

    // DEBUG: check channel switch record
    cout << "DEBUG: check channel switch record" << endl;
    forn(time, 86400) {
        forn (event, channelSwitchProgram[time].size()) {
            cout << time << " " << channelSwitchProgram[time][event] << endl;
        }
    }

    // Get things at t=0 rolling
        // Initialise a few things
    forn(channel, N) {
        channelViewerCount[channel] = 0;
        programOnChannel[channel] = 0;
    }
    forn(household, M) {
        int channel = Q[household];
        if (P[household]) {
            channelViewerCount[channel]++;
        }
    }
    forn(programSerial, D_size) {
        programViewTime[programSerial] = 0;
    }
        // ------
    int channelSwitch_i = 0;
    while (householdSwitchChannelTime[channelSwitch_i] == 0) {
        if (channelBefore[channelSwitch_i] != -1) {
            channelViewerCount[channelBefore[channelSwitch_i]]--;
        }
        if (channelAfter[channelSwitch_i != -1]) {
            channelViewerCount[channelAfter[channelSwitch_i]]++;
        }
        channelSwitch_i++;
    }
    //----
    cout << "channelSwitch_i " << channelSwitch_i << endl;
    for (int time = 1; time < 86400; time++) {
        forn(event, channelSwitchProgram[time].size()) {
            cout << "time " << time << endl;
            int channel = channelSwitchProgram[time][event];
            cout << "viewers " << channelViewerCount[channel] << endl;
            int program = programOnChannel[channel];
            int programSerial = CMark[channel] + program;
            programViewTime[programSerial] += channelViewerCount[channel] * D[programSerial];
            programOnChannel[channel]++;
        }
        while (householdSwitchChannelTime[channelSwitch_i] == time) {
            printf("channelBefore: %d, channelAfter: %d\n", channelBefore[channelSwitch_i], channelAfter[channelSwitch_i]);
            if (channelBefore[channelSwitch_i] != -1) {
                int channel = channelBefore[channelSwitch_i];
                int program = programOnChannel[channel];
                int programSerial = CMark[channel] + program;
                channelViewerCount[channel]--;
                programViewTime[programSerial] += time - Ds[programSerial];
            }
            if (channelAfter[channelSwitch_i] != -1) {
                int channel = channelAfter[channelSwitch_i];
                int program = programOnChannel[channel];
                int programSerial = CMark[channel] + program;
                channelViewerCount[channel]++;
                programViewTime[programSerial] -= time - Ds[programSerial];
            }
            channelSwitch_i++;
        }
    }

    forn (channel, N) {
        int program = C[channel] - 1;
        int programSerial = CMark[channel] + program;
        cout << programSerial << " =? " << D_size - 1 << endl;
        cout << channelViewerCount[channel] * D[programSerial] << endl;
        programViewTime[programSerial] += channelViewerCount[channel] * D[programSerial];
    }

    forn (channel, N) {
        forn (program, C[channel]) {
            int programSerial = CMark[channel] + program;
            cout << (double) programViewTime[programSerial] / D[programSerial] << " ";
        }
        cout << endl;
    }
}