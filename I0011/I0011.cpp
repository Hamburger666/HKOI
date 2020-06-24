#include <iostream>
#include <string>
#define forn(i,n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int N;
string S;
ll costT[5001] = {0};
bool protectedTB[5000] = {0};
ll protectedTV[5000] = {0};


int main() {
    cin >> N >> S;
    forn(i, N) {
        forn(ai, N - i){
            if (protectedTB[ai]) {
                protectedTB[ai] = false;
                if (ai > 0 && ai + i < N) {
                    protectedTB[ai-1] = (S[ai - 1] == S[ai+i]);
                    protectedTV[ai-1] = costT[ai];
                }
                costT[ai] = protectedTV[ai];
            } else {
                if (ai > 0 && ai + i < N) {
                    protectedTB[ai-1] = (S[ai - 1] == S[ai+i]);
                    protectedTV[ai-1] = costT[ai];
                }
                if (i) {
                    costT[ai] = 1 + min(costT[ai], costT[ai+1]);
                } else {
                    costT[ai] = 0;
                }
            }
        }
    }
    cout << costT[0] << endl;
}