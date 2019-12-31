#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; i++) 
using namespace std;

int N, M, L,
C[100000], D[100000], CMark__channel_programSerial[100000], DC__programSerial;
bool P[100000]; int Q[100000],
T[100000], H[100000], B[100000];

int householdOn__household_on[10000], householdChannel__household_channel[100000];
int DSum__programSerial_startTime[10000];

int householdCChannel__serial_time[100001], channelBefore__serial_channel[100001], channelAfter__serial_channel[100001], householdCChannelC__serial;
vector<int> channelCProgram__time_event_channel[86400];

int currentProgram__channel_program[100000], channelViews__channel_viewC[100000],
programViewDuration__programSerial_duration[100000];

int main() {
    // load data 
    cin >> N >> M >> L;
    DC__programSerial = 0;
    forn(channel, N) {
        cin >> C[channel];
        CMark__channel_programSerial[channel] = DC__programSerial;
        forn(program, C[channel]) {
            cin >> D[DC__programSerial];
            DC__programSerial++;
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
    int i = L-1;
    while (T[i] == 86400) {
        L--;
        i--;
    }
    // ----

    // organise events
    forn(household, M) {
        householdOn__household_on[household] = P[household];
        householdChannel__household_channel[household] = Q[household];
    }
    
    householdCChannelC__serial = 0;
    forn(event, L) {
        if (householdOn__household_on[H[event]]) {
            householdCChannel__serial_time[householdCChannelC__serial] = T[event];
            channelBefore__serial_channel[householdCChannelC__serial] = householdChannel__household_channel[H[event]];
            if (B[event] == -1) {
                householdOn__household_on[H[event]] = false;
                channelAfter__serial_channel[householdCChannelC__serial] = -1;
            } else {
                householdChannel__household_channel[H[event]] = B[event];
                channelAfter__serial_channel[householdCChannelC__serial] = B[event];
            }
            householdCChannelC__serial++;
        } else if (B[event] == -1) {
            householdCChannel__serial_time[householdCChannelC__serial] = T[event];
            channelBefore__serial_channel[householdCChannelC__serial] = -1;
            channelAfter__serial_channel[householdCChannelC__serial] = householdChannel__household_channel[H[event]];
            householdCChannelC__serial++;
            householdOn__household_on[H[event]] = true;
        }
    }
    householdCChannel__serial_time[householdCChannelC__serial] = 86400;
    householdCChannelC__serial++;

    forn(channel, N) {
        int time = 0;
        forn(program, C[channel]) {
            int programSerial = CMark__channel_programSerial[channel] + program;
            DSum__programSerial_startTime[programSerial] = time;
            time += D[programSerial];
        }
    }

    forn(channel, N) {
        forn(program, C[channel]) {
            int programSerial = CMark__channel_programSerial[channel] + program;
            int time = DSum__programSerial_startTime[programSerial];
            channelCProgram__time_event_channel[time].push_back(channel);
        }
    }
    // ------

    // main loop
        // some set up
    
    forn(channel, N) {
        currentProgram__channel_program[channel] = 0;
        channelViews__channel_viewC[channel] = 0;
    }
    forn(household, M) {
        if (P[household]) {
            channelViews__channel_viewC[Q[household]]++;
        }
    }
    forn(programSerial, DC__programSerial) {
        programViewDuration__programSerial_duration[programSerial] = 0;
    }
        // ------
    int householdCChannelI__serial = 0;
    while (householdCChannel__serial_time[householdCChannelI__serial] == 0) {
        if (channelBefore__serial_channel[householdCChannelI__serial] != -1) {
            channelViews__channel_viewC[channelBefore__serial_channel[householdCChannelI__serial]]--;
        } else {
            channelViews__channel_viewC[channelAfter__serial_channel[householdCChannelI__serial]]++;
        }
        householdCChannelI__serial++;
    }

    for (int time = 1; time < 84600; time++) {
        forn(event, channelCProgram__time_event_channel[time].size()) {
            int channel = channelCProgram__time_event_channel[time][event];
            int program = currentProgram__channel_program[channel];
            int programSerial = CMark__channel_programSerial[channel] + program;
            programViewDuration__programSerial_duration[programSerial] += channelViews__channel_viewC[channel] * D[programSerial];
            currentProgram__channel_program[channel]++;
            // cout << "current time: " << time << ", current program: " << currentProgram__channel_program[channel] << ", current channel: " << channel << ", views: " << channelViews__channel_viewC[channel] << endl;
        }
        while (householdCChannel__serial_time[householdCChannelI__serial] == time) {
            // printf("Current time: %d, previous channel:% d, after channel: %d\n", time, channelBefore__serial_channel[householdCChannelI__serial], channelAfter__serial_channel[householdCChannelI__serial]);
            if (channelBefore__serial_channel[householdCChannelI__serial] != -1) {
                int channel = channelBefore__serial_channel[householdCChannelI__serial];
                int program = currentProgram__channel_program[channel];
                int programSerial = CMark__channel_programSerial[channel] + program;
                programViewDuration__programSerial_duration[programSerial] += time - DSum__programSerial_startTime[programSerial];
                channelViews__channel_viewC[channelBefore__serial_channel[householdCChannelI__serial]]--;
                
            }
            if (channelAfter__serial_channel[householdCChannelI__serial] != -1) {
                int channel = channelAfter__serial_channel[householdCChannelI__serial];
                int program = currentProgram__channel_program[channel];
                int programSerial = CMark__channel_programSerial[channel] + program;
                programViewDuration__programSerial_duration[programSerial] -= time - DSum__programSerial_startTime[programSerial];
                channelViews__channel_viewC[channelAfter__serial_channel[householdCChannelI__serial]]++;
            }
            householdCChannelI__serial++;
        }
    }

    forn(channel, N) {
        int program = C[channel] - 1;
        int programSerial = CMark__channel_programSerial[channel] + program;
        programViewDuration__programSerial_duration[programSerial] += channelViews__channel_viewC[channel] * D[programSerial];
    }

    forn(channel, N) {
        forn(program, C[channel]) {
            int programSerial = CMark__channel_programSerial[channel] + program;
            cout << (double) programViewDuration__programSerial_duration[programSerial] / D[programSerial] << " ";
        }
        cout << endl;
    }

}
