#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> q;
    vector<int> vis(200000, 0);
    q.push({n, 0});
    vis[n] = 1;
    while (!q.empty())
    {
        auto [node, step] = q.front();
        q.pop();

        if (node == m)
        {
            cout << step;
            break;
        }

        
        int blue = node * 2;
        if (blue < 200000 && !vis[blue])
        {
            q.push({blue, step + 1});
            vis[blue] = true;
        }
        int red = node - 1;
        if (red > 0 && !vis[red])
        {
            q.push({red, step + 1});
            vis[red] = true;
        }
    }
    return 0;
}