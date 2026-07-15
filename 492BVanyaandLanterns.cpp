#include <iostream>
#include <cmath>
#include <iomanip> 
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    double max_dist = 0;

    // distance between consecutive lanterns
    for(int i = 1; i < n; i++) {
        max_dist = max(max_dist, (a[i] - a[i-1]) / 2.0);
    }

    // edges
    max_dist = max(max_dist, (double)a[0]);         // from 0 to first
    max_dist = max(max_dist, (double)(l - a[n-1])); // last to l

    cout << fixed << setprecision(10) << max_dist;
}