#include <iostream>
#include <vector>
using namespace std;
int findUParent(vector<int> &parent, int node)
{
    if (node == parent[node])
        return node;
    return parent[node] = findUParent(parent, parent[node]);
}

void Connect(int x, int y, vector<int> &parent, vector<int> &rank)
{
    int ux = findUParent(parent, x);
    int uy = findUParent(parent, y);
    if (rank[ux] > rank[uy])
    {
        parent[uy] = ux;
    }
    else if (parent[uy] > parent[ux])
    {
        parent[ux] = uy;
    }
    else
    {
        parent[uy] = ux;
        rank[ux]++;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> parent(n + 1, 0);
    vector<int> rank(n + 1, 0);
    for (int i{1}; i < n + 1; i++)
    {
        parent[i] = i;
    }

    vector<int> x(n + 1, 0);
    vector<int> y(n + 1, 0);
    for (int i{1}; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }

    for (int i{1}; i <= n; i++)
    {
        for (int j{i + 1}; j <= n; j++)
        {
            if (x[i] == x[j] || y[i] == y[j])
            {
                Connect(i, j, parent, rank);
            }
        }
    }

    int components = 0;
    for (int i = 1; i <= n; i++)
    {
        if (findUParent(parent,i) == i)
        {
            components++;
        }
    }

    cout << components - 1 << "\n";
}