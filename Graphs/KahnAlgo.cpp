#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
        vector<vector<int>> graph;
        vector<int> indegree;
    public:
        Graph (int);
        void insert_edge (int, int);
        void topo_sort();
};

Graph :: Graph (int v) {
    graph.resize (v);
    indegree.resize (v);
}

void Graph :: insert_edge (int s, int d) {
    graph[s].push_back (d);
    indegree[d]++;
}

void Graph :: topo_sort () {
    queue<int> q;
    vector<int> topo_sorted;
    for (int i = 0; i < graph.size(); i++) {
        if (indegree[i] == 0)
            q.push (i);
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        topo_sorted.push_back (v);
        for (auto i : graph[v]) {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push (i);
        }
    }
    if (topo_sorted.size() != graph.size())
        cout << "The graph is not a DAG!!";
    else {
        cout << "The topological sort is : ";
        for (auto i : topo_sorted)
            cout << i << " ";
    }
}

int main() {
    int v, e, s, d;
    cin >> v >> e;
    Graph g (v);
    for (int i = 0; i < e; i++) {
        cin >> s >> d;
        g.insert_edge (s, d);
    }
    g.topo_sort();
    return 0;
}
