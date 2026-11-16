#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Use 1-based indexing for convenience
    // p[i] stores the person that person i points to.
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    // The problem asks us to start the process from EVERY person i
    for (int i = 1; i <= n; i++) {
        vector<bool> vis(n + 1, false);
        int curr = i;
        
        // Traverse until we hit a person we've already visited
        while (!vis[curr]) {
            vis[curr] = true;   // Mark current person as visited
            curr = p[curr];     // Move to the next person
        }
        
        // 'curr' is now the first person visited twice
        cout << curr << " ";
    }
    
    cout << "\n";
    return 0;
}