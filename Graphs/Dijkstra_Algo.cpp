#include <bits/stdc++.h>
using namespace std;

// single source shortest path algorithm
// works only on non-negative edge weights
// both directed and undirected graphs
// Time complexity : O(E*logV)

struct _priority {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
        return a.second > b.second;  // comparison in min heap based on distance
    }
};

vector<vector<pair<int, int>>> graph;  // first denotes the destination vertex, second denotes the weight/distance
vector<int> dist;
//vector<bool> visited;
priority_queue<pair<int, int>, vector<pair<int, int>>, _priority> pq;

void dijkstra(int s) {
    dist[s] = 0;
    pq.push(make_pair(s, 0));
    while (!pq.empty()) {
        auto v = pq.top();
        pq.pop();
        //if (visited[v.first]) {
            //continue;
        //}
        //visited[v.first] = true;
        for (int i = 0; i < graph[v.first].size(); i++) {
            auto node = graph[v.first][i];
            if (dist[node.first] > dist[v.first] + node.second) {
                dist[node.first] = dist[v.first] + node.second;
                pq.push(make_pair(node.first, dist[node.first]));
            }
        }
    }
}

int main() {
    int v, e, s, d, w;
    cin >> v >> e;
    graph.resize(v+1);
    dist.assign(v+1, INT_MAX);
    //visited.assign(v+1, false);
    while(e--) {
        cin >> s >> d >> w;
        // undirected
        graph[s].push_back(make_pair(d, w));
        graph[d].push_back(make_pair(s, w));
    }
    cin >> s;
    dijkstra(s);
    for (int i = 1; i <= v; i++) {
        if (dist[i] == INT_MAX) {
            cout << "inf";
        } else {
            cout << dist[i];
        }
        cout << " ";
    }
    return 0;
}
