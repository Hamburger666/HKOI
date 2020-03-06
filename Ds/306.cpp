#include <iostream>
#include <string>
#define forn(i,n) for(long long i = 0; i<n;i++)
typedef long long ll;
using namespace std;

string email;
bool usernameorhost, valid, wasDot, wasDash, hostBeginning, hosthasdot;
int main() {
    cin >> email;
    usernameorhost = true;
    valid = true;
    wasDot = false;
    wasDash = false;
    hosthasdot = false;
    hostBeginning = false;
    if (email[0] == '.') {
        valid = false;
    }
    forn(i, email.length() && valid) {
        char c = email[i];
        if (c == '@') {
            if (usernameorhost) {
                if (wasDot) {
                    valid = false;
                } else {
                    hostBeginning = true;
                    usernameorhost = false;
                }
            } else {
                valid = false;
            }
        } else if (usernameorhost) {
            if (('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '+') {
                wasDot = false;
            } else if (c == '.') {
                if (wasDot) {
                    valid = false;
                } else {
                    wasDot = true;
                }
            } else {
                valid = false;
            }
        } else {
            if (hostBeginning && c == '.') {
                valid = false;
            } else {
                hostBeginning = false;
                if (('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
                    wasDot = false;
                    wasDash = false;
                } else if (c == '.') {
                    hosthasdot = true;
                    if (wasDot || wasDash) {
                        valid = false;
                    } else {
                        wasDot = true;
                        wasDash = false;
                    } 
                } else if (c == '-') {
                    if (wasDot) {
                        valid = false;
                    } else {
                        wasDot = false;
                        wasDash = true;
                    } 
                } else {
                    valid = false;
                }
            }
        }
    }
    // printf("%d %d %d\n", wasDot, hosthasdot, usernameorhost);
    // printf("%d\n", valid);
    if (wasDot || !hosthasdot || usernameorhost) {
        valid = false;
    }
    if (valid) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }

}