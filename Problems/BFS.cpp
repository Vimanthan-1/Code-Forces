#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> parent(n+1);
    for(int i{0};i<m;i++){
        int u,v;
        cin>>u>>v;
        parent[u].push_back(v);
        parent[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    vector<int> vis(n+1,0);
    vis[1]=1;
    for(auto i:vis){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Starting traversal: "<<endl;
    while(!q.empty()){
        auto node=q.front();
        q.pop();

        cout<<node<<endl;
        for(auto i:parent[node]){
            if(!vis[i]){
                q.push(i);
                vis[i]=1;
                for(auto j:vis){
                    cout<<j<<" ";
                }

                cout<<endl;
            }
        }
    }

}