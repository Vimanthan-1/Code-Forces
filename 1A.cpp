#include <iostream>
using namespace std;

int main() 
{
    // Use long long to prevent integer overflow
    long long n, m, a;
    cin >> n >> m >> a;

    // Calculate tiles needed for length, rounding up
    long long length_tiles = (n + a - 1) / a;

    // Calculate tiles needed for width, rounding up
    long long width_tiles = (m + a - 1) / a;

    // Total tiles is the product of both
    long long total_tiles = length_tiles * width_tiles;

    cout << total_tiles << endl;

    return 0;
}