#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O for Codeforces
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Use n + 1 size because nodes are 1-indexed
    vector<vector<int>> adj(n + 1);

    // Read undirected edges
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Tree is undirected
    }

    vector<int> ans(n);
    vector<int> pos(n + 1); // Stores the index/position of each node in the target sequence

    for (int i = 0; i < n; i++) {
        cin >> ans[i];
        pos[ans[i]] = i; // Node 'ans[i]' appears at index 'i'
    }

    // CRITICAL RULE: BFS must start at node 1
    if (ans[0] != 1) {
        cout << "No\n";
        return 0;
    }

    // Sort neighbors of each node based on their arrival order in 'ans'
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end(), [&](int a, int b) {
            return pos[a] < pos[b];
        });
    }

    // Standard BFS simulation
    vector<int> bfs_order;
    vector<bool> vis(n + 1, false);
    queue<int> q;

    q.push(1);
    vis[1] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        bfs_order.push_back(curr);

        for (int neighbor : adj[curr]) {
            if (!vis[neighbor]) {
                vis[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    // Check if our generated BFS matches the target sequence exactly
    if (bfs_order == ans) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}