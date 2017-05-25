#include <iostream>
using namespace std;

class Edge;

class Vertex {
    public:
        int info;
        Vertex* next_vertex;
        Edge* start_edge;
        Vertex (int info) {
            this->info = info;
            next_vertex = NULL;
            start_edge = NULL;
        }
};

class Edge {
    public:
        Edge* next_edge;
        Vertex* dest_vertex;
        Edge() {
            next_edge = NULL;
            dest_vertex = NULL;
        }
};

class Graph {
    public:
        Vertex* root;
        Graph() {
            root = NULL;
        }
        void print_graph();
        void insert_vertex (int);
        void insert_edge (int, int);
        void remove_vertex (int);
        void remove_edge (int, int);
        Vertex* search_vertex (int);
        Edge* search_edge (int, int);
};

void Graph :: print_graph() {
    Vertex* v = root;
    while (v != NULL) {
        cout << v->info;
        Edge* e = v->start_edge;
        while (e != NULL) {
            cout << " -> " << e->dest_vertex->info;
            e = e->next_edge;
        }
        cout << "\n";
        v = v->next_vertex;
    }
}

void Graph :: insert_vertex (int vertex) {
    Vertex *v = new Vertex (vertex);
    if (root == NULL)
        root = v;
    else {
        Vertex* curr = root;
        while (curr->next_vertex != NULL) 
            curr = curr->next_vertex;
        curr->next_vertex = v;
    }
}

void Graph :: insert_edge (int source, int destination) {
    Vertex* s = search_vertex (source);
    Vertex* d = search_vertex (destination);
    if (s == NULL) {
        cout << "Source vertex does not exist\n";
        return;
    }
    if (d == NULL) {
        cout << "Destination vertex does not exist\n";
        return;
    }
    Edge* e = new Edge();
    e->dest_vertex = d;
    if (s->start_edge == NULL)
        s->start_edge = e;
    else {
        Edge* curr = s->start_edge;
        while (curr->next_edge != NULL)
            curr = curr->next_edge;
        curr->next_edge = e;
    }
}

void Graph :: remove_vertex (int vertex) {
    if (root == NULL) {
        cout << "Graph is empty, it has no vertices!\n";
        return;
    }
    Vertex* v = root;           // deleting all those edges whose destination vertex is to be deleted
    while (v != NULL) {
        if (v->start_edge == NULL) {
            v = v->next_vertex;
            continue;
        }
        if (v->start_edge->dest_vertex->info == vertex) {
            Edge* e = v->start_edge;
            v->start_edge = v->start_edge->next_edge;
            delete e;
            continue;
        }
        Edge* curr = v->start_edge;
        while (curr->next_edge != NULL) {
            if (curr->next_edge->dest_vertex->info == vertex) {
                Edge *e = curr->next_edge;
                curr->next_edge = curr->next_edge->next_edge;
                delete e;
                continue;
            }
            curr = curr->next_edge;
        }
        v = v->next_vertex;
    }
    Vertex* curr = root;
    if (root->info == vertex)                //  the starting vertex is to be deleted
        root = root->next_vertex;
    else {
        Vertex* del_next = root;
        while (del_next->next_vertex != NULL) {
            if (del_next->next_vertex->info == vertex)
                break;
            del_next = del_next->next_vertex;
        }
        if (del_next->next_vertex == NULL) {
            cout << "Sorry! Vertex not found!\n";
            return;
        }
        curr = del_next->next_vertex;
        del_next->next_vertex = del_next->next_vertex->next_vertex;
    }
    Edge* edge = curr->start_edge;
    while (edge != NULL) {                     // deleting all edges whose source vertex is to be deleted
        Edge* temp = edge;
        edge = edge->next_edge;
        delete temp;
    }
    delete curr;
}

void Graph :: remove_edge (int source, int destination) {
    Vertex* v = search_vertex (source);
    Edge* e = search_edge (source, destination);
    if (e == NULL) {
        cout << "Sorry! Edge not found!\n";
        return;
    }
    if (e == v->start_edge)
        v->start_edge = v->start_edge->next_edge;
    else {
        Edge* prev = v->start_edge;
        while (prev->next_edge != e)
            prev = prev->next_edge;
        prev->next_edge = e->next_edge;
    }
    delete e;
}

Vertex* Graph :: search_vertex (int info) {
    Vertex* curr = root;
    while (curr != NULL) {
        if (curr->info == info)
            break;
        curr = curr->next_vertex;
    }
    return curr;
}

Edge* Graph :: search_edge (int s, int d) {
    Vertex* source = search_vertex (s);
    if (source == NULL)
        return NULL;
    Edge *e = source->start_edge;
    while (e != NULL) {
        if (e->dest_vertex->info == d)
            break;
        e = e->next_edge;
    }
    return e;
}

int main() {
    Graph g;
    cout << "MENU :\n\t1. Print graph\n\t2. Insert vertex\n\t3. Insert egde\n\t4. Delete vertex\n\t5. Delete edge\n\t6. Search vertex\n\t7. Search edge\n\t8. Exit\n";
    while (true) {
        int ch, num1, num2;
        Vertex* v;
        Edge* e;
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch) {
            case 1:
                g.print_graph();
                break;
            case 2:
                cout << "Enter the vertex : ";
                cin >> num1;
                g.insert_vertex (num1);
                break;
            case 3:
                cout << "Enter the source vertex : ";
                cin >> num1;
                cout << "Enter the destination vertex : ";
                cin >> num2;
                g.insert_edge (num1, num2);
                break;
            case 4:
                cout << "Enter the vertex : ";
                cin >> num1;
                g.remove_vertex (num1);
                break;
            case 5:
                cout << "Enter the source vertex : ";
                cin >> num1;
                cout << "Enter the destination vertex : ";
                cin >> num2;
                g.remove_edge (num1, num2);
                break;
            case 6:
                cout << "Enter the vertex : ";
                cin >> num1;
                v = g.search_vertex (num1);
                if (v == NULL)
                    cout << "Sorry! Vertex not found.\n";
                else
                    cout << "Vertex found!\n";
                break;
            case 7:
                cout << "Enter the source vertex : ";
                cin >> num1;
                cout << "Enter the destination vertex : ";
                cin >> num2;
                e = g.search_edge (num1, num2);
                if (e == NULL)
                    cout << "Sorry! Edge not found.\n";
                else
                    cout << "Edge found!\n";
                break;
            case 8:
                return 0;
            default:
                cout << "Wrong choice entered!!\n";
        }
    }
    return 0;
}
