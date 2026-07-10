#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<string> graph(n);
    for(int i{0};i<n;i++){
        cin>>graph[i];
    }

    int count=0;
    vector<vector<int>> vis(n,vector<int>(m,0));
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    for(int i{0};i<n;i++){
        for(int j{0};j<m;j++){
            if(!vis[i][j] && graph[i][j]=='.'){
                count++;
                queue<pair<int,int>> q;
                vis[i][j]=1;
                q.push({i,j});
                while(!q.empty()){
                    int row=q.front().first;
                    int col=q.front().second;
                    q.pop();
                    for(int k{0};k<4;k++){
                        int nrow=row+drow[k];
                        int ncol=col+dcol[k];
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && graph[nrow][ncol]=='.'){
                            vis[nrow][ncol]=1;
                            q.push({nrow,ncol});
                        }
                    }
                }

            }
        }
    }

    cout<<count<<endl;
}
