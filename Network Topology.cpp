#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // degree[i] will store the exact number of connections for computer i
    vector<int> degree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }

    // Count the frequency of each degree configuration
    map<int, int> degree_counts;
    for (int i = 1; i <= n; i++) {
        degree_counts[degree[i]]++;
    }

    // --- TOPOLOGY VALIDATION LOGIC ---

    // 1. Star Topology: Exactly one central hub with degree (n - 1), 
    //    and the remaining (n - 1) nodes have a degree of 1.
    if (m == n - 1 && degree_counts[n - 1] == 1 && degree_counts[1] == n - 1) {
        cout << "star topology\n";
    }
    // 2. Bus Topology: Exactly 2 endpoints with degree 1,
    //    and the remaining (n - 2) intermediate nodes have a degree of 2.
    else if (m == n - 1 && degree_counts[1] == 2 && degree_counts[2] == n - 2) {
        cout << "bus topology\n";
    }
    // 3. Ring Topology: Every single node is connected to exactly 2 others.
    else if (m == n && degree_counts[2] == n) {
        cout << "ring topology\n";
    }
    // 4. Any other irregular configuration
    else {
        cout << "unknown topology\n";
    }

    return 0;
}