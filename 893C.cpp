#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int BFS(vector<int>& vis,int node,queue<int>& q,vector<vector<int>>& adj,vector<int>& gold){
    int min_gold=gold[node];
    while(!q.empty()){
        auto node=q.front();
        q.pop();

        for(auto i:adj[node]){
            if(!vis[i]){
                vis[i]=1;
                min_gold=min(min_gold,gold[i]);
                q.push(i);
            }
        }
    }

    return min_gold;
}
int main(){
    int n,m;
    cin>>n>>m;

    

    vector<int> gold(n+1,0);
    for(int i{1};i<n+1;i++){
        cin>>gold[i];
    }

    vector<vector<int>> adj(n+1);
    for(int i{0};i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long gold_total=0;
    vector<int> vis(n+1,0);
    queue<int> q;
    

    for(int i{1};i<n+1;i++){
        if(!vis[i] && adj[i].size()!=0){
            q.push(i);
            vis[i]=1;
            gold_total+=BFS(vis,i,q,adj,gold);
        }
    }

    for(int i{1};i<n+1;i++){
        if(!vis[i]){
            gold_total+=gold[i];
        }
    }

    cout<<gold_total<<endl;
    



}