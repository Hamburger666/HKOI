#include <iostream>
using namespace std;

long N;
long rockIndexes[200001];
long steps;
long birdX;
long birdY;
bool birdDirection;
const bool right_ = true;
const bool left_ = false;

void load() {
    cin >> N;
    for (long i = 0; i < N; i++) {
        long h;
        cin >> h;
        rockIndexes[h] = i;
    }
}

void printLoad() {
    for (long i = 0; i <= N; i++) {
        cout << rockIndexes[i] << " ";
    }
    cout << endl;
}

int main() {
    load();
    if (N == 1) {
        cout << "DROP" << endl;
        cout << 2 << endl;
        cout << 2 << endl;
    } else if (rockIndexes[N] < rockIndexes[N-1]) {
        // meaning it will just return
        cout << "ESCAPE" << endl;
        cout << N - 1 << endl;
        cout << (rockIndexes[N] * 3 + 2) * 2 << endl;
    } else {
        steps += rockIndexes[N] * 3 + 2;
        birdDirection = left_;
        long rightRockIndex = rockIndexes[N];
        long leftRockIndex = 0;
        for (long r = N-2; r >= 0; r--) {
            if (birdDirection == right_) {
                if (rockIndexes[r+1] > leftRockIndex && rockIndexes[r+1] < rightRockIndex) {
                    rightRockIndex = rockIndexes[r+1];
                }
                birdDirection = left_;
            } else {
                if (rockIndexes[r+1] > leftRockIndex && rockIndexes[r+1] < rightRockIndex) {
                    leftRockIndex = rockIndexes[r+1];
                }
                birdDirection = right_;
            }
            steps += (rightRockIndex - leftRockIndex) * 3 - 1;
        }
        long finalX;
        if (birdDirection == right_) {
            finalX = leftRockIndex * 3 + 3;
        } else {
            finalX = rightRockIndex * 3 + 1;
        }
        cout << "DROP" << endl;
        cout << finalX + 1 << endl;
        cout << steps << endl;
    }
    return 0;
}