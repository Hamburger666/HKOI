//
//  s174v5.cpp
//  s174v5 - optimized upon v4 - caches optimal solutions for all possible sums (x+y) and scores 100 points
//
//  Created by Haye Chan on 4/12/19.
//  Copyright © 2019 Haye Chan. All rights reserved.
//
#include <iostream>
using namespace std;
#define RANGE 256
#define INF_COST 81 * 80 / 4 * 50 * RANGE

int V[80][80];
int N, A, B, K;
int Best_xyz_to_sum[80][80][RANGE*3+1][3];
int Min_cost_to_sum[80][80][RANGE*3+1];

void read_input() {
    int r, c;
    cin >> N >> A >> B >> K;
    for (r=0; r<N; r++) {
        for (c=0; c<=r; c++) {
            cin >> V[r][c];
        }
    }
}

int dist(int src, int dest) {
    int diff = dest - src;
    if (diff > 0) {
        return diff * A;
    } else {
        return -diff * B;
    }
}

int main() {
    int r0, c0, i, x, y, z, r, c, cost, sum, sum_xy, min_cost, best_sum, n_big_group = 0;
    int r0c0[3240][2];      // stores the list of (r0, c0) at the head of each "big group"
    int best_x_to_sum[RANGE*2+1];
    int min_cost_to_sum_xy[RANGE*2+1];

    read_input();

    // create a list of (r0, c0)'s that denotes each "big group"
    for (r0=0; r0<min(K, N-K); r0++) {
        for (c0=0; c0<=r0; c0++) {
            r0c0[n_big_group][0] = r0;
            r0c0[n_big_group][1] = c0;
            n_big_group++;
        }
    }
    for (r0=K; r0<min(2*K-1, N-K); r0++) {
        for (c0=r0 - K + 1; c0<K; c0++) {
            r0c0[n_big_group][0] = r0;
            r0c0[n_big_group][1] = c0;
            n_big_group++;
        }
    }

    // for each <sum>, find the optimal solution for each "big group" and cache the results
    for (i=0; i<n_big_group; i++) {
        r0 = r0c0[i][0];
        c0 = r0c0[i][1];
        for (sum=3; sum<=RANGE*3; sum++) {
            Min_cost_to_sum[r0][c0][sum] = INF_COST;
        }
        for (sum_xy=2; sum_xy<=RANGE*2; sum_xy++) {
            min_cost_to_sum_xy[sum_xy] = INF_COST;
        }
        // cache the cost-distance to convert the 1/3 of "subgroup" into target x, y or z
        int distance_to_target[RANGE+1][3] = {0};        // cost-distance to move all number in a subgroup into x
        for (r=r0; r<N; r+=K) {
            for (c=c0; c<=r; c+=K) {
                for (x=1; x<=RANGE; x++) {
                    distance_to_target[x][(r/K + c/K) % 3] += dist(V[r][c], x);
                }
            }
        }
        // cache the results for sum of 2 numbers x & y
        for (x=1; x<=RANGE; x++) {
            for (y=1; y<=RANGE; y++) {
                sum_xy = x + y;
                cost = distance_to_target[x][0] + distance_to_target[y][1];
                if (cost < min_cost_to_sum_xy[sum_xy]) {
                    min_cost_to_sum_xy[sum_xy] = cost;
                    best_x_to_sum[sum_xy] = x;
                }
            }
        }

        // cache the results optimal solution for each <sum> from 1..RANGE*3
        for (z=1; z<=RANGE; z++) {
            for (sum_xy=2; sum_xy<=RANGE*2; sum_xy++) {
                sum = z + sum_xy;
                cost = distance_to_target[z][2] + min_cost_to_sum_xy[sum_xy];
                if (cost < Min_cost_to_sum[r0][c0][sum]) {
                    x = best_x_to_sum[sum_xy];
                    y = sum_xy - x;
                    Min_cost_to_sum[r0][c0][sum] = cost;
                    Best_xyz_to_sum[r0][c0][sum][0] = x;
                    Best_xyz_to_sum[r0][c0][sum][1] = y;
                    Best_xyz_to_sum[r0][c0][sum][2] = z;
                }
            }
        }
    }

    // find the sum that minimizes the total cost, i.e., sum of min_cost for each "big group"
    min_cost = INF_COST;
    for (sum=3; sum<=RANGE*3; sum++) {
        cost = 0;
        for (i=0; i<n_big_group; i++) {
            r0 = r0c0[i][0];
            c0 = r0c0[i][1];
            cost += Min_cost_to_sum[r0][c0][sum];
        }
        if (cost < min_cost) {
            min_cost = cost;
            best_sum = sum;
        }
    }
    
    // update the vertices with the best (x, y, z) solution
    for (i=0; i<n_big_group; i++) {
        r0 = r0c0[i][0];
        c0 = r0c0[i][1];
        for (r=r0; r<N; r+=K) {
            for (c=c0; c<=r; c+=K) {
                V[r][c] = Best_xyz_to_sum[r0][c0][best_sum][(r/K + c/K) % 3];
            }
        }
    }

    cout << min_cost << endl;
    for (r=0; r<N; r++) {
        for (c=0; c<=r; c++) {
            cout << V[r][c] << " ";
        }
        cout << endl;
    }
    return 0;
}
