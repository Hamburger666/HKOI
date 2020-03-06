#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

string A, B, As(100, 0), Bs(100, 0);
int main() {
    cin >> A >> B;
    size_t i = 0;
    bool result = false;
    bool greater;
    for (size_t i = 0; i < A.length(); i++) {
        char c = A[i];
        if ('a' <= c && c <= 'z') {
            c += 'A' - 'a';
        }
        As[i] = c;
    }

    for (size_t i = 0; i < B.length(); i++) {
        char c = B[i];
        if ('a' <= c && c <= 'z') {
            c += 'A' - 'a';
        }
        Bs[i] = c;
    }



    while(!result && (As[i] != 0 || Bs[i] != 0)) {
        if (As[i] > Bs[i]) {
            greater = true;
            result = true;
        } else if (As[i] < Bs[i]) {
            greater = false;
            result = true;
        }
        i++;
    }

    if (result) {
        if (greater) {
            cout << "Greater" << endl;
        } else {
            cout << "Smaller" << endl;
        }
    } else {
        cout << "Equal" << endl;
    }


}