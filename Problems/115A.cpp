#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Global adjacency list and depth array
vector<vector<int>> adj;
vector<int> depth;

// Simple DFS. No 'parent' needed because the graph is strictly directed downwards
void dfs(int u) {
    for (int v : adj[u]) {
        depth[v] = depth[u] + 1; // Child's depth is manager's depth + 1
        dfs(v);
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    adj.resize(n + 1);
    // Base depth is 1 (if a person has no manager, they are the 1st person in their chain)
    depth.assign(n + 1, 1); 
    
    vector<int> roots;

    for (int i = 1; i <= n; i++) {
        int manager;
        cin >> manager;
        
        if (manager == -1) {
            roots.push_back(i); // This person is a top-level boss (a root)
        } else {
            adj[manager].push_back(i); // Directed edge from manager to employee
        }
    }

    // Run DFS from every top-level boss
    for (int root : roots) {
        dfs(root);
    }

    // The answer is the maximum depth found in the entire company
    int min_groups = 0;
    for (int i = 1; i <= n; i++) {
        min_groups = max(min_groups, depth[i]);
    }

    cout << min_groups << "\n";

    return 0;
}