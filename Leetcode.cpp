#include <iostream>
#include <vector>
using namespace std;

int findUParent(int node, vector<int> &parent)
{
    if (parent[node] == node)
        return node;
    return parent[node] = findUParent(parent[node], parent);
}

void UnionByRank(int u, int v, vector<int> &rank, vector<int> &parent)
{
    int Parent_u = findUParent(u, parent);
    int Parent_v = findUParent(v, parent);
    if (rank[u] > rank[v])
    {
        parent[Parent_v] = Parent_u;
    }
    else if (rank[v] > rank[u])
    {
        parent[Parent_u] = Parent_v;
    }
    else
    {
        parent[Parent_v] = Parent_u;
        rank[u]++;
    }
}

vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
{
    vector<int> parent(n, 0);
    vector<int> rank(n, 0);

    vector<bool> ans(n, false);

    for (int i{0}; i < n; i++)
    {
        parent[i] = i;
    }

    for (auto i : queries)
    {
        int u = i[0];
        int v = i[1];
        int diff = nums[u] - nums[v];
        if (diff <= maxDiff)
        {
            UnionByRank(u, v, rank, parent);
        }
    }

    for(auto i:parent)
    {
        cout<<i<<" ";
    }

    return ans;
}

int main()
{
    vector<int> nums={1, 2, 3, 4, 5};
    int maxDiff=2;
    vector<vector<int>> graph={{0,1},{1,2},{2,3},{3,4}};
    pathExistenceQueries(5,nums,maxDiff,graph);
}
