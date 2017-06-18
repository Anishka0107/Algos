#include <bits/stdc++.h>
using namespace std;

struct node {
    int dv;    // destination vertex
    int wt;   // weight of edge
};

class Graph {
        vector<vector<node>> adjlst;
        vector<bool> visited;
        stack<int> topological_sort ();
        void topo_helper (stack<int> &, int);
    public:
        Graph (int);
        void insert_edge (int, int, int);
        void shortest_path (int);
};

Graph :: Graph (int v) {
    adjlst.resize (v);
    visited.resize (v);
}

void Graph :: insert_edge (int s, int d, int weight) {
    node n;
    n.dv = d;
    n.wt = weight;
    adjlst[s].push_back (n);
}

void Graph :: shortest_path (int s) {
    stack<int> st = topological_sort();
    vector<int> distance (adjlst.size(), INT_MAX);
    distance[s] = 0;
    while (!st.empty()) {
        int v = st.top();
        st.pop();
        if (distance[v] != INT_MAX) {
            for (auto i : adjlst[v])
                if (distance[i.dv] > distance[v] + i.wt)
                    distance[i.dv] = distance[v] + i.wt;
        }
    }
    for (int i = 0; i < adjlst.size(); i++)
        if (distance[i] != INT_MAX)
            cout << distance[i] << " ";
        else
            cout << "Infinite ";
}

stack<int> Graph :: topological_sort () {
    stack<int> st;
    for (int i = 0; i < adjlst.size(); i++)
        if (!visited[i])
            topo_helper (st, i);
    return st;
}

void Graph :: topo_helper (stack<int> & st, int v) {
    visited[v] = true;
    for (auto i : adjlst[v])
        if (!visited[i.dv])
            topo_helper (st, i.dv);
    st.push (v);
}

int main() {
    int v, e, s, d, wt;
    // Enter number of vertices
    // Enter number of edges
    // Enter the edges in form of source, destination and weight for the directed graph
    // Enter the source vertex
    cin >> v >> e;
    Graph g (v);
    for (int i = 0; i < e; i++) {
        cin >> s >> d >> wt;
        g.insert_edge (s, d, wt);
    }
    cin >> s;   // source vertex
    // Prints the shortest paths in the DAG from the source vertex
    g.shortest_path (s);
    return 0;
}
