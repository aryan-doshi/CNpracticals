#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

const int INF = INT_MAX;
const int N = 4; // number of routers in the network

// function to initialize the routing table for each router
void initialize(int cost[][N], int next_hop[][N], vector<vector<int>>& dist) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i == j) {
                dist[i][j] = 0;
                next_hop[i][j] = i;
            }
            else if(cost[i][j] != INF) {
                dist[i][j] = cost[i][j];
                next_hop[i][j] = j;
            }
            else {
                dist[i][j] = INF;
                next_hop[i][j] = -1;
            }
        }
    }
}

// function to update the routing table for a given router
void update(int cost[][N], int next_hop[][N], vector<vector<int>>& dist, int router) {
    for(int k=0; k<N; k++) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(dist[i][k] != INF && dist[k][j] != INF && dist[i][k]+dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next_hop[i][j] = next_hop[i][k];
                }
            }
        }
    }
}

// function to print the routing table for each router
void print_table(int next_hop[][N], vector<vector<int>>& dist) {
    for(int i=0; i<N; i++) {
        cout << "Routing table for Router " << i << ":" << endl;
        cout << "Destination\tCost\tNext Hop" << endl;
        for(int j=0; j<N; j++) {
            if(i != j) {
                cout << j << "\t\t" << dist[i][j] << "\t" << next_hop[i][j] << endl;
            }
        }
        cout << endl;
    }
}

int main() {
    int cost[N][N] = {{0, 1, INF, 3}, {1, 0, 2, INF}, {INF, 2, 0, 1}, {3, INF, 1, 0}}; // cost matrix
    int next_hop[N][N]; // next hop matrix
    vector<vector<int>> dist(N, vector<int>(N)); // distance matrix
    
    initialize(cost, next_hop, dist);
    
    cout << "Initial routing tables:" << endl;
    print_table(next_hop, dist);
    
    for(int i=0; i<N; i++) {
        update(cost, next_hop, dist, i);
        cout << "Routing tables after update " << i+1 << ":" << endl;
        print_table(next_hop, dist);
    }
    
    return 0;
}
