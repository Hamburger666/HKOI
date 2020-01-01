    #include <bits/stdc++.h>
    #define forn(i, n) for (long long i = 0; i < n; i++)
    using namespace std;

    // D is not the same as the D given in the problem. It is like a flattened 
    // 2D array. DMark[channel] is where data for channel starts in D[10000]. 
    // For example, Di,j given in the problem statement would be D[DMark[i] + j]


    long long N, M, L;
    long long C[100000], D[100000], DMark[100000], D_size;
    bool P[100000]; long long Q[100000];
    long long T[100000], H[100000], B[100000];

    // Ds is simliar to D, but rather than storing the duration of the program,
    // it stores the time when the program begins.

    long long Ds[100000];
    vector<long long> channelChange[86401];

    long long programOnChannel[100000] = {0};
    long long channelViewCount[100000] = {0};
    long long programViewTime[100000] = {0};
    bool householdOn[100000];
    long long householdChannel[100000];


    long long getProgramSerial(long long channel, long long program) {
        return DMark[channel] + program;
    }

    void recordChannelChange(long long channelBefore, long long channelAfter, long long time) {
        if (channelBefore != -1) {
            long long program = programOnChannel[channelBefore];
            channelViewCount[channelBefore]--;
            programViewTime[getProgramSerial(channelBefore, program)] += time - Ds[getProgramSerial(channelBefore, program)];
        }
        if (channelAfter != -1) {
            long long program = programOnChannel[channelAfter];
            channelViewCount[channelAfter]++;
            programViewTime[getProgramSerial(channelAfter, program)] -= time - Ds[getProgramSerial(channelAfter, program)];
        }
    }

    int main() {
        /* Pseudocode:
        load data

        sort the time when channels their programs in a array of vectors,
        and pretend that each channels changed its program at t = 86400
        so that the view time for the last program can be counted.
        
        consider the initial states of households and count the viewers

        for time 0 --> 86401:
            for each channel that changed program at the time:
                old program view time += old program duration * channel viewer count
                record that the channel has changed its program
            while the time of the next button press == time:
                if tv in the household is on:
                    if the button is the power button:
                        old program view time += time - old program start time
                        record that the tv turned off
                    else:
                        old program view time += time - old program start time
                        new program view time -= time - new program start time
                        record that the tv switched a channel
                else:
                    if the button is the power button:
                        new program view time += time - new program start time
                        record that the tv turned on
                    else:
                        do nothing
        
        prlong long the result
        */
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
            long long time = 0;
            forn(program, C[channel]) {
                Ds[getProgramSerial(channel, program)] = time;
                time += D[getProgramSerial(channel, program)];
            }
        }

        forn(channel, N) {
            for (long long program = 1; program < C[channel]; program++) {
                channelChange[Ds[getProgramSerial(channel, program)]].push_back(channel);
            }
            channelChange[86400].push_back(channel); // so by the end everything resets
        }

        forn(household, M) {
            householdOn[household] = P[household];
            householdChannel[household] = Q[household];
            if (P[household]) {
                channelViewCount[Q[household]]++;
            }
        }

        long long event = 0;
        forn(time, 86401) {
            forn(i, channelChange[time].size()) {
                long long programBefore = programOnChannel[channelChange[time][i]];
                // printf("channel view count: %d\n", channelViewCount[channelChange[time][i]]);
                programViewTime[getProgramSerial(channelChange[time][i], programBefore)] += channelViewCount[channelChange[time][i]] * D[getProgramSerial(channelChange[time][i], programBefore)];
                programOnChannel[channelChange[time][i]]++;
            }
            while (T[event] == time && event < L) {
                if (householdOn[H[event]]) {
                    if (B[event] == -1) {
                        recordChannelChange(householdChannel[H[event]], -1, time);
                        householdOn[H[event]] = false;
                    } else {
                        recordChannelChange(householdChannel[H[event]], B[event], time);
                        householdChannel[H[event]] = B[event];
                    }
                } else {
                    if (B[event] == -1) {
                        recordChannelChange(-1, householdChannel[H[event]], time);
                        householdOn[H[event]] = true;
                    } // else do nothing
                }
                event++;
            }
        }

        cout << fixed;
        cout << setprecision(30);
        forn(channel, N) {
            forn(program, C[channel]) {
                long long programSerial = getProgramSerial(channel, program);
                double output = (double) programViewTime[programSerial] / D[programSerial];
                cout << output << " ";
            }
            cout << endl;
        }
    }