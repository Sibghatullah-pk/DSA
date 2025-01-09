#include <vector>
#include <iostream> // For input/output
using namespace std;

// Function to perform DFS on a single component
void dfs(int node, vector<bool> &visited, 
         vector<vector<int>> &adj, vector<int> &component) {
    component.push_back(node);
    visited[node] = true;

    // Traverse all neighbors of the current node
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adj, component);
        }
    }
}

// Function to perform DFS on the entire graph
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V); // Adjacency list using vector

    // Prepare the adjacency list
    for (const auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    vector<bool> visited(V, false); // Use vector to track visited nodes

    // Traverse all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }

    return ans;
}

// Main function to test the DFS implementation
int main() {
    // Example input: 5 vertices (0 to 4) and 4 edges
    int V = 5, E = 4;
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {3, 4}
    };

    vector<vector<int>> result = depthFirstSearch(V, E, edges);

    // Print the DFS result
    cout << "Connected Components:" << endl;
    for (const auto &component : result) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
