#include <bits/stdc++.h>
using namespace std;

// Function to create an adjacency list
void cradj(vector<vector<int>> &adj, int b, int i) {
    adj[b].push_back(i);
    adj[i].push_back(b);
}

// Function to display the adjacency list
void display(const vector<vector<int>> &adj) {
    for (int i = 0; i < adj.size(); ++i) {
        cout << "List of vertex " << i << " is: ";
        for (auto j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

// Depth First Search (DFS) function
void dfs(int start, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[start] = true;
    cout << start << " ";

    for (auto i : adj[start]) {
        if (!visited[i]) {
            dfs(i, adj, visited); // Recursive call to DFS
        }
    }
}

int main() {
    int v = 5;
    vector<vector<int>> adj(v);
    vector<vector<int>> edges = {{1, 2}, {1, 0}, {2, 0}, {2, 3}, {2, 4}};
    
    // Build adjacency list
    for (auto &i : edges) {
        cradj(adj, i[0], i[1]);
    }

    // Display adjacency list
    display(adj);

    // Perform DFS
    vector<bool> visited(v, false);
    int start = 1;
    cout << "DFS traversal starting from " << start << ": ";
    dfs(start, adj, visited);

    return 0;
}
