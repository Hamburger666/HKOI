#include<bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)

int N, M, L;
int C[100000], D[100000], Ds[100000], DMark[100000], D_size;
int P[100000], Q[100000];
int T[100000], H[100000], B[100000];

int householdSwichTime[100001], channelBefore[100001], channelAfter[100001], h_size;
vector<int> channelSwitchChannel[864001];

int channelProgram[100000] = {0}, channelViewerCount[100000] = {0}, programViewTime[100000] = {0};


int getProgramSerial(int channel, int program) {
    return DMark[channel] + program;
}

int main() {
    cin >> N >> M >> L;
    D_size = 0;
    forn(i, N) {
        DMark[i] = D_size;
        cin >> C[i];
        forn(j, C[i]) {
            cin >> D[D_size];
            D_size++;
        }
    }
    forn(i, M) {
        cin >> P[i] >> Q[i];
        Q[i]--;
    }
    forn(i, L) {
        cin >> T[i] >> H[i] >> B[i];
        H[i]--;
        B[i]--;
    }

    forn(channel, N) {
        int time = 0;
        forn(program, C[channel]) {
            int programSerial = getProgramSerial(channel, program);
            Ds[programSerial] = time;
            time += D[programSerial];
        }
    }

    int householdChannel[100000], householdOn[100000];
    forn(household, M) {
        householdOn[household] = P[household];
        householdChannel[household] = Q[household];
    }

    h_size = 0;
    forn(switchEvent, L) {
        int time = T[switchEvent];
        int household = H[switchEvent];
        int button = B[switchEvent];
        if (householdOn[household]) {
            householdSwichTime[h_size] = time;
            channelBefore[h_size] = householdChannel[household];
            if (button == -1) {
                channelAfter[h_size] = -1;
                householdOn[household] = false;
            } else {
                channelAfter[h_size] = button;
                householdChannel[household] = button;
            }
            h_size++;
        } else if (button == -1) {
            householdSwichTime[h_size] = time;
            channelBefore[h_size] = -1;
            channelAfter[h_size] = householdChannel[household];
            h_size++;
            householdOn[household] = true;
        }
    }
    householdChannel[h_size] = 86401;
    h_size++;

    forn(channel, N) {
        for (int program = 1; program < C[channel]; program++) {
            int programSerial = getProgramSerial(channel, program);
            int time = Ds[programSerial];
            channelSwitchChannel[time].push_back(channel);
        }
        channelSwitchChannel[86400].push_back(channel);
    }

    forn(household, M) {
        if (P[household]) {
            int channel = Q[household];
            channelViewerCount[channel]++;
        }
    }
    int i = 0;
    
    forn(time, 86401) {
        forn(event, channelSwitchChannel[time].size()) {
            int channel = channelSwitchChannel[time][event];
            int program = channelProgram[channel];
            int programSerial = getProgramSerial(channel, program);
            programViewTime[programSerial] += channelViewerCount[channel] * D[programSerial];
            channelProgram[channel]++;
            printf("program changed: channel = %d, program = %d, views = %d, time added = %d, program view time = %d\n", channel, program, channelViewerCount[channel], channelViewerCount[channel] * D[programSerial], programViewTime[programSerial]);
            
        }
        while(householdSwichTime[i] == time) {
            printf("event household switch, time = %d, channel before = %d, channel after = %d\n", time, channelBefore[i], channelAfter[i]);
            if (channelBefore[i] != -1) {
                int channel = channelBefore[i];
                int program = channelProgram[channel];
                int programSerial = getProgramSerial(channel, program);
                programViewTime[programSerial] += time - Ds[programSerial];
                channelViewerCount[channel]--;
            } 
            if (channelAfter[i] != -1) {
                int channel = channelAfter[i];
                int program = channelProgram[channel];
                int programSerial = getProgramSerial(channel, program);
                programViewTime[programSerial] -= time - Ds[programSerial];
                channelViewerCount[channel]++;
            }
            printf("viewer count channel before = %d (channel(%d)), viewer count channel after = %d (channel(%d))\n", 
            channelViewerCount[channelBefore[i]], channelBefore[i], channelViewerCount[channelAfter[i]], channelAfter[i]);
            i++;
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