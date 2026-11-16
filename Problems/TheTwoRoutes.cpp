#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> road(n + 1);
    vector<vector<bool>> hasrail(n + 1, vector<bool>(n + 1, false));
    for (int i{0}; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        hasrail[u][v] = true;
        hasrail[v][u] = true;
    }

    for (int i{1}; i <= n; i++)
    {
        for (int j{1}; j <= n; j++)
        {
            if (!hasrail[i][j] && i!=j)
            {
                road[i].push_back(j);
            }
        }
    }

    vector<int> dist(n + 1, 1e9);

    int tot = 0;
    queue<int> q;
    q.push(1);
    dist[1]=0;

    if (hasrail[1][n])
    {
        tot = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            if (node == n)
            {
                tot = dist[n];
                break;
            }

            for (auto i : road[node])
            {
                if (dist[node] + 1 < dist[i])
                {
                    dist[i] = dist[node] + 1;
                    q.push(i);
                }
            }
        }
    }
    else
    {
        tot = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            if (node == n)
            {
                tot = dist[n];
                break;
            }

            for (auto i : adj[node])
            {
                if (dist[node] + 1 < dist[i])
                {
                    dist[i] = dist[node] + 1;
                    q.push(i);
                }
            }
        }
    }

    if(dist[n]!=1e9) cout << tot;
    else cout<<-1;

    return 0;
}