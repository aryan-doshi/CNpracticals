#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

const int INF = INT_MAX;
const int N = 4; // number of routers in the network

// function to initialize the Link State Database for each router
void initialize(int cost[][N], vector<vector<pair<int, int>>>& LSDB) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(cost[i][j] != INF) {
                LSDB[i].push_back(make_pair(j, cost[i][j]));
            }
        }
    }
}

// function to calculate the shortest path for a given router using Dijkstra's algorithm
void dijkstra(int router, vector<vector<pair<int, int>>>& LSDB, vector<int>& dist, vector<int>& prev) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[router] = 0;
    pq.push(make_pair(dist[router], router));
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for(int i=0; i<LSDB[u].size(); i++) {
            int v = LSDB[u][i].first;
            int w = LSDB[u][i].second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

// function to print the shortest path for each router
void print_path(int router, vector<int>& prev, vector<int>& dist) {
    cout << "Shortest path for Router " << router << ":" << endl;
    for(int i=0; i<N; i++) {
        if(i != router) {
            cout << "Router " << i << ": ";
            if(dist[i] == INF) {
                cout << "Not reachable" << endl;
            }
            else {
                vector<int> path;
                int j = i;
                while(j != router) {
                    path.push_back(j);
                    j = prev[j];
                }
                path.push_back(router);
                for(int k=path.size()-1; k>=0; k--) {
                    cout << path[k] << " ";
                }
                cout << "(Cost: " << dist[i] << ")" << endl;
            }
        }
    }
    cout << endl;
}

int main() {
    int cost[N][N] = {{0, 1, INF, 3}, {1, 0, 2, INF}, {INF, 2, 0, 1}, {3, INF, 1, 0}}; // cost matrix
    vector<vector<pair<int, int>>> LSDB(N); // Link State Database
    vector<int> dist(N, INF); // distance vector
    vector<int> prev(N, -1); // previous vector
    
    initialize(cost, LSDB);
    
    for(int i=0; i<N; i++) {
        dijkstra(i, LSDB, dist, prev);
        print_path(i, prev, dist);
        dist.assign(N, INF);
        prev.assign(N, -1);
    }
    
    return 0;
}
