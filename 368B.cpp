#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Fast I/O is highly recommended for problems with 10^5 inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    // Using a boolean vector is much faster than unordered_map for this constraint
    vector<bool> seen(100005, false); 
    
    // Size n+2 prevents out-of-bounds when evaluating dp[i+1] at i=n
    vector<int> dp(n + 2, 0); 

    for(int i = n; i >= 1; i--){
        if(!seen[arr[i]]){
            dp[i] = dp[i + 1] + 1;  // New distinct number found
            seen[arr[i]] = true;    // Mark as seen
        } else {
            dp[i] = dp[i + 1];      // Number already exists, carry over previous count
        }
    }

    for(int i = 0; i < m; i++){
        int query_idx;
        cin >> query_idx;
        // Print exactly what the judge expects, followed by a newline
        cout << dp[query_idx] << "\n";
    }

    return 0;
}