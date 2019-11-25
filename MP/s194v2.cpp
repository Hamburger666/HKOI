#include <iostream>
using namespace std;

int n, m, k;
int main() {
    cin >> n >> m >> k;
    int snakes[200000][2];
    if (m == 0) {
        int count = n / k;
        if (n % k != 0) {
            count++;
        }
        cout << count << endl;
        return 0;
    }
    for (int i = 0; i < m; i++) {
        cin >> snakes[i][0] >> snakes[i][1];
    }
    int consecutiveSnakeCount = 1;
    int onSquare = 0;
    int totalStep = 0;
    for (int i = 1; i < m; i++) {
        if(snakes[i-1][0] + 1 == snakes[i][0]) {
            consecutiveSnakeCount++;
        } else {
            if (consecutiveSnakeCount >= k) {
                cout << "Lonely Christmas" << endl;
                return 0;
            }
            // ----- Move Self Accordingly ------
            int freeSegmentEnd = snakes[i-1][0] - consecutiveSnakeCount;
            int freelyMoveStep = freeSegmentEnd - onSquare;
            totalStep += freelyMoveStep / k;
            onSquare += freelyMoveStep/k*k;
            if (snakes[i-1][0] >= onSquare + k) {
                onSquare = freeSegmentEnd;
                totalStep++;
            }
            // ---------------------------------
            consecutiveSnakeCount = 1;
        }
    }
    if (consecutiveSnakeCount >= k) {
        cout << "Lonely Christmas" << endl;
        return 0;
    }
    // ----- Move Self Accordingly ------
    int freeSegmentEnd = snakes[m - 1][0] - consecutiveSnakeCount;
    int freelyMoveStep = freeSegmentEnd - onSquare;
    totalStep += freelyMoveStep / k;
    onSquare += freelyMoveStep/k*k;
    if (snakes[m-1][0] >= onSquare + k) {
        onSquare = freeSegmentEnd;
        totalStep++;
    }
    // ---------------------------------
    totalStep += (n - onSquare) / k;
    onSquare += ((n - onSquare) / k * k);
    if (onSquare != n) {
        totalStep++;
    }
    cout << totalStep << endl;
    return 0;
}