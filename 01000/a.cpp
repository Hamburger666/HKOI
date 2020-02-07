#include <iostream>
#include <string>
#include <sstream>
#define forn(i, n) for (int i = 0; i < n; i++)
using namespace std;

int N;

int main() {
    cin >> N;
    string raw[N];
    string re[N];
    string processed[N];
    string i;
    getline(cin, i);
    forn(i, N) {
        getline(cin, raw[i]);
    }
    forn(i, N) {
        int firstBegin, firstEnd, secondBegin, secondEnd, thirdBegin, thirdEnd;
        string first, second;
        int at = 0;
        forn (c, raw[i].length()) {
            if (raw[i].at(c) == '"') {
                if (at == 0) {
                    firstBegin = c + 1;
                } else if (at == 1) {
                    firstEnd = c;
                } else if (at == 2) {
                    secondBegin = c + 1;
                } else if (at == 3) {
                    secondEnd = c;
                } else if (at == 4) {
                    thirdBegin = c + 1;
                } else if (at == 5) {
                    thirdEnd = c;
                }
                at++;
            }
        }
        first = raw[i].substr(firstBegin, firstEnd-firstBegin);
        second = raw[i].substr(secondBegin, secondEnd-secondBegin);
        stringstream ss(raw[i].substr(firstEnd + 1, secondBegin - 1-firstEnd));
        string commandword; int pos;
        ss >> commandword;
        if (commandword == "Insert") {
            ss >> pos;
            pos--;
            string s = first.substr(0, pos) + second + first.substr(pos);
            re[i] = s;
        }
        
        if (commandword == "Cut") {
            int pos = first.find(second);
            if (pos == -1) {
                re[i] = first;
            } else {
                re[i] = first.substr(0, pos) + first.substr(pos + second.length());
            }
        }

        if (commandword == "Append") {
            re[i] = first + second;
        }

        if (commandword == "Replace") {
            string third = raw[i].substr(thirdBegin, thirdEnd-thirdBegin);
            int pos = first.find(second);
            re[i] = first.substr(0, pos) + third + first.substr(pos + second.length());
        }

        cout << "Command #" << i + 1 << ": \"" << re[i] << "\"" << endl; 
    }
}