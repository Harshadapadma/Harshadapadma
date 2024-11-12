#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void addVertex(vector<list<int>>& adj) {
    adj.push_back(list<int>());
}

void addEdge(vector<list<int>>& adj, int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void removeEdge(vector<list<int>>& adj, int v, int w) {
    adj[v].remove(w);
    adj[w].remove(v);
}

void removeVertex(vector<list<int>>& adj, int V, int vertexToDelete) {
    for (int i = 0; i < V; ++i) {
        adj[i].remove(vertexToDelete);
    }
    adj[vertexToDelete].clear();
}

void displayGraph(const vector<list<int>>& adj) {
    for (int i = 0; i < adj.size(); ++i) {
        cout << "Vertex " << i << ": ";
        auto neighbor = adj[i].begin();
        for (; neighbor != adj[i].end(); ++neighbor) {
            cout << *neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    int V, E, v, w;
    cin >> V;
    vector<list<int>> adj(V);
    cin >> E;

    for (int i = 0; i < E; ++i) {
        cin >> v >> w;
        if (v >= 0 && v < V && w >= 0 && w < V) {
            addEdge(adj, v, w);
            cout << "Edge (" << v << ", " << w << ") added successfully!" << endl;
        } else {
            cout << "Invalid vertices! Please enter vertices between 0 and " << V - 1 << endl;
        }
    }

    displayGraph(adj);
    addVertex(adj);
    displayGraph(adj);

    cin >> v >> w;
    if (v >= 0 && v < V && w >= 0 && w < V) {
        addEdge(adj, 5, w);
        cout << "Edge (5, " << w << ") added successfully!" << endl;
    }

    cin >> v >> w;
    if (v >= 0 && v < V && w >= 0 && w < V) {
        removeEdge(adj, v, w);
        cout << "Edge (" << v << ", " << w << ") removed successfully!" << endl;
    }

    cin >> v;
    if (v >= 0 && v < V) {
        removeVertex(adj, V, v);
        V--;
        cout << "Vertex " << v << " and its edges removed successfully!" << endl;
    } else {
        cout << "Invalid vertex!" << endl;
    }

    displayGraph(adj);
    return 0;
}
