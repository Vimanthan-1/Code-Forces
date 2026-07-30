#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);

    vector<int> indegree(n + 1, 0);
    for (int i{1}; i <= n; i++)
    {
        int num;
        cin >> num;
        adj[i].push_back(num);
        indegree[num]++;
    }

    int org_count = 0;
    for (auto i : adj)
    {
        if (i.size() != 0)
        {
            org_count++;
        }
    }

    queue<int> q;

    for (int i{1}; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topoOrder;

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();

        topoOrder.push_back(node);
        for (auto i : adj[node])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }

    if (topoOrder.size() != org_count)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}