#include <map>
#include <vector>
#include <iostream> // For input/output

using namespace std;

// Function to perform DFS on a single component
void dfs(int node, map<int, bool> &visited,
         map<int, vector<int>> &adj, vector<int> &component)
{
    component.push_back(node);
    visited[node] = true;

    // Traverse all neighbors of the current node using iterators
    for (map<int, vector<int>>::iterator it = adj.find(node); it != adj.end(); ++it)
    {
        for (vector<int>::iterator neighbor = it->second.begin(); neighbor != it->second.end(); ++neighbor)
        {
            if (!visited[*neighbor])
            {
                dfs(*neighbor, visited, adj, component);
            }
        }
    }
}

// Function to perform DFS on the entire graph
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    map<int, vector<int>> adj; // Adjacency list using map

    // Prepare the adjacency list
    for (vector<vector<int>>::iterator it = edges.begin(); it != edges.end(); ++it)
    {
        int u = (*it)[0];
        int v = (*it)[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    map<int, bool> visited; // Use map to track visited nodes

    // Traverse all components
    for (int i = 0; i < V; i++)
    {
        if (visited.find(i) == visited.end() || !visited[i])
        {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }

    return ans;
}

// Main function to test the DFS implementation
int main()
{
    // Example input: 5 vertices (0 to 4) and 4 edges
    int V = 5, E = 4;
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {3, 4}};

    vector<vector<int>> result = depthFirstSearch(V, E, edges);

    // Print the DFS result
    cout << "Connected Components:" << endl;
    for (vector<vector<int>>::iterator it = result.begin(); it != result.end(); ++it)
    {
        for (vector<int>::iterator node = it->begin(); node != it->end(); ++node)
        {
            cout << *node << " ";
        }
        cout << endl;
    }

    return 0;
}
