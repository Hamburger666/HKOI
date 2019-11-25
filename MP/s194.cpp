// https://judge.hkoi.org/task/s194

#include <iostream>
using namespace std;

int n, m, k;
int main() {
    cin >> n >> m >> k;
    int currentSquare = 0;
    int consecutiveSnakeCount = 1;
    int previousSnakeHead;
    int temp;
    cin >> previousSnakeHead >> temp;
    int totalStep = 0;
    for (int i = 1; i < m; i++) {
        int head, tail;
        cin >> head >> tail;
        if (head - previousSnakeHead == 1) {
            consecutiveSnakeCount++;
            if (consecutiveSnakeCount >= k) {
                cout << "Lonely Christmas" << endl;
                return 0;
            }
        } else {
            int freeSegmentLength = previousSnakeHead - currentSquare - consecutiveSnakeCount;
            int wholePart = freeSegmentLength / k;
            int remainingPart = freeSegmentLength % k;
            int stepAfter;
            totalStep += wholePart;
            if (remainingPart + consecutiveSnakeCount < k) {
                stepAfter = k - remainingPart - consecutiveSnakeCount;
            } else {
                stepAfter = k - consecutiveSnakeCount;
                totalStep++;
            }
            if (previousSnakeHead + stepAfter < head) {
                currentSquare = previousSnakeHead + stepAfter;
            } else {
                currentSquare = head - 1;
            }
            totalStep++;
            consecutiveSnakeCount = 1;
        }
        previousSnakeHead = head;
    }
    int freeSegmentLength = previousSnakeHead - currentSquare - consecutiveSnakeCount;
    int wholePart = freeSegmentLength / k;
    int remainingPart = freeSegmentLength % k;
    int stepAfter;
    totalStep += wholePart;
    if (remainingPart + consecutiveSnakeCount < k) {
        stepAfter = k - remainingPart - consecutiveSnakeCount;
    } else {
        stepAfter = k - consecutiveSnakeCount;
        totalStep++;
    }
    if (previousSnakeHead + stepAfter < n) {
        currentSquare = previousSnakeHead + stepAfter;
        totalStep++;
        totalStep = (n - currentSquare) / k + 1;
    } else {
        totalStep++;
    }
    cout << totalStep << endl;
}